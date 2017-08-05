#include <iostream>
#include <algorithm>
#include <assert.h>

struct period {
    int come_in;
    int come_out;
};

class heap
{
public:
    period* arr;
    int count;
    void SiftUp( int index );
    void SiftDown( int i );
    void BuildHeap( int n );
    bool arr_empty ();
};

bool heap::arr_empty ()
{
    return count;
}

// Проталкивание элемента наверх.
void heap::SiftUp( int index )
{
    while( index > 0 ) {
        int parent = ( index - 1 ) / 2;
        if( arr[index].come_out <= arr[parent].come_out )
            return;
        std::swap( arr[index], arr[parent] );
        index = parent;
    }
}

// Проталкивание элемента вниз.
void heap::SiftDown( int i )
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // Ищем большего сына, если такой есть.
    int largest = i;
    if( left < count && arr[left].come_out > arr[i].come_out )
        largest = left;
    if( right < count && arr[right].come_out > arr[largest].come_out )
        largest = right;
    // Если больший сын есть, то проталкиваем корень в него.
    if( largest != i ) {
        std::swap( arr[i], arr[largest] );
        SiftDown( largest );
    }
}

// Построение кучи.
void heap::BuildHeap( int n )
{
    for ( int i = n / 2 - 1; i >= 0; --i) {
        SiftDown( i );
    }
}


bool cmp (period a, period b) {
    if (a.come_out == b.come_out){
        return a.come_in < b.come_in;
    }
    else {
        return a.come_out < b.come_out;
    }
    return true;
}

int work (heap table, int count) {

    int answer = 2;
    int first =  table.arr[0].come_out - 1;
    int second = table.arr[0].come_out;
    for ( int i = 0; i < count; ++i ) {

        if (!(table.arr[i].come_out >= first && table.arr[i].come_in <= first))
        {
            answer++;
            first =  table.arr[i].come_out - (second == table.arr[i].come_out);
        }

        if (!(table.arr[i].come_out >= second && table.arr[i].come_in <= second))
        {
            answer++;
            second =  table.arr[i].come_out - (first == table.arr[i].come_out);
        }

    }

    return answer;

}

void HeapSort(heap table, int n )
{
    table.BuildHeap( table.count );
    while( table.count > 1 ) {
        std::swap( table.arr[0], table.arr[table.count - 1] );
        --(table.count);
        table.SiftDown( 0 );
    }
}

int main()
{
    int count = 0;
    std::cin >> count;
    assert (count > 0);
    heap table;

    table.count = count;
    table.arr = new period [count];

    for ( int i = 0; i < count; ++i ) {
        std::cin >> table.arr[i].come_in >> table.arr[i].come_out;
    }

    HeapSort (table, count);

    int answer = work(table, count);

    std::cout << answer;

    delete[] table.arr;

    return 0;
}
