#include <bits/stdc++.h>
using namespace std;

// Find function with Path Compression
int find(int par[], int x)
{
    if (par[x] == x)
        return x;                      // If x is the parent of itself
    return par[x] = find(par, par[x]); // Path Compression
}

// Union function (Union by Rank or Size)
void unionSet(int par[], int x, int z)
{
    int rootX = find(par, x); // Find root of x
    int rootZ = find(par, z); // Find root of z

    if (rootX == rootZ)
        return;
    // Make one root parent of the other
    par[rootX] = rootZ;
}

int find(int A[], int X)
{
    if (A[X] == X)
        return X;
    return find(A, A[X]);
}
void unionSet(int A[], int X, int Z)
{
    int parentX = find(A, X);
    int parentZ = find(A, Z);
    if (parentX == parentZ)
        return;
    A[parentX] = parentZ;
}