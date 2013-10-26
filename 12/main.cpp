#include <cstdio>
#include <cmath>
using namespace std;

typedef unsigned long long int uint64;

int number_of_divisors(uint64 num)
{
    int sum = 0;

    uint64 SQRT = ceil(sqrt(num));
    for (uint64 i = 1; i <= SQRT; ++i)
        if ((num % i) == 0)
            sum += 2;

    return sum;
}

int main()
{
    uint64 index = 1, number = 1;
    while (true)
    {
        int nod = number_of_divisors(number);

        printf("#%llu: %llu  => %d \n", index, number, nod);

        if (nod > 500)
            break;

        ++index;
        number += index;
    }

    return 0;
}

