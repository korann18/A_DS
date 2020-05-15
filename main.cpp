#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

#define NMAX 2 * 11000000

using namespace std;

int A[NMAX];
int B[NMAX];

int comp1 (const void * a, const void * b)
{
    return (*(int*)b -  *(int*)a);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];

    qsort(A, n, sizeof(int), comp1);

    int j = 0;
    for(int i = 0; i < n; i++){
        if(A[i] == A[i + 1] + 1 || A[i] == A[i + 1]){
            B[j] = min(A[i], A[i + 1]);
            j++;
            i++;
        }
    }

    unsigned long long sum = 0;

    for(int i = 0; i < n; i += 2){
        sum += (unsigned long long)B[i] * B[i + 1];
    }


    return cout << sum, 0;
}