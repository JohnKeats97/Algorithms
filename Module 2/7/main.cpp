#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <cstring>
#include <stdio.h>



void inline writeInt(int var) {
    int tmpChar[16] = {0};
    int pos = 0;
    while (var != 0) {
        tmpChar[pos++] = var % 10 + '0';
        var /= 10;
    }
    while (pos != 0)
        putchar_unlocked(tmpChar[--pos]);
    putchar_unlocked(' ');
}

// Соревнование
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

// Первый QIsort
//int Partition( int* arr, int n )
//{
//    int pivot_index = n / 2;
//    std::swap( arr[0], arr[pivot_index] );
//    int pivot = arr[0];
//    int i = n - 1;
//    int j = n - 1;
//    while ( j > 0 ) {
//        if ( arr[j] >= pivot ) {
//            std::swap(arr[i], arr[j]);
//            --i;
//        }
//        --j;
//    }
//    std::swap( arr[0], arr[i] );
//    return i;
//}

//void QuickSort( int* a, int n ) {
//    int part = Partition( a, n );
//    if( part > 20 ) QuickSort( a, part );
//    if( part + 20 < n ) QuickSort( a + part + 1, n - ( part + 1 ) );
//}

//void QISort( int* a, int n ) {
//    QuickSort (a, n);
//    InsertionSort (a, n);
//}


//// QIsort на сдачу
//int Partition( int* arr, int left, int right )
//{
//    int pivot_index = rand() % (right - left + 1) + left;
//    std::swap( arr[left], arr[pivot_index] );
//    int pivot = arr[left];
//    int i = right;
//    int j = right;
//    while ( j > left ) {
//        if ( arr[j] >= pivot ) {
//            std::swap(arr[i], arr[j]);
//            --i;
//        }
//        --j;
//    }
//    std::swap( arr[left], arr[i] );
//    return i;
//}

//void InsertionSort( int* a, int n ) {
//    for( int i = 1; i < n; ++i ) {
//        int tmp = a[i];
//        int j = i - 1;
//        for( ; j >= 0 && tmp < a[j]; --j ) {
//            a[j + 1] = a[j];
//        }
//        a[j + 1] = tmp;
//    }
//}


//void QISort(int *arr, int l, int h) {
//    int stack[100000];
//    int top = -1;

//    stack[++top] = l;
//    stack[++top] = h;

//    while ( top >= 0 ) {
//        h = stack[top--];
//        l = stack[top--];

//        if (h - l <= 10) {
//            InsertionSort(arr + l, h - l + 1);
//            continue;
//        }

//        int p = Partition( arr, l, h );

//        if (p - 1 > l) {
//            stack[++top] = l;
//            stack[++top] = p - 1;
//        }

//        if (p + 1 < h) {
//            stack[++top] = p + 1;
//            stack[++top] = h;
//        }
//    }
//}



bool read_int_unlocked(int & out)
{
    int c = getchar_unlocked();
    int x = 0;
    int neg = 0;

    for (; !('0'<=c && c<='9') && c != '-'; c = getchar_unlocked())
    {
        if (c == EOF)
            return false;
    }
    if (c == '-')
    {
        neg = 1;
        c = getchar_unlocked();
    }
    if (c == EOF)
        return false;
    for (; '0' <= c && c <= '9' ; c = getchar_unlocked())
    {
        x = x*10 + c - '0';
    }
    out = neg ? -x : x;
    return true;
}




int main()
{
    int* arr = (int*) malloc(sizeof(int) * 25000000);
    int n = 0;
    while (read_int_unlocked(arr[n])) {
        n++;
    }

    LSD_sort (arr, n);

    for ( int i = 9; i < n; i+=10 ) {
        writeInt(arr[i]);
    }

    free(arr);

    return 0;
}

