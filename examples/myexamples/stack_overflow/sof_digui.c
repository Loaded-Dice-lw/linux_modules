#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX (1UL << 20)

typedef unsigned long long u64;
typedef unsigned int u32;
u32 max_addend = MAX;

u64 sum_till_max(u32 n)
{
	u64 sum;
	n++;
	sum = n;

	if (n < max_addend)
		sum += sum_till_max(n);
	return sum;
}


int main(int argc, char **argv)
{
	u64 sum	= 0;
	if ((argc == 2) && isdigit(*argv[1]))
		max_addend = strtoul(argv[1], NULL, 0);
	sum = sum_till_max(0);
	printf("sum = %llu\n", sum);
		
	return 0;
}
