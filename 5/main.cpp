#include <iostream>
using namespace std;
typedef unsigned long long int uint64;

uint64 gcd(uint64 a, uint64 b)
{
    uint64 c;
    while (a != 0)
    {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

uint64 lcm(uint64 a, uint64 b)
{
    return (a * b) / gcd(a, b);
}

const int start  = 1;
const int finish = 20;

int main()
{
    uint64 answer = 1;

    for (int i = start; i <= finish; ++i)
    {
        answer = lcm(answer, i);
        cout << "After adding " << i << " answer = " << answer << endl;
    }

    cout << endl << "Answer is " << answer << endl;

    return 0;
}

