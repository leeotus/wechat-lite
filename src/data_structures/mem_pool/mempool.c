#include "mem_pool/mempool.h"

#include <stdlib.h>
#include <unistd.h>

/**
 * @brief 创建第一个内存池
 * @param size 内存池中元素的大小
 * @return mem_pool* 内存池创建成功则返回指针,否则返回NULL
 * @note 如果出现错误,比如内存不够分配导致分配到NULL的情况,这里不做判断.
 */
mem_pool* create_mem_pool(ssize_t size)
{
    mem_pool *mp = (mem_pool *)malloc(sizeof(mem_pool));
    if(mp == NULL)
        return NULL;

    // 如果当前的内存池不够使用了,就再开辟下一个内存池,
    // 即mp->mpool[1] = malloc(size * INITIAL_MEMSIZE * GROUWTH_FACTOR);
    mp->cur_chunk_num = 0;
    mp->mpool[mp->cur_chunk_num] = malloc(size * INITIAL_MEMSIZE); 

    if(mp->mpool[mp->cur_chunk_num] == NULL)
    {
        free(mp);
        return NULL;
    }
    mp->size_of_data = size;
    mp->cur_chunk_size = INITIAL_MEMSIZE;
    mp->cur_chunk_cursor = 0;

    mp->avail = NULL;

    return mp;
}

/**
 * @brief 查看空闲链表中是否有空闲的节点可以被使用
 * @param mp 内存池对象
 * @return 如果空闲链表中有空闲节点的话就返回true,否则返回false
 */
inline bool is_freelinker_available(mem_pool *mp)
{
    return (mp->avail != NULL) ? true : false;
}

/**
 * @brief 为内存池分配下一块内存块
 * @param mp 指向内存池的指针
 * @note 无需自己调用,只有在当前内存池不够空间的时候才会在alloc_from_mempool函数里自行调用
 * @warning 如果内存池里的chunks数目超过MEMPOOL_CHUNKS那么不可避免的会发生内存错误
 * TODO: 当chunks数目超过MEMPOOL_CHUNKS之后需要realloc内存给内存池使用?
 */
void realloc_next_chunk(mem_pool *mp)
{
    mp->cur_chunk_num += 1;
    ssize_t realloc_size = INITIAL_MEMSIZE * GROWTH_FACTOR;
    mp->mpool[mp->cur_chunk_num] = malloc(mp->size_of_data * realloc_size);
    mp->cur_chunk_cursor = 0;
    mp->cur_chunk_size = realloc_size;
}

/**
 * @brief 从内存池中申请内存空间
 * @param mp 
 * @return void* 
 * @note 如果内存池不够使用则会重新向内核申请一块内存块,同样交由该mem_pool管理
 */
void *alloc_from_mempool(mem_pool *mp)
{
    void *res;
    // 检测单链空闲链表中是否有空闲空间可以拿出来给使用
    if(is_freelinker_available(mp))
    {
        res = mp->avail->node;
        mp->avail = mp->avail->next;
        return res;
    }
    // 如果空闲链表中没有空闲节点空间可供使用,那么从内存池中取出
    if(mp->cur_chunk_cursor >= mp->cur_chunk_size)
    {
        // 说明当前内存池已经没有空闲内存可以使用了
        realloc_next_chunk(mp);   
    }
    res = (char *)mp->mpool[mp->cur_chunk_num] + mp->cur_chunk_cursor * mp->size_of_data;
    mp->cur_chunk_cursor += 1;
    return res;
}

/**
 * @brief 回收内存,并保存在单链空闲表中
 * @param mp 内存池对象指针
 * @param ptr 要回收内存的对象指针 
 */
void recyle_mem_avail(mem_pool *mp, void **ptr)
{
    if(mp->avail == NULL)
    {
        // TODO: 如果反复地申请和释放内存放回到avail空闲单链表,那么就会导致经常需要向系统内核申请内存空间,因此这里需要进行优化
        mp->avail = (free_linker *)malloc(sizeof(free_linker));
        mp->avail->next = NULL;
        mp->avail->node = *ptr;
        *ptr = NULL;
        return;
    }
    free_linker *tmp = (free_linker *)malloc(sizeof(free_linker));
    tmp->node = *ptr;
    tmp->next = mp->avail->next;
    mp->avail->next = tmp;
    *ptr = NULL;
}

/**
 * @brief 垃圾回收
 * @param mp 内存池对象指针
 * @note TODO: 当前还没想好该怎么做
 */
void garbage_collect(mem_pool *mp)
{
    ssize_t cur_free_nodes;
    free_linker *tmp = mp->avail;
    while (tmp != NULL)
    {
        // 获取当前内存池里有多少内存空间是没有被使用的
        cur_free_nodes += 1;
        tmp = tmp->next;
    }

}

/**
 * @brief 释放所有申请的内存空间然后销毁内存池指针
 * @param mp 
 * @warning 请在调用该函数销毁内存池之前确保没有指针指向内存池内的内存地址
 */
void destroy_mempool(mem_pool **mp)
{
    for(int i=0;i<=(*mp)->cur_chunk_num;++i)
    {
        free((*mp)->mpool[i]);
    }

    while ((*mp)->avail != NULL) {
        free_linker* tmp = (*mp)->avail->next;
        free((*mp)->avail);
        (*mp)->avail = tmp;
    }
    free(*mp);
    *mp = NULL;
}