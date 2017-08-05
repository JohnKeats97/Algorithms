#include <iostream>
#include <assert.h>

int try_head_tail (int head,int tail);
int work (int n);

class deque{
private:
    int* array;
    int max_size;
    int size;
    int head;
    int tail;
public:
    deque();
    ~deque();

    void push_front (int b);
    void push_back (int b);
    int pop_front ();
    int pop_back ();
    void grow();
};

int try_head_tail (int head,int tail)
{
    return (head == tail) ? 0 : 1;
}

void deque::push_front (int b)
{
    // Проверка на окончание дека.
    if (try_head_tail(head, tail) == 0){
        grow();
    }
    array[head] = b;
    (size)++;
    if (head == 0){
        head = max_size-1;
    }
    else{
        (head)--;
    }
}

int deque::pop_front ()
{
    // Пустая структура, позвращаем -1.
    if (size == 0){
        return -1;
    }
    // Если head в конце дека, то переносим его в начало.
    if (head == max_size-1){
        head = 0;
    }
    else{
        (head)++;
    }
    (size)--;
    return array[head];
}

void deque::push_back (int b)
{
    // Проверка на окончание дека.
    if (try_head_tail(head, tail) == 0){
        grow();
    }
    array[tail] = b;
    (size)++;
    if (tail == max_size-1){
        tail = 0;
    }
    else{
        (tail)++;
    }
}

int deque::pop_back ()
{
    // Пустая структура, позвращаем -1.
    if (size == 0){
        return -1;
    }
    // Если tail в начале дека, то переносим его в конец.
    if (tail == 0){
        tail = max_size-1;
    }
    else{
        (tail)--;
    }
    (size)--;
    return array[tail];
}

deque::deque ()
{
    max_size = 1;
    size = 0;
    array = new int [max_size];
    head = int (max_size/2);
    tail = head;
}

void deque::grow()
{

    int new_max_size = max_size * 2;
    int* new_array = new int [new_max_size];

    for (int i = 1; i<max_size; i++){
        int index = head+i;
        if (index >= max_size){
            index = index - max_size;
        }
        new_array[i-1] =  array[index];
    }

    head = new_max_size - 1;
    tail = size;
    max_size = new_max_size;

    delete[] array;
    array = NULL;
    array = new_array;
}

deque::~deque()
{
    delete [] array;
}

int work (int n)
{
    deque deq;

    int a = 0, b = 0, result = 0;

    for (int i = 0; i<n; i++){
        std::cin >> a >> b;
        switch(a)
        {
            case (1):
            {
                deq.push_front (b);
                break;
            }
            case (2):
            {

                result = deq.pop_front ();
                if (result != b){
                    return -1;
                }
                break;
            }
            case (3):
            {
                deq.push_back (b);
                break;
            }
            case (4):
            {
                result = deq.pop_back ();
                if (result != b){
                    return -1;
                }
                break;
            }
            default:
                assert ( false );
        }
    }

    return 1;
}

int main()
{
    int n = 0;
    std::cin >> n;
    int result = work(n);

    if (result == 1){
        std::cout << "YES";
    }
    else{
        std::cout << "NO";
    }

    return 0;
}


