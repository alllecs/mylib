#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _TNode
{
    char* pstr;
    unsigned count;
    struct _TNode* next;
}   TNode;

TNode* Push(TNode** list, const char* pstr)
{
    TNode* node = *list;
    TNode* prenode = NULL;

    for (; node && strcmp(node->pstr, pstr); node = node->next)
    {
        prenode = node;
    }

    if (node)
    {
        node->count++;
    }
    else
    {
        node = malloc(sizeof(TNode));
        node->pstr = malloc(strlen(pstr) + 1);
        strcpy(node->pstr, pstr);
        node->count = 1;
        node->next = NULL;

        if (prenode)
        {
            prenode->next = node;
        }
        else
        {
            *list = node;
        }
    }

    return *list;
}
void Print(TNode* list)
{
    for (; list; list = list->next)
    {
        printf("%3u %s\n", list->count, list->pstr);
    }
}

int main()
{
    TNode* list = NULL;

    char buff[64] = {0};

    while ((scanf("%63s", buff) == 1) && strcmp(buff, "exit"))
    {
        Push(&list, buff);
    }

    Print(list);

    return 0;
}
