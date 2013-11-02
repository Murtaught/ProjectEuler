#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned int uint;

const int UPPER_LIMIT = 28123;

vector<uint> abundants;

uint sum_of_divisors(uint num)
{
    uint sum = 0;
    for (uint i = 1; i < num; ++i)
        if ((num % i) == 0)
            sum += i;

    return sum;
}

bool is_abundant(uint num)
{
    return sum_of_divisors(num) > num;
}

void find_abundants()
{
    printf("Starting search for abundant numbers... \n");
    for (uint i = 2; i <= UPPER_LIMIT; ++i)
        if ( is_abundant(i) )
            abundants.push_back(i);

    printf("Found %lu abundant numbers under %d. \n",
           abundants.size(), UPPER_LIMIT);
}

bool is_abundant_fast(uint num)
{
    vector<uint>::iterator it =
            std::lower_bound(abundants.begin(), abundants.end(), num);

    return (it != abundants.end()) && (*it == num);
}

bool can_be_written_as_sum_of_2_ab_nums(uint num)
{
    for (uint i = 0; i < abundants.size() && abundants[i] < num; ++i)
        if ( is_abundant_fast(num - abundants[i]) )
            return true;

    return false;
}

void sum_of_nums_that_cannot()
{
    printf("Starting conting needed sum... \n");
    uint sum = 0;
    for (uint i = 0; i < UPPER_LIMIT; ++i)
        if ( !can_be_written_as_sum_of_2_ab_nums(i) )
            sum += i;

    printf("Sum of all the positive integers which cannot \n"
           "be written as the sum of two abundant numbers is %u.\n",
           sum);
}

int main()
{
    find_abundants();
    sum_of_nums_that_cannot();

    return 0;
}

