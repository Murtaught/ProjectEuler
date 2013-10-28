#include <iostream>
using namespace std;
typedef long long int uint64;

const int N = 20; //this is solution for NxN grid

uint64 grid[N + 1][N + 1];

void print_grid()
{
    cout << "Resulting grid: \n";
    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= N; ++j)
            cout << grid[i][j] << "  ";

        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    for (int j = 0; j <= N; ++j)
        grid[N][j] = 1;

    for (int i = N - 1; i >= 0; --i)
    {
        grid[i][N] = 1;

        for (int j = N - 1; j >= 0; --j)
            grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
    }

    // print_grid();

    cout << "There are exactly " << grid[0][0] << " routes." << endl;

    return 0;
}

