#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long int uint64;

size_t names_size;

string names[] =
{
    #include "names.txt"
};

int main()
{
    // it is so dirty unportable GCC hack that i'm almost ashamed
    names_size = sizeof(names) / sizeof(string);

    printf("There is %lu names in the file.\n", names_size);

    printf("Sorting... \n");
    sort(names, names + names_size);

    printf("Counting name scores... \n");
    uint64 total_sum = 0;
    for (size_t i = 0; i < names_size; ++i)
    {
        uint64 sum = 0;
        for (size_t j = 0; j < names[i].size(); ++j)
            sum += names[i][j] - 'A' + 1;

        sum *= (i + 1);

        total_sum += sum;
    }

    printf("\nSum of all name scores is %llu \n", total_sum);

    return 0;
}
