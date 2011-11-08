#include <CUnit/Basic.h>
#include "../src/dinamicArray.h"
#include "../src/directorieListing.h"
#include "test_listing_diretories.h"

int test_diretorie_listing_setup(void)
{
    return 0;
}

void test_listing_diretories(void)
{
    DinamicArray *files;

    files = list_dict("./test_folder");
    CU_ASSERT(strcmp(files->next_element->element, "test_file") == 0);
    CU_ASSERT(strcmp(files->next_element->next_element->element, "test_folder") == 0);
}

int test_diretorie_listing_teardown(void)
{
    return 0;
}
