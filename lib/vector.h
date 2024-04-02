#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h> /* для введения NULL */
#include "FieldInfo.h"
/* заголовочный файл, реализующий интерфейс для работы с векторами*/

typedef struct _vector{
    int size;
    void* elements;
    FieldInfo* typeInfo;
} Vector;

typedef struct _namedVector{
    char name[20];  //через readline
    Vector* vector;
}NamedVector;

typedef struct _vectorCollection{
    NamedVector* vectors;
    int size;
}VectorCollection;

Vector* vectorInit(FieldInfo* typeInfo);

void vectorAddElement(Vector* v, void* elem, FieldInfo* elemType);

void vectorFree(Vector* v);

void vectorSum(Vector** res, Vector* v1, Vector* v2);

void vectorMulti(Vector** res, Vector* v1, Vector* v2);

void vectorPrint(Vector *v);

void vectorAddToCollection(VectorCollection *collection, char *name, FieldInfo* VectorInfo);

Vector* vectorFindInCollection(VectorCollection *collection, char *name);
#endif
