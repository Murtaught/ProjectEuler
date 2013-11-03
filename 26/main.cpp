#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_D = 1000;

int cycle_length(int d)
{
    cout << "1 / " << d << " = 0.";

    int divident = 10;
    vector<int> answer, divd_hist;

    while (true)
    {
        if ( divident == 0 )
        {
            for (size_t i = 0; i < answer.size(); ++i)
                cout << answer[i];
            cout << endl;

            return 0;
        }

        while (divident < d)
        {
            divident *= 10;
            answer.push_back( 0 );
        }

        bool cycle_found = false;
        size_t cycle_start, cycle_length;

        for (size_t i = 0; i < divd_hist.size(); ++i)
            if (divd_hist[i] == divident)
            {
                cycle_found  = true;
                cycle_start  = i;
                cycle_length = answer.size() - cycle_start;
            }

        if ( cycle_found )
        {
            for (size_t i = 0; i < cycle_start; ++i)
                cout << answer[i];
            cout << "(";
            for (size_t i = cycle_start; i < answer.size(); ++i)
                cout << answer[i];
            cout << ")  ::  cycle length = " << cycle_length << endl;

            return cycle_length;
        }
        else
            divd_hist.push_back(divident);


        answer.push_back( divident / d );
        divident = ( divident % d ) * 10;
    }
}

int main()
{
    int max_length = -1, max_d;
    for (int d = 2; d <= MAX_D; ++d)
        if (max_length < cycle_length(d))
        {
            max_length = cycle_length(d);
            max_d = d;
        }

    cout << "Maximum cycle length for d up to " << MAX_D
         << " is " << max_length << " for d = " << max_d << endl;

    return 0;
}

