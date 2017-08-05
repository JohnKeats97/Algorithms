#include <iostream>
#include <assert.h>


int GetPrimes(int* prime, int n)
{
    assert(n > 1);

    int count_arr = 0;

    // избавляемся от делимости на 2
    while (n % 2 == 0){
        prime[count_arr++] = 2;
        n /= 2;
    }
    // проверяем нечетные числа
    int i = 3;
    while (n != 1){
        if (n % i == 0){
            prime[count_arr++] = i;
            n /= i;
        }
        else{
            i += 2;
        }
    }

    return count_arr;
}

int main()
{
    int n = 0;
    std::cin >> n;

    int* prime = new int[n];

    int count_arr = GetPrimes(prime, n);

    for (int i = 0; i < count_arr; i++){
        std::cout << prime[i] << " ";
    }

    delete[] prime;

    return 0;
}
