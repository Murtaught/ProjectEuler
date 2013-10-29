#include <iostream>
using namespace std;

const int N = 10000;

int d(int n)
{
    int sum = 0;

    for (int i = 1; i < n; ++i)
        if ((n % i) == 0)
            sum += i;

    return sum;
}

bool is_amicable(int a)
{
    int b = d(a);

    return (a != b) && (a == d(b));
}

int main()
{
    long sum = 0;
    for (int i = 1; i < N; ++i)
        if ( is_amicable(i) )
        {
            cout << i << " is amicable!" << endl;
            sum += i;
        }

    cout << "Sum of all the amicable numbers under 10000 is " << sum << endl;

    return 0;
}

