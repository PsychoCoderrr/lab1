#ifndef COMPLEX_H
#define COMPLEX_H
#include "FieldInfo.h"

typedef struct
{
    int Real;
    int Im;
} Complex;

FieldInfo *CreateComplexFieldInfo();
#endif
