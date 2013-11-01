#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
using namespace std;
typedef unsigned int uint;

uint layer(uint n, uint m, uint k, uint N)
{
    return 2*(n*m + n*k + m*k) + 4*(n + m + k + N - 2)*(N - 1);
}

const uint LAYER_CEILING = 100000;
vector<uint> layer_pop( LAYER_CEILING + 1, 0 ); // layer popularity

void brute_force()
{
    for (int n = 1; layer(n, n, n, 1) <= LAYER_CEILING; ++n)
        for (int m = n; layer(n, m, m, 1) <= LAYER_CEILING; ++m)
            for (int k = m; layer(n, m, k, 1) <= LAYER_CEILING; ++k)
                for (int N = 1; layer(n, m, k, N) <= LAYER_CEILING; ++N)
                    ++layer_pop[layer(n, m, k, N)];
}

void dump(const char *filename, const vector<uint> &layer_pop)
{
    cout << "Saving layer popularity array to file \""
         << filename << "\"... ";

    ofstream file(filename);

    file << layer_pop.size() << "\n";
    for (size_t i = 0; i < layer_pop.size(); ++i)
        file << layer_pop[i] << " ";

    file.flush();
    cout << "done." << endl;
}

void load(const char *filename, vector<uint> &layer_pop)
{
    cout << "Loading layer popularity array from file \""
         << filename << "\"..." << endl;

    ifstream file(filename);

    size_t size;
    file >> size;

    layer_pop.clear();
    layer_pop.resize(size);

    for (size_t i = 0; i < size; ++i)
        file >> layer_pop[i];

    cout << "done." << endl;
}

void research()
{
    cout << "Going through " << layer_pop.size() << " elements..." << endl;

    for (size_t i = 0; i < layer_pop.size(); ++i)
        if ( layer_pop[i] == 1000 )
        {
            cout << "C(" << i << ") = 1000" << endl;
            break;
        }
}

int main()
{
    brute_force();
    //dump("dump.txt", layer_pop);

    //load();
    research();

    return 0;
}
