#include <iostream>
#include <vector>
#include <cstring>

int get_byte_by_index( long long value, int byte ) {
    return (value >> (8 * byte)) & 255;
}

void CountingSort ( long long *arr, int byte, int n )
{
    long long* arr2 = new long long [n];
    int c[256] = {0};

    for (int j = 0; j < n; ++j) {
        c[get_byte_by_index(arr[j], byte)]++;
    }
    for (int j = 1; j < 256; ++j) {
        c[j] += c[j - 1];
    }
    for (int j = n - 1; j >= 0; --j) {
        arr2[--c[get_byte_by_index(arr[j], byte)]] = arr[j];
    }
    std::memcpy(arr, arr2, sizeof(long long) * n);

    delete[] arr2;
}

void LSD_sort ( long long *arr, int n )
{
    for( int i = 0; i < sizeof(long long); ++i ) {
        CountingSort( arr, i, n );
    }
}

int main()
{
    int count = 0;
    std::cin >> count;
    long long* arr = new long long [count];

    for( int i = 0; i < count; ++i ) {
        std::cin >> arr[i];
    }

    LSD_sort (arr, count);

    for( int i = 0; i < count; ++i ) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}


