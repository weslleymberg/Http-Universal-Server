#include <CUnit/Basic.h>
#include "test_dinamic_array.h"

int main()
{
    CU_pSuite dinamicArray_pSuite = NULL;

    if (CU_initialize_registry() != CUE_SUCCESS)
        return CU_get_error();

    dinamicArray_pSuite = CU_add_suite("Dinamic Array", test_dinamic_array_setup, test_dinamic_array_teardown);

    if (dinamicArray_pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((CU_add_test(dinamicArray_pSuite, "it creates an array", test_dinamic_array_create_array)) == NULL ||
        (CU_add_test(dinamicArray_pSuite, "it include an item", test_dinamic_array_include_item)) == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
