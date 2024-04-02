#include "vector.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector *vectorInit(FieldInfo *typeInfo)
{
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    if (vector == NULL)
    {
        return NULL;
    }
    vector->typeInfo = typeInfo;
    vector->elements = NULL;
    vector->size = 0;
    return vector;
}

int vectorAddElement(Vector *v, void *elem, FieldInfo *elemType)
{
    if (v->typeInfo == elemType)
    {
        v->elements = realloc(v->elements, (v->size + 1) * v->typeInfo->elemSize);
        memcpy((char *)v->elements + v->size * v->typeInfo->elemSize, elem, v->typeInfo->elemSize);
        v->size = v->size + 1;
        return OK;
    }
    else
    {
        fprintf(stderr, "Ошибка несоответствия типов");
        return BAD_TYPE;
    }
}

void vectorFree(Vector *v)
{
    free(v->elements);
    v->size = 0;
    v->typeInfo = NULL;
    free(v);
}

int vectorSum(Vector *res, const Vector *v1, const Vector *v2)
{
    if (v1->size == v2->size && v1->typeInfo == v2->typeInfo)
    {
        int vSize = v1->typeInfo->elemSize;
        void *intermediateResult = malloc(vSize);
        if (intermediateResult == NULL)
        {
            fprintf(stderr, "Ошибка выделения памяти");
            return BAD_MEMORY;
        }
        for (int elemNumber = 0; elemNumber < v1->size; elemNumber++)
        {
            void *elem1 = v1->elements + elemNumber * vSize;
            void *elem2 = v2->elements + elemNumber * vSize;

            v1->typeInfo->SumElements(intermediateResult, elem1, elem2);

            vectorAddElement(res, intermediateResult, v1->typeInfo);
        }
        free(intermediateResult);
    }
    else if (v1->size != v2->size)
    {
        fprintf(stderr, "Ошибка несоотвеетсвия размеров векторов");
        return BAD_SIZE;
    }
    else if (v1->typeInfo != v2->typeInfo)
    {
        fprintf(stderr, "Ошибка несоотвеетсвия типов вектора");
        return BAD_TYPE;
    }
    return OK;
}

int vectorMulti(Vector *res, const Vector *v1, const Vector *v2)
{
    if (v1->size == v2->size && v1->typeInfo == v2->typeInfo)
    {
        int vSize = v1->typeInfo->elemSize;
        void *intermediateResult = malloc(vSize);
        if (intermediateResult == NULL)
        {
            fprintf(stderr, "Ошибка выделения памяти");
            return BAD_MEMORY;
        }
        for (int elemNumber = 0; elemNumber < v1->size; elemNumber++)
        {
            void *elem1 = v1->elements + elemNumber * vSize;
            void *elem2 = v2->elements + elemNumber * vSize;

            v1->typeInfo->MultiElements(intermediateResult, elem1, elem2);

            vectorAddElement(res, intermediateResult, v1->typeInfo);
        }
        free(intermediateResult);
    }
    else if (v1->size != v2->size)
    {
        fprintf(stderr, "Ошибка несоотвеетсвия размеров векторов");
        return BAD_SIZE;
    }
    else if (v1->typeInfo != v2->typeInfo)
    {
        fprintf(stderr, "Ошибка несоотвеетсвия типов вектора");
        return BAD_TYPE;
    }
    return OK;
}

void vectorPrint(Vector *v)
{
    int vSize = v->typeInfo->elemSize;
    for (int elemNumber = 0; elemNumber < v->size; elemNumber++)
    {
        v->typeInfo->PrintElements(v->elements + elemNumber * vSize);
    }
    printf("\n");
}

void vectorAddToCollection(VectorCollection *collection, char *name, FieldInfo *VectorInfo)
{
    collection->vectors =
        realloc(collection->vectors, (collection->size + 1) * sizeof(NamedVector)); /*(лучше сделать другой шаг)*/
    NamedVector *newVec = &(collection->vectors[collection->size]);
    newVec->name = name;
    newVec->vector = vectorInit(VectorInfo);
    collection->size += 1;
}

Vector *vectorFindInCollection(VectorCollection *collection, char *name)
{
    for (int i = 0; i < collection->size; i++)
    {
        if (strcmp((collection->vectors[i]).name, name) == 0)
        {
            return (collection->vectors[i]).vector;
        }
    }
    return NULL;
}
