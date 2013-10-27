#include <iostream>
using namespace std;

int main()
{
    for (int a = 1; a <= 1000; ++a)
        for (int b = 1; b <= (1000 - a); ++b)
        {
            int c = 1000 - a - b;

            if ( c*c == a*a + b*b )
            {
                cout << a << "^2 + " << b << "^2 = " << c << "^2;  ";
                cout << "a * b * c = " << (a * b * c) << ";" << endl;
            }
        }

    return 0;
}

