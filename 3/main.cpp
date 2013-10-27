#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long int uint64;

uint64 NUMBER = 600851475143;

uint64 max_factor = 0;

void check_factor(uint64 factor)
{
    if (factor > max_factor)
        max_factor = factor;

    printf("Found factor %llu, cur. max = %llu \n",
            factor, max_factor);
}

int main()
{


    while (true)
    {
        for (uint64 i = 2; i <= NUMBER; ++i)
            if ((NUMBER % i) == 0)
            {
                check_factor(i);

                NUMBER /= i;
                goto next;
            }

        printf("No prime factors found for %llu, "
               "which means it is prime number itself \n", NUMBER);
        check_factor(NUMBER);

        break;

        next:;
    }

    printf("\nMax factor is %llu. \n", max_factor);

    return 0;
}

