#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef unsigned long long int uint64;

const uint64 START = pow10(12) + 1;

uint64 UINT64_MAX = 0;

uint64 my_sqrt(uint64 x)
{
    //cout << "my_sqrt( " << x << " )" << endl;
    //cout << "uint64   " << UINT64_MAX << endl;

    uint64 l = 1, r = x;
    while (l < r)
    {
        uint64 m = (l + r) / 2;
        uint64 sqr_m = m * m;

        //cout << "l = " << l << ", r = " << r
        //     << ",  => m = " << m << ",  m^2 = " << sqr_m << endl;

        if (sqr_m == x)
            return m;

        if (sqr_m > x)
        {
            if (r != m)
                r = m;
            else
                break;
        }
        else
        {
            if (l != m)
                l = m;
            else
                break;
        }


    }

    return 0;
}

bool check(uint64 sum)
{
    //if (sum % 2000 == 0)
    //    cout << "Processing " << sum << "... " << endl;

    uint64 gamma = sum * (sum - 1);
    if ( gamma & 1 )
        return false;
    gamma /= 2;

    uint64 SQRT = my_sqrt(1 + 4 * gamma);

    //cout << "SQRT processed... its " << SQRT << endl;

    if ( SQRT == 0 )
        return false;

    ++SQRT;
    if ( SQRT & 1 )
    {
        cout << "Strange thing, SQRT + 1 is not divisible by 2!" << endl;
        return false;
    }

    cout << "Wow!" << endl;

    uint64 a = SQRT / 2;
    uint64 b = sum - a;


    cout << "sum = " << sum << ", => a = " << a
         << ",  b = " << b << " ; " << endl;

    return true;

}

int main()
{
    --UINT64_MAX;
    cout << "uint64 max = " << UINT64_MAX << endl;

    for (uint64 i = 0; /*!check(i)*/ i < 1000; ++i) check(i);
    cout << "DOEN" << endl;

    return 0;
}

