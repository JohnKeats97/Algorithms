#include <iostream>
#include <vector>

class heap
{
protected:
    std::vector<int> arr;
public:
    void SiftUp( int index );
    void SiftDown( int i );
    void BuildHeap( int n );
    bool arr_empty ();
};


class queue_priority : public heap
{
public:
    void InsertWithPriority ( int element );
    int PeekAtNext ();
    int GetMax ();
};

bool heap::arr_empty ()
{
    return !arr.empty();
}

// Проталкивание элемента наверх.
void heap::SiftUp( int index )
{
    while( index > 0 ) {
        int parent = ( index - 1 ) / 2;
        if( arr[index] <= arr[parent] )
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
    if( left < arr.size() && arr[left] > arr[i] )
        largest = left;
    if( right < arr.size() && arr[right] > arr[largest] )
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

// Добавление элемента.
void queue_priority::InsertWithPriority ( int element )
{
    arr.emplace_back(element);
    SiftUp( arr.size() - 1 );
}

int queue_priority::PeekAtNext ()
{
    return arr[0];
}

int queue_priority::GetMax ()
{
    int max = arr[0];
    std::swap(arr[0], arr[arr.size() - 1]);
    arr.pop_back();
    SiftDown ( 0 );
    return max;
}


int work ( queue_priority queue_p, int k )
{
    int answer = 0;
    if (queue_p.PeekAtNext() > k) {
        return answer;
    }
    std::vector<int> arr_apple;
    while (queue_p.arr_empty()) {
        int weight = 0;
        while (weight + queue_p.PeekAtNext() <= k && queue_p.arr_empty()) {
            arr_apple.push_back(queue_p.GetMax());
            weight += arr_apple[arr_apple.size() - 1];
        }
        answer++;
        while (!arr_apple.empty()) {
            if (arr_apple[arr_apple.size() - 1] == 1) {
                arr_apple.pop_back();
            }
            else if (arr_apple[arr_apple.size() - 1] % 2 == 0) {
                queue_p.InsertWithPriority (arr_apple[arr_apple.size() - 1] / 2);
                arr_apple.pop_back();
            }
            else {
                int push = arr_apple[arr_apple.size() - 1] / 2;
                queue_p.InsertWithPriority (push);
                arr_apple.pop_back();
            }
        }
    }
    return answer;
}

int main()
{
    int n = 0;
    std::cin >> n;
    queue_priority queue_p;

    int value;
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        queue_p.InsertWithPriority (value);
    }

    int k = 0;
    std::cin >> k;

    //BuildHeap (arr, n);

    while (queue_p.PeekAtNext() > k){
        queue_p.GetMax();
    }

    int answer = work (queue_p, k);

    std::cout << answer;

    return 0;
}
