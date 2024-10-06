#include "io/pager.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/**
 * @brief 创建一个pager指针并返回,此Pager类保存着打开的数据库文件描述符
 * @param filename 要打开的数据库文件名
 * @return Pager* 返回的Pager指针
 */
Pager* pager_open(const char *filename)
{
    uint32_t i;
    int fd = open(
        filename,
        O_RDWR | O_CREAT,
        S_IWUSR| S_IRUSR
    );
    if(fd == -1)
    {
        printf("Unable to open file %s\r\n", filename);
        exit(EXIT_FAILURE);
    }

    /**
     * @brief lseek 函数用于在文件中移动文件指针
     * @param fd 文件描述符
     * @param offet 偏移量,表示要移动到哪个位置
     * @param whence 表示从哪个位置开始移动.
     * @return 成功完成后，将返回从文件开头算起的以字节为单位的结果偏移量
     * @note whence可以是 SEEK_SET(文件开头),SEEK_CUR(当前位置)或SEEK_END(文件末尾)
     * 此处 off_t file_len = lseek(fd, 0, SEEK_END);表示从文件尾移动到文件头(offset=0)
     * 因此,返回的结果即表示该文件的长度
     */
    off_t file_len = lseek(fd, 0, SEEK_END);

    Pager *pager = (Pager*)malloc(sizeof(Pager));
    if(pager == NULL)
    {
        printf("Out of memory in creating Pager");
        exit(EXIT_FAILURE);
    }
    pager->file_descriptor = fd;
    pager->file_length = file_len;
    for(i=0;i<TABLE_MAX_PAGES;++i)
    {
        pager->pages[i] = NULL;
    }
    return pager;
}

/**
 * @brief Get the page object
 * The get_page() method has the logic for handling a cache miss
 * @param pager 保存数据库文件描述符的page类指针,该类还保存了数据库文件的大小
 * @param page_num 要访问的第几页数据库
 * @return void* 返回指向第page_num页面的指针,或从数据库中调出,或从内存获取新的空间.
 */
void *get_page(Pager* pager, uint32_t page_num)
{
    if(page_num > TABLE_MAX_PAGES)
    {
        printf("Tried to fetch page number out of bounds.\r\n");
        exit(EXIT_FAILURE);
    }
    if(pager->pages[page_num] == NULL)
    {
        // 如果我们发现指定的页面没有在写入内存:
        void *page = (void *)malloc(PAGE_SIZE);     // 每一个页面大小是PAGE_SIZE
        // 接下来要查看数据库文件里已经有多少页面是之前保存在里面的:
        uint32_t num_pages = pager->file_length / PAGE_SIZE;
        if(num_pages % PAGE_SIZE)
            num_pages += 1;     // 别忘记了多余出来不足一页面的也得算进去
        
        // 如果我们要访问的page_num此前已经被写入过数据库文件了:
        if(page_num <= num_pages)
        {
            lseek(pager->file_descriptor, page_num*PAGE_SIZE, SEEK_SET);
            // 读取数据库文件内的数据
            ssize_t bytes_read = read(pager->file_descriptor, page, PAGE_SIZE);
            if(bytes_read == -1)
            {
                printf("Error reading file.\r\n");
                exit(EXIT_FAILURE);
            }
        }
        // 不管最后是否会从数据库中获取页面,我们都要执行的一步:
        pager->pages[page_num] = page;
    }
    return pager->pages[page_num];
}

/**
 * @brief 将pager->pages[page_num]这个页面的写入数据库文件中,
 * 要写入的这个页面的大小为size,因为存在页面可能没有全部被写完的情况,所以使用size
 * 参数来指定要写多少字节的数据回数据库文件中
 * @param pager 
 * @param page_num 
 * @param size 
 * @note 因为有些页面没有被全部写满，所以1如果不采用size，而是直接用PAGE_SIZE作为写入的大小,
 * 那么在重新从数据库文件写回数据到Pager的时候就会导致多出很多Row行数据是空的!!!
 */
void pager_flush(Pager *pager, uint32_t page_num, uint32_t size)
{
    if(pager->pages[page_num] == NULL)
    {
        printf("Tried to flush null page!\r\n");
        exit(EXIT_FAILURE);
    }
    // 找到数据库文件中要存储第page_num的位置
    off_t offset = lseek(pager->file_descriptor, page_num * PAGE_SIZE, SEEK_SET);
    if(offset == -1)
    {
        printf("Error seeking %d.\r\n", errno);
        exit(EXIT_FAILURE);
    }
    ssize_t bytes_written = write(pager->file_descriptor, pager->pages[page_num], size);
    if(bytes_written == -1)
    {
        printf("Error writing: %d\r\n", errno);
        exit(EXIT_FAILURE);
    }
}
