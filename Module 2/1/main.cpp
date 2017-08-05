#include <iostream>
#include <string>
#include <algorithm>

// Возвращает true когда первое слово меньше второго
bool cmp (std::string first, std::string second)
{
    for (int i = 0; i < first.size() && i < second.size(); i++) {
        if (first[i] < second[i]) {
            return true;
        }
        else if (first[i] > second[i]) {
            return false;
        }
    }
    return ( first.size() < second.size() ) ? true : false;
}

void InsertionSort( std::string* a, size_t n ) {
    for( int i = 1; i < n; ++i ) {
        std::string tmp = a[i];
        int j = i - 1;
        for(; j >= 0 && cmp(tmp, a[j]); --j ) {
            a[j + 1] = a[j];
        }
        a[j + 1] = tmp;
    }
}

int main()
{
    size_t count_string;

    std::cin >> count_string;

    std::string* string_array = new std::string [count_string];

    for ( int i = 0; i < count_string; ++i ) {
        std::cin >> string_array[i];
    }

    InsertionSort (string_array, count_string);

    for ( int i = 0; i < count_string; ++i ) {
        std::cout << string_array[i] << "\n";
    }

    delete[] string_array;

    return 0;
}
