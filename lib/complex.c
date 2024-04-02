#include <stdio.h>
#include <stdlib.h>
#include "complex_lib.h"
#include "complex.h"

void complexSum(void *res, void *a, void *b)
{
    ((Complex *)res)->Real = ((Complex *)a)->Real + ((Complex *)b)->Real;
    ((Complex *)res)->Im = ((Complex *)a)->Im + ((Complex *)b)->Im;
}

void complexMulti(void *res, void *a, void *b)
{
    ((Complex *)res)->Real = ((Complex *)a)->Real * ((Complex *)b)->Real - ((Complex *)a)->Im * ((Complex *)b)->Im;
    ((Complex *)res)->Im = ((Complex *)a)->Real * ((Complex *)b)->Im + ((Complex *)b)->Real * ((Complex *)a)->Im;
}
void complexPrint(void *elem)
{
    printf("%d + %di ", ((Complex *)elem)->Real, ((Complex *)elem)->Im);
}

FieldInfo *CreateComplexFieldInfo()
{
    FieldInfo *COMPLEX_FIELD_INFO = NULL; /*(вернуться к static)*/
    COMPLEX_FIELD_INFO = (FieldInfo *)malloc(sizeof(FieldInfo));
    if (COMPLEX_FIELD_INFO == NULL)
    {
        return NULL;
    }
    COMPLEX_FIELD_INFO->elemSize = sizeof(Complex);
    COMPLEX_FIELD_INFO->SumElements = &complexSum;
    COMPLEX_FIELD_INFO->MultiElements = &complexMulti;
    COMPLEX_FIELD_INFO->PrintElements = &complexPrint;
    return COMPLEX_FIELD_INFO;
}
