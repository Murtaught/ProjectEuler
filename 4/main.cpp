#include <iostream>
#include <string>
using namespace std;

int largest_palindrome = -1;
int la, lb;

bool is_palindrome(string const& s)
{
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        if ( s[i] != s[j] )
            return false;

    return true;
}

void check(int a, int b)
{
    int number = a * b;
    string tmp = to_string(number); // C++11

    if ( is_palindrome(tmp) && (number > largest_palindrome) )
    {
        largest_palindrome = number;
        la = a;
        lb = b;
    }
}

int main()
{
    for (int a = 100; a <= 999; ++a)
        for (int b = 100; b <= 999; ++b)
            check(a, b);

    cout << "Largest palindrome is " << la << " * " << lb <<
            " = " << largest_palindrome << endl;

    return 0;
}

