#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long int uint64;

// Pandigital numbers cannot have more than 9 digits
// So n_max = 9

const uint64 PANDIGITAL9_MIN = 123456789;
const uint64 PANDIGITAL9_MAX = 987654321;

// Let's just find all the pandigital primes

uint64 get_previous_pandigital(uint64 num)
{
    string s = to_string(num); // C++11
    if ( !prev_permutation(s.begin(), s.end()) )
    {
        if (s.length() > 1)
            s = s.substr(1); // drop the first symbol
        else
            throw "Oh shit!";
    }
    return stoull(s);
}

vector<uint64> primes;

bool is_prime(uint64 num)
{
    uint64 SQRT = ceil(sqrt(num));
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

    // How much is enough?
    const uint64 CEILING = ceil(sqrt(PANDIGITAL9_MAX));

    for (uint64 p = 7; p <= CEILING; p += 2)
        if ( is_prime(p) )
            primes.push_back(p);

    printf("Found enough primes (actually %lu of them) \n", primes.size());
}

void find_and_print_the_largest_pandigital_prime()
{
    uint64 cur = PANDIGITAL9_MAX;
    while (true)
    {
        cout << cur << "..." << endl;
        if ( is_prime(cur) )
        {
            cout << cur << " is the largest pandigital prime! Wow!" << endl;
            break;
        }
        cur = get_previous_pandigital(cur);
    }
}

void find_and_print_all_pandigital_primes()
{
    vector<uint64> panprimes;
    uint64 cur = PANDIGITAL9_MAX;
    while (cur > 1)
    {
        if ( is_prime(cur) )
            panprimes.push_back(cur);

        cur = get_previous_pandigital(cur);
    }

    cout << "There are all pandigital primes that exist:" << endl;

    while ( !panprimes.empty() )
    {
        cout << panprimes.back() << "  ";
        panprimes.pop_back();
    }

    cout << endl;
}

int main()
{
    find_enough_primes();
    find_and_print_the_largest_pandigital_prime();
    //find_and_print_all_pandigital_primes();

    return 0;
}

