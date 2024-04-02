#include "lib/FieldInfo.h"
#include "lib/complex.h"
#include "lib/constants.h"
#include "lib/number.h"
#include "lib/tests.h"
#include "lib/vector.h"
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //    testIntVector();
    //    testComplexVector();
    VectorCollection collection = {NULL, 0};
    FieldInfo *IntFieldInfo = CreateIntFieldInfo();
    if (IntFieldInfo == NULL)
    {
        return 0;
    }

    FieldInfo *ComplexFieldInfo = CreateComplexFieldInfo();
    if (ComplexFieldInfo == NULL)
    {
        return 0;
    }

    int status = 0;
    printf("0. Создать вектор целых чисел\n");
    printf("1. Создать вектор комплексных чисел\n");
    printf("2. Добавить элемент в вектор целых чисел\n");
    printf("3. Добавить элемент в вектор комплексных чисел\n");
    printf("4. Суммировать векторы\n");
    printf("5. Произведение векторов\n");
    printf("6. Показать вектор по имени\n");
    printf("7. Остановить программу\n");
    char *name = NULL;
    char *name2 = NULL;
    char *name3 = NULL;
    Vector *vec = NULL;
    Vector *vec1 = NULL;
    Vector *vec2 = NULL;
    Vector *vecRes = NULL;
    int value = 0;
    int value2 = 0;
    Complex compEl = {0, 0};
    int flag = 1;
    while (flag && scanf("%d", &status) != EOF)
    {
        switch (status)
        {
        case 0:
            name = readline("Введите имя вектора целых чисел\n");
            if (name == NULL)
            {
                return 0;
            }
            vectorAddToCollection(&collection, name, IntFieldInfo);
            break;

        case 1:
            name = readline("Введите имя вектора комплексных чисел\n");
            if (name == NULL)
            {
                return 0;
            }
            vectorAddToCollection(&collection, name, ComplexFieldInfo);
            break;

        case 2:
            name = readline("Введите имя вектора целых чисел\n");
            if (name == NULL)
            {
                return 0;
            }
            vec = vectorFindInCollection(&collection, name);
            if (vec == NULL)
            {
                fprintf(stderr, "Вектор не найден\n");
                free(name);
                break;
            }
            printf("Введите целое число: ");
            scanf("%d", &value);
            vectorAddElement(vec, &value, IntFieldInfo);
            free(name);
            break;

        case 3:
            name = readline("Введите имя вектора комплексных чисел\n");
            if (name == NULL)
            {
                return 0;
            }
            vec = vectorFindInCollection(&collection, name);
            if (vec == NULL)
            {
                fprintf(stderr, "Вектор не найден\n");
                free(name);
                break;
            }
            printf("Введите два целых числа, первое - действительная часть, вторая - мнимая: ");
            scanf("%d %d", &value, &value2);
            compEl.Real = value;
            compEl.Im = value2;
            vectorAddElement(vec, &compEl, ComplexFieldInfo);
            free(name);
            break;

        case 4:
            name = readline("Введите имя первого вектора в сумме\n");
            name2 = readline("Введите имя второго вектора в сумме\n");
            name3 = readline("Введите имя вектора результата\n");
            if (!name || !name2 || !name3)
            {
                fprintf(stderr, "Случилась беда\n");
                free(name);
                free(name2);
                free(name3);
                break;
            }
            vecRes = vectorFindInCollection(&collection, name3);
            if (vecRes == NULL)
            {
                vectorAddToCollection(&collection, name3, IntFieldInfo);
                vecRes = vectorFindInCollection(&collection, name3);
            }
            else
            {
                vecRes->size = 0;
                free(name3);
            }

            vec1 = vectorFindInCollection(&collection, name);
            vec2 = vectorFindInCollection(&collection, name2);
            if (!vec1 || !vec2)
            {
                fprintf(stderr, "Какой-то из векторов не найден\n");
                free(name);
                free(name2);
                break;
            }
            switch (vectorSum(vecRes, vec1, vec2))
            {
            case BAD_MEMORY:
            case BAD_TYPE:
            case BAD_SIZE:
                free(name);
                free(name2);
                continue;
            }
            free(name);
            free(name2);
            break;

        case 5:
            name = readline("Введите имя первого вектора в произведении\n");
            name2 = readline("Введите имя второго вектора в произведении\n");
            name3 = readline("Введите имя вектора результата\n");
            if (!name || !name2 || !name3)
            {
                fprintf(stderr, "Случилась беда\n");
                free(name);
                free(name2);
                free(name3);
                break;
            }
            vecRes = vectorFindInCollection(&collection, name3);
            if (vecRes == NULL)
            {
                vectorAddToCollection(&collection, name3, IntFieldInfo);
                vecRes = vectorFindInCollection(&collection, name3);
            }
            else
            {
                vecRes->size = 0;
                free(name3);
            }

            vec1 = vectorFindInCollection(&collection, name);
            vec2 = vectorFindInCollection(&collection, name2);
            if (!vec1 || !vec2)
            {
                fprintf(stderr, "Какой-то из векторов не найден\n");
                free(name);
                free(name2);
                break;
            }
            switch (vectorMulti(vecRes, vec1, vec2))
            {
            case BAD_MEMORY:
            case BAD_TYPE:
            case BAD_SIZE:
                free(name);
                free(name2);
                continue;
            }
            free(name);
            free(name2);
            break;

        case 6:
            name = readline("Введите имя вектора\n");
            if (name == NULL)
            {
                return 0;
            }
            vec = vectorFindInCollection(&collection, name);
            free(name);
            if (vec == NULL)
            {
                fprintf(stderr, "Какой-то из векторов не найден\n");
                break;
            }
            vectorPrint(vec);
            break;

        case 7:
            flag = 0;
            break;

        default:
            fprintf(stderr, "Неизвестная команда\n");
        }
        printf("0. Создать вектор целых чисел\n");
        printf("1. Создать вектор комплексных чисел\n");
        printf("2. Добавить элемент в вектор целых чисел\n");
        printf("3. Добавить элемент в вектор комплексных чисел\n");
        printf("4. Суммировать векторы\n");
        printf("5. Произведение векторов\n");
        printf("6. Показать вектор по имени\n");
        printf("7. Остановить программу\n");
    }

    for (int i = 0; i < collection.size; i++)
    {
        free((collection.vectors[i]).name);
        vectorFree((collection.vectors[i]).vector);
    }
    return 0;
}
