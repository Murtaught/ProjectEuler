#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
//#include <cmath>
#include <algorithm>
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
    const int64 CEILING = ceil(sqrt(10000));

    for (int64 p = 7; p <= CEILING; p += 2)
        if ( is_prime(p) )
            primes.push_back(p);

    // This is very important hack
    primes.push_back(CEILING + 1);
    // Ok, CEILING is not prime (most likely). But this ensures that
    // program wont crash when square root of is_prime() argument
    // is greater than primes.back()

    printf("Found enough primes (actually %lu of them) \n", primes.size());
}

bool is_4_digit(int64 num)
{
    return (1000 <= num) && (num <= 9999);
}

string to_4_string(int64 num)
{
    string s = to_string(num);
    while (s.length() < 4)
        s = '0' + s;

    return s;
}

void process(int64 num)
{
    string s = to_4_string(num);

    if ( !is_prime(num) )
        return;

    string g = s;
    sort(g.begin(), g.end());

    do {
        if ( g != s )
        {
            int64 a = num;
            int64 b = stoll(g);
            int64 c = b + (b - a);

            if ( is_prime(b) && ((b - a) > 0) && is_4_digit(c) )
            {
                string c_str = to_4_string(c);
                if ( is_permutation(g.begin(), g.end(), c_str.begin()) )
                {
                    if ( is_prime(c) )
                    {
                        cout << s << "  " << g << "  " << c_str
                             << "  delta = " << (b - a) << endl;
                    }
                }
            }
        }

    } while ( next_permutation(g.begin(), g.end()) );

}

int main()
{
    find_enough_primes();
    for (int i = 0; i <= 9999; ++i)
        process(i);

    return 0;
}

