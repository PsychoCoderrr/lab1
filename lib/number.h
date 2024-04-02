#ifndef NUMBER_H
#define NUMBER_H
#include "FieldInfo.h"

void numberSum(void* res, void* a, void* b); /*(должно быть загнано внутрь .c файла)*/

void numberMulti(void* res, void* a, void* b);

FieldInfo* CreateIntFieldInfo();

#endif
