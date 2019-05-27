#include <stdio.h>
#include <time.h>

/* 
 * To compile: 
 * gcc -O3 -o volatile volatile.c
 */

long timediff(clock_t t1, clock_t t2) {
    long elapsed;
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed;
}

int main(int argc, char const *argv[])
{
	clock_t t1, t2;
	long elapsed;

	volatile int i = 0;
	/* Try the program w/o volatile, 
	and see the performance variation. */

    t1 = clock();
	for (; i < 100000000; ++i)
	{
		/* code */
	}
	t2 = clock();

    elapsed = timediff(t1, t2);
    printf("elapsed: %ld ms\n", elapsed);

	return 0;
}