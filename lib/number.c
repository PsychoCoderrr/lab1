#include "number.h"
#include "number_lib.h"
#include <stdio.h>
#include <stdlib.h>
void numberSum(void *res, void *a, void *b)
{
    *(int *)res = *(int *)a + *(int *)b;
}

void numberMulti(void *res, void *a, void *b)
{
    *(int *)res = *(int *)a * *(int *)b;
}

void numberPrint(void *elem)
{
    printf("%d ", *(int *)elem);
}

FieldInfo *CreateIntFieldInfo()
{
    FieldInfo *INT_FIELD_INFO = NULL;
    INT_FIELD_INFO = (FieldInfo *)malloc(sizeof(FieldInfo));
    if (INT_FIELD_INFO == NULL)
    {
        return NULL;
    }
    INT_FIELD_INFO->elemSize = sizeof(int);
    INT_FIELD_INFO->SumElements = &numberSum;
    INT_FIELD_INFO->MultiElements = &numberMulti;
    INT_FIELD_INFO->PrintElements = &numberPrint;
    return INT_FIELD_INFO;
}
