#include <iostream>

using namespace std;

int BinarySearch( int* arr, int count, int element, int first, int last )
{
    while( first < last ) {
        int mid = ( first + last ) / 2;
        if( element <= arr[mid] ){
            last = mid;
        }
        else{
            first = mid + 1;
        }
    }
    return ( first == count ) ? -1 : first;
}


void GetArr (int n, int m, int *A, int* B)
{
    for (int i = 0; i<n; i++){
        std::cin >> A[i];
    }

    for (int i = 0; i<m; i++){
        std::cin >> B[i];
    }
}

void FindIndex (int* A, int n, int value, int& FirstIndex, int& LastIndex)
{
    while (true){
        if (A[LastIndex]>=value){
            return;
        }
        else{
            FirstIndex = LastIndex;
            LastIndex *= 2;
            if (LastIndex > n-1){
                LastIndex = n;
                return;
            }
        }
    }
}

int main()
{

    int n = 0, m = 0;
    std::cin >> n >> m;

    int* A = new int [n];
    int* B = new int [m];

    GetArr (n,m,A,B);

    for (int i = 0; i<m; i++){
        int FirstIndex = 0;
        int LastIndex = 1;
        FindIndex (A, n, B[i], FirstIndex, LastIndex);
        int IndexElement = BinarySearch (A, n, B[i], FirstIndex, LastIndex);
        if (IndexElement >= 0){
            std::cout << IndexElement << " ";
        }
        else{
            std::cout << n << " ";
        }
    }

    delete[] A;
    delete[] B;

    return 0;
}
