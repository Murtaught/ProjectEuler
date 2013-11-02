#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MILLION = 1000 * 1000;

int main()
{
    // this is 1th permutation, not 0th
    string s = "0123456789";

    for (int i = 1; i < MILLION; ++i)
        next_permutation(s.begin(), s.end());

    cout << MILLION << "th permutation of numbers 0..9 is "
         << s << endl;

    return 0;
}

