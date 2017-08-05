#include <assert.h>
#include <iostream>
#include <vector>
#include <time.h>
using std::vector;

// Разделение подмассива по опорному элементу. В качестве опорного берется случайный и меняется с left.
// left, right - границы подмассива. left включается, right не включается.
// Возвращает индекс опорного элемента.
int Partition( vector<int>& arr, int left, int right )
{
    assert( right > left );
    srand(time(0));
    int pivot_index = rand() % ((right - 1) - left + 1) + left;
    std::swap( arr[left], arr[pivot_index] );
    int pivot = arr[left];
    int i = right - 1;
    int j = right - 1;
    while ( j > left ) {
        if ( arr[j] >= pivot ) {
            std::swap(arr[i], arr[j]);
            --i;
        }
        --j;
    }
    std::swap( arr[left], arr[i] );
    return i;
}




// Поиск k-ой порядковой статистики.
int KStatistics( vector<int>& arr, int k )
{
    assert( k >= 0 );
    assert( k < static_cast<int>( arr.size() ) );

    int left = 0;
    int right = arr.size();
    while( true ) {
        int pivotPos = Partition( arr, left, right );
        if( pivotPos == k ) {
            return arr[k];
        } else if( pivotPos < k ) {
            left = pivotPos + 1;
        } else {
            right = pivotPos;
        }
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    int k = 0;
    std::cin >> k;
    vector<int> arr( n, 0 );
    for( int i = 0; i < n; ++i ) {
        std::cin >> arr[i];
    }

    std::cout << KStatistics( arr, k ) << std::endl;

    return 0;
}
