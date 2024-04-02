#ifndef COMPLEX_H
#define COMPLEX_H
#include "FieldInfo.h"

typedef struct
{
    int Real;
    int Im;
} Complex;

void complexSum(void *res, void *a, void *b);

void complexMulti(void *res, void *a, void *b);

void complexPrint(void *elem);

FieldInfo *CreateComplexFieldInfo();
#endif
