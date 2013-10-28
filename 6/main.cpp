#include <iostream>
using namespace std;
typedef long long int int64;

const int N = 100;

int64 sqr(int x)
{
    return x * x;
}

int main()
{
    int64 sum_of_sqr = 0;
    for (int i = 1; i <= N; ++i)
        sum_of_sqr += sqr(i);

    cout << "Answer is: " << ( sqr(N * (N + 1) / 2.0) - sum_of_sqr ) << endl;

    return 0;
}

