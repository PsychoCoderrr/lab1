#ifndef FIELD_INFO_H
#define FIELD_INFO_H

typedef void (*SumVector)(void *result, void *a, void *b); /*(переименовать)*/

typedef void (*PrintVector)(void *elem);

typedef void (*MultiVector)(void *result, void *a, void *b);

typedef struct FieldInfo
{
    int elemSize;
    SumVector SumElements;
    MultiVector MultiElements;
    PrintVector PrintElements;
} FieldInfo;

#endif
