#ifndef VECTOR_H
#define VECTOR_H

#include "FieldInfo.h"
#include <stddef.h> /* для введения NULL */
/* заголовочный файл, реализующий интерфейс для работы с векторами*/

typedef struct _vector
{
    int size;
    void *elements;
    FieldInfo *typeInfo;
} Vector;

typedef struct _namedVector
{
    char* name;
    Vector *vector;
} NamedVector;

typedef struct _vectorCollection
{
    NamedVector *vectors;
    int size;
} VectorCollection;

Vector *vectorInit(FieldInfo *typeInfo);

void vectorAddElement(Vector *v, void *elem, FieldInfo *elemType);

void vectorFree(Vector *v);

void vectorSum(Vector *res, const Vector *v1, const Vector *v2);

void vectorMulti(Vector *res, const Vector *v1, const Vector *v2);

void vectorPrint(Vector *v);

void vectorAddToCollection(VectorCollection *collection, char *name, FieldInfo *VectorInfo);

Vector *vectorFindInCollection(VectorCollection *collection, char *name);
#endif
