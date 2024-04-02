#include "tests.h"
#include <assert.h>
#include <stdio.h>
void testIntVector()
{
    FieldInfo *IntFieldInfo = CreateIntFieldInfo();

    VectorCollection collection = {NULL, 0};

    vectorAddToCollection(&collection, "test1", IntFieldInfo);
    assert(collection.size == 1);
    vectorAddToCollection(&collection, "test2", IntFieldInfo);
    assert(collection.size == 2);
    vectorAddToCollection(&collection, "resSum", IntFieldInfo);
    assert(collection.size == 3);
    vectorAddToCollection(&collection, "resMulti", IntFieldInfo);
    assert(collection.size == 4);
    Vector *vec1 = vectorFindInCollection(&collection, "test1");
    assert(vec1);
    Vector *vec2 = vectorFindInCollection(&collection, "test1");
    assert(vec2);

    int temp1 = 2, temp2 = 3, temp3 = 6, temp4 = 9;

    Vector *vecResSum = vectorFindInCollection(&collection, "resSum");
    assert(vecResSum);
    Vector *vecResMulti = vectorFindInCollection(&collection, "resMulti");
    assert(vecResMulti);
    vectorAddElement(vec1, &temp1, IntFieldInfo);
    assert(vec1->size == 1);
    vectorAddElement(vec1, &temp2, IntFieldInfo);
    assert(vec1->size == 2);
    vectorAddElement(vec2, &temp3, IntFieldInfo);
    assert(vec2->size == 1);
    vectorAddElement(vec2, &temp4, IntFieldInfo);
    assert(vec2->size == 2);
    vectorSum(&vecResSum, vec1, vec2);
    assert(vecResSum->size == 2);
    assert(vecResSum->elements[0] == 8);
    assert(vecResSum->elements[1] == 12);
    vectorMulti(&vecResMulti, vec1, vec2);
    assert(vecResMulti->size == 2);
    assert(vecResMulti->elements[0] == 12);
    assert(vecResMulti->elements[1] == 27);
    free(IntFieldInfo);
}

void testComplexVector()
{
    FieldInfo *ComplexFieldInfo = CreateComplexFieldInfo();

    VectorCollection collection = {NULL, 0};

    vectorAddToCollection(&collection, "test1", ComplexFieldInfo);
    assert(collection.size == 1);
    vectorAddToCollection(&collection, "test2", ComplexFieldInfo);
    assert(collection.size == 2);
    vectorAddToCollection(&collection, "resSum", ComplexFieldInfo);
    assert(collection.size == 3);
    vectorAddToCollection(&collection, "resMulti", ComplexFieldInfo);
    assert(collection.size == 4);
    Complex elem11 = {2, 4};
    Complex elem12 = {5, 6};
    Complex elem21 = {10, 14};
    Complex elem22 = {12, 16};
    Vector *vec1 = vectorFindInCollection(&collection, "test1");
    assert(vec1);
    Vector *vec2 = vectorFindInCollection(&collection, "test1");
    assert(vec2);
    Vector *vecResSum = vectorFindInCollection(&collection, "resSum");
    assert(vecResSum);
    Vector *vecResMulti = vectorFindInCollection(&collection, "resMulti");
    assert(vecResMulti);
    vectorAddElement(vec1, elem11, IntFieldInfo);
    assert(vec1->size == 1);
    vectorAddElement(vec1, elem12, IntFieldInfo);
    assert(vec1->size == 2);
    vectorAddElement(vec2, elem21, IntFieldInfo);
    assert(vec2->size == 1);
    vectorAddElement(vec2, elem22, IntFieldInfo);
    assert(vec2->size == 2);
    vectorSum(&vecResSum, vec1, vec2);
    assert(vecResSum->elements[0].Real == 12);
    assert(vecResSum->elements[0].Im == 18);
    assert(vecResSum->elements[1].Real == 17);
    assert(vecResSum->elements[1].Im == 22);
    vectorMulti(&vecResMulti, vec1, vec2);
    assert(vecResSum->elements[0].Real == -36);
    assert(vecResSum->elements[0].Im == 68);
    assert(vecResSum->elements[1].Real == -36);
    assert(vecResSum->elements[1].Im == 152);
}
