#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = pow10(6); // one million

vector<int> primes;

bool is_prime(int num)
{
    int SQRT = ceil(sqrt(num));

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

    for (int p = 7; p <= N; p += 2)
        if ( is_prime(p) )
            primes.push_back(p);

    printf("Found enough primes (actually %lu of them) \n", primes.size());
}

int prime_than_is_a_sum_of_l_consecutive_primes(int l)
{
    //cout << "length = " << l << ":" << endl;

    const int L = primes.size() - l + 1;

    int sum = 0;
    for (int j = 0; j < l; ++j)
        sum += primes[j];

    for (int i = 0; i < L; ++i)
    {
        if ( is_prime(sum) )
        {
            //cout << "    " << primes[i];
            //for (int j = 1; j < l; ++j)
            //    cout << " + " << primes[i + j];
            //cout << " = " << sum << endl;
            return sum;
        }

        sum -= primes[i];
        sum += primes[i + l];
    }

    return -1;
}

int calculate_l_max()
{
    int l = 0, sum = 0;
    while ( sum < N )
    {
        sum += primes[l];
        ++l;
    }

    return l - 1;
}

int main()
{
    find_enough_primes();

    int l_max = calculate_l_max();
    cout << "Maximum length (upper bound of our answer) = " << l_max << endl;

    int answer;

    int i = l_max;
    while ( true )
    {
        cout << "Searching answer for " << i << " consecutive primes... ";
        cout.flush();

        answer = prime_than_is_a_sum_of_l_consecutive_primes(i);
        cout << answer << endl;

        if ( answer != -1 && answer < N )
            break;
        else
            --i;
    }

    cout << "\nAnswer is " << answer << endl;

    return 0;
}

