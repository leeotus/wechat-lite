#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define NAME_LEN 16

#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

typedef struct {
    size_t id;
    char name[NAME_LEN];
}TestStruct;

int main(int argc, char **agrv)
{
    int size = size_of_attribute(TestStruct, id);
    return 0;
}
