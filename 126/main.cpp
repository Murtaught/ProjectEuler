#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
using namespace std;
typedef unsigned int uint;

// Amount of cubes in layer N of cuboid with dimensions (n; m; k)
uint layer(uint n, uint m, uint k, uint N)
{
    // Finally derived this formula. HELL FREAKING YEAH!
    return 4*N*N + 4*N*(n + m + k - 3) + (2*(n*m + n*k + m*k) - 4*(n + m + k) + 8);
}

void user_mode()
{
    int n, m, k;
    cout << "Input cuboid dimensions (n ; m ; k): " << endl;
    cout << "  n = "; cin >> n;
    cout << "  m = "; cin >> m;
    cout << "  k = "; cin >> k;

    cout << "\nCuboid (" << n << " ; " << m << " ; " << k << "): \n";

    for (int N = 1; N <= 7; ++N)
        cout << "    N = " << N << ":  " << layer(n, m, k, N) << endl;

    cout << endl << layer(n, m, k, 1);
    for (int N = 2; N <= 15; ++N)
        cout << ", " << layer(n, m, k, N);

    cout << endl;
}

int main()
{
    user_mode();

    return 0;
}

