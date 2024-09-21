#include "onegin_testing.h"

void test_swap()
{
    char s1[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    char s2[] = {'f', 'g', 'h', 'v', 'l', '\0'};

    DEBUG_PRINTF("\n---SWAP TEST---\n");
    DEBUG_PRINTF("before:\n"
                 "s1: %s\n"
                 "s2: %s\n", s1, s2);

    swap_by_8((void*)s1, (void*)s2, strlen(s1));
    DEBUG_PRINTF("after:\n"
                 "s1: %s\n"
                 "s2: %s\n", s1, s2);
}
