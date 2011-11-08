#include <CUnit/Basic.h>
#include <stdlib.h>
#include <string.h>
#include "test_dinamic_array.h"
#include "../src/dinamicArray.h"

int test_dinamic_array_setup(void)
{
    return 0;
}

void test_dinamic_array_create_array(void)
{
    struct DinamicArray *Array = NULL;
    CU_ASSERT(Array == NULL);
    Array = create_array();
    CU_ASSERT(Array != NULL);
}

void test_dinamic_array_include_item(void)
{
    struct DinamicArray *Array = create_array();
    char string[] = {"Hello World"};

    append(Array, string);
    CU_ASSERT(strcmp(Array->next_element->element, string) == 0);
    CU_ASSERT(Array->next_element->next_element == NULL);
}

int test_dinamic_array_teardown(void)
{
    return 0;
}
