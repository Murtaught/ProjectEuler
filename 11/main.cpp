#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 20;
int grid[20][20];

int main()
{
    freopen("input.txt", "r", stdin);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &grid[i][j]);


    long M = -1;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (j + 3 < N)
            {
                long tmp = grid[i][j];
                tmp *= grid[i][j + 1];
                tmp *= grid[i][j + 2];
                tmp *= grid[i][j + 3];
                M = max(M, tmp);
            }

            if (i + 3 < N)
            {
                long tmp = grid[i][j];
                tmp *= grid[i + 1][j];
                tmp *= grid[i + 2][j];
                tmp *= grid[i + 3][j];
                M = max(M, tmp);
            }

            if ((j + 3 < N) && (i + 3 < N))
            {
                long tmp = grid[i][j];
                tmp *= grid[i + 1][j + 1];
                tmp *= grid[i + 2][j + 2];
                tmp *= grid[i + 3][j + 3];
                M = max(M, tmp);
            }

            if ((j - 3 >= 0) && (i + 3 < N))
            {
                long tmp = grid[i][j];
                tmp *= grid[i + 1][j - 1];
                tmp *= grid[i + 2][j - 2];
                tmp *= grid[i + 3][j - 3];
                M = max(M, tmp);
            }
        }

    printf("Maximum product is %ld.\n", M);

    return 0;
}

