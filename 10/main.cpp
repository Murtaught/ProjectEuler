#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long int int64;

const int N = 2 * pow10(6); // two million

vector<int64> primes;

bool is_prime(int64 num)
{
    int64 SQRT = ceil(sqrt(num));

    for (int i = 0; primes[i] <= SQRT; ++i)
        if ((num % primes[i]) == 0)
            return false;

    return true;
}

void find_enough_primes()
{
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);

    for (int64 p = 7; p < N; p += 2)
        if ( is_prime(p) )
            primes.push_back(p);

    printf("Found enough primes (actually %lu of them) \n", primes.size());
}

int main()
{
    find_enough_primes();

    int64 sum = 0;

    while ( !primes.empty() )
    {
        sum += primes.back();
        primes.pop_back();
    }

    cout << "Sum of all primes below " << N << " is " << sum << endl;


    return 0;
}

