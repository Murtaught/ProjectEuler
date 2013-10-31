#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
using namespace std;
typedef unsigned int uint;

class Cuboid
{
    uint n, m, k;
    vector<uint> caphash;

private:
    // along k
    uint cross_section_layer(uint N)
    {
        if (N == 0)
            return 0;

        return 2 * ((n + m) + 2 * (N - 1));
    }

    // along k
    uint cap_layer(uint N)
    {
        while ( N >= caphash.size() )
        {
            uint last_known_N = caphash.size() - 1;
            uint last_known_value = caphash.back();

            caphash.push_back(last_known_value + cross_section_layer(last_known_N));
        }

        return caphash[N];
    }

public:
    Cuboid(uint n, uint m, uint k)
        : n(n), m(m), k(k), caphash(2, 0)
    {
        caphash[1] = n * m;
    }

    uint layer_size(uint N)
    {
        //cout << "      l_s(" << N << "):  cross = " << cross_section_layer(N) << ", cap = " << cap_layer(N) << endl;

        if (N == 0)
            throw "undefined";

        return k * cross_section_layer(N) + 2 * cap_layer(N);
    }
};

void user_mode()
{
    int n, m, k;
    cout << "Input cuboid dimensions (n ; m ; l): " << endl;
    cout << "  n = "; cin >> n;
    cout << "  m = "; cin >> m;
    cout << "  k = "; cin >> k;

    cout << "\nCuboid (" << n << " ; " << m << " ; " << k << "): \n";

    Cuboid cub(n, m, k);

    for (int i = 1; i <= 7; ++i)
        cout << "    N = " << i << ":  " << cub.layer_size(i) << endl;

    cout << endl << cub.layer_size(1);
    for (int i = 2; i <= 15; ++i)
        cout << ", " << cub.layer_size(i);

    cout << endl;
}

const uint LAYER_CEILING = 1000000;
vector<uint> layer_pop( LAYER_CEILING + 1 ); // layer popularity

void brute_force()
{
    uint i, j, k;

    for (i = 1; ; ++i)
    {
        cout << i << endl;
        for (j = i; ; ++j)
        {
            cout << "  " << j << endl;

            for (k = j; ; ++k)
            {
                Cuboid cub(i, j, k);
                //cout << "  (" << i << ", " << j << ", " << k << ") | ";
                //cout.flush();

                for (uint N = 1; ; ++N)
                {
                    uint tmp = cub.layer_size(N);

                    if ( tmp > LAYER_CEILING )
                    {
                        //cout << N << " done." << endl;

                        if (N == 1)
                            goto cont;

                        break;
                    }

                    int different = 1;
                    if (j != i)
                        ++different;
                    if (k != i && k != j)
                        ++different;

                    static const uint PERMUTATIONS[] = { 0, 1, 3, 6 };

                    layer_pop[tmp] += PERMUTATIONS[different];
                }

            }
            cont:

            if (k == j)
                break;
        }

        if (j == i)
            break;
    }

}

void dump()
{
    const char filename[] = "dump.txt";
    cout << "Saving layer popularity array to file \""
         << filename << "\"... ";

    ofstream file(filename);

    file << layer_pop.size() << "\n";
    for (size_t i = 0; i < layer_pop.size(); ++i)
        file << layer_pop[i] << " ";

    file.flush();
    cout << "done." << endl;
}

void load()
{
    const char filename[] = "dump.txt";
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
    cout << "Researching " << layer_pop.size() << " elements..." << endl;

    bool greater1000 = false;
    bool exact1000 = false;

    for (size_t i = 0; i < layer_pop.size(); ++i)
        if ( layer_pop[i] >= 1000 )
        {
            greater1000 = true;
            if ( layer_pop[i] == 1000 )
                exact1000 = true;
        }

    cout << "greater1000 = " << greater1000 << endl;
    cout << "exact1000   = " << exact1000 << endl;

}

void generate()
{
    ofstream file("generated.txt");

    for (int i = 1; i <= 12; ++i)
        for (int j = 1; j <= 12; ++j)
            for (int k = 1; k <= 12; ++k)
            {
                file << "     " << i << "  " << j << "  " << k << "  :  ";

                Cuboid cub(i, j, k);
                file << cub.layer_size(1);
                for (int i = 2; i <= 15; ++i)
                    file << ", " << cub.layer_size(i);

                file << endl;
            }
}

int main()
{
    //brute_force();
    //dump();

    //load();
    //research();

    user_mode();

    //generate();

    return 0;
}

