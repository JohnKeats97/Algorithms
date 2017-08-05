#include <iostream>
#include <assert.h>

using namespace std;

void work (int n, long** D)
{
    for (int i = 0; i < n; i++){
        D[i][0] = 1;
        D[0][i] = 1;
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            if (j < i){
                D[i][j] = D[i-j-1][j] + D[i][j-1];
            }
            else if(i == j){
                D[i][j] = D[i][j-1] + 1;
            }
            else{
                D[i][j] = D[i][j-1];
            }
        }
    }
}


int main()
{
    int n = 0;
    std::cin >> n;
    assert (n > 0);
    long** D = new long* [n];
    for (int i = 0; i < n; i++){
        D[i] = new long [n];
    }
    work(n,D);
    std::cout << D[n-1][n-1];

    for (int i = 0; i < n; i++){
        delete[] D[i];
    }
    delete[] D;

    return 0;
}
