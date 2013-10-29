#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned long long int uint64;

typedef vector< vector<uint64> > Triangle;

uint64& left(Triangle &tri, int row, int column)
{
    return tri[row + 1][column];
}

uint64& right(Triangle &tri, int row, int column)
{
    return tri[row + 1][column + 1];
}

void read_triangle(Triangle &tri, ifstream &in)
{
    int row = 1;

    while ( in )
    {
        tri.resize(row);
        tri[row - 1].resize(row);

        for (int i = 0; i < row; ++i)
            in >> tri[row - 1][i];

        // we have read a row
        ++row;
    }

    tri.pop_back();
}

void solve(const char *filename)
{
    ifstream in(filename);

    Triangle tri;
    read_triangle(tri, in);

    for (int i = tri.size() - 2; i >= 0; --i)
    {
        for (int j = 0; j < int(tri[i].size()); ++j)
            tri[i][j] += max(left(tri, i, j), right(tri, i, j));
    }

    cout << "Answer: " << tri[0][0] << endl;
}

int main()
{
    solve("input1.txt");

    return 0;
}

