#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stringutils.h"

void test_string_after_last()
{
	char *dn = "dc=root";
	assert(strcmp("root", string_after_last(dn, '=')) == 0);
}

void test_string_before()
{
	char *dn = "o=bar,dc=root";
	assert(strcmp("o=bar", string_before(dn, ',')) == 0);
}

int main()
{
	test_string_after_last();
	test_string_before();
	return 0;
}
