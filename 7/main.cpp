#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int int64;

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

    // How much is enough?
    const int ENOUGH = 10001;

    for (int64 p = 7; primes.size() < ENOUGH; p += 2)
        if ( is_prime(p) )
            primes.push_back(p);
}

void generage_primes_header()
{
    ofstream file("primes.h");

    file << "unsigned long long primes[" << primes.size()
         << "]\n    = { 2";

    for (size_t i = 1; i < primes.size(); ++i)
        file << ",\n        " << primes[i];

    file << " };" << endl;
}

int main()
{
    find_enough_primes();

    generage_primes_header();
    //cout << "10001th prime is " << primes.back() << endl;

    return 0;
}

