#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int K = 5;

int main()
{
    ifstream in("input.txt");

    string s;
    while ( true )
    {
        string t;
        in >> t;

        if ( !in )
            break;

        s += t;
    }

    int max_value = -1, max_i = -1;

    const size_t FINISH = s.length() - K + 1;
    for (size_t i = 0; i < FINISH; ++i)
    {
        int tmp = 1;
        for (size_t j = 0; j < K; ++j)
            tmp *= (s[i + j] - '0');

        if (tmp > max_value)
        {
            max_value = tmp;
            max_i     = i;
        }
    }

    cout << "Largest produst is " << max_value << endl;
    cout << "Found at characters #" << max_i << "..#" << (max_i + K - 1)
         << ": \"" << s.substr(max_i, K) << "\"" << endl;

    return 0;
}

