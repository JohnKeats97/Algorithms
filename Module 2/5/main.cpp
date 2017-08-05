#include <iostream>
#include <algorithm>
#include <cstring>

int get_byte_by_index( int value, int byte ) {
    return (value >> (8 * byte)) & 255;
}

void CountingSort ( int *arr, int byte, int n )
{
    int* arr2 = (int*) malloc (sizeof(int) * n);
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
    memcpy(arr, arr2, sizeof(int) * n);

    free(arr2);
}

void LSD_sort ( int *arr, int n )
{
    for( int i = 0; i < sizeof(int); ++i ) {
        CountingSort( arr, i, n );
    }
}


void Merge(const int* a, int a_len, const int* b, int b_len, int* out) {
    int i = 0;
    int j = 0;

    for (; i < a_len && j < b_len;) {
        if (a[i] < b[j]) {
            out[i + j] = a[i];
            ++i;
        } else {
            out[i + j] = b[j];
            ++j;
        }
    }
    if (i == a_len) {
        for (; j < b_len; ++j) {
            out[i + j] = b[j];
        }
    } else if (j == b_len) {
        for (; i < a_len; ++i) {
            out[i + j] = a[i];
        }
    }
}

int main() {
    int count, k;
    std::cin >> count >> k;

    int* data = new int[2*k];
    int i = 0;
    while (i < count && i < k) {
        std::cin >> data[i++];
    }
    LSD_sort(data, i);
    while (i < count) {
        int j = k;
        for ( ;i < count && j < 2*k; j++) {
            std::cin >> data[j];
            i++;
        }
        LSD_sort(data+k, j-k);
        int* c = new int [2*k];
        Merge(data, k, data+k, j-k, c);
        memcpy(data, c, sizeof(int) * j);
        delete[] c;

        if (i == count) {
            for (int z = 0; z < j; z++) {
                std::cout << data[z] << " ";
            }
        }
        else {
            for (int z = 0; z < k; z++) {
                std::cout << data[z] << " ";
            }
            memcpy(data, data+k, sizeof(int) * k);
        }

    }

    delete[] data;

    return 0;
}

