#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MILLION = 1000 * 1000 - 1;

int main()
{
    string s = "0123456789";

    for (int i = 0; i < MILLION; ++i)
        next_permutation(s.begin(), s.end());

    cout << MILLION << "th permutation of numbers 0..9 is "
         << s << endl;

    return 0;
}

