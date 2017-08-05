#include <iostream>
#include <algorithm>
#include <cstdio>

struct man{
    int weight;
    int power;
};

// Сортировка массива по возрастанию.
bool cmp(struct man a, struct man b) {
    return ( a.power < b.power );
}

int work (int count, struct man* human)
{
    int CountMan = 0;
    int WeightTower = 0;

    for (int i = 0; i < count; i++){
        // Если Атлет способен поднять всех предыдущих, то прибавляем его
        if (human[i].power >= WeightTower){ // if (human[i].power > WeightTower){
            CountMan++;
            WeightTower += human[i].weight;
        }
    }

    return CountMan;
}

int main()
{
    struct man* human = new struct man [100000];

    int count = 0;
    // Пока не конец потока.
    while (!feof(stdin)){
        std::cin >> human[count].weight >> human[count].power;
        count++;
    }

    // Сортируем по силе.
    std::sort(human, human + count, cmp);

    int answer = work(count, human);
    std::cout << answer;

    delete[] human;

    return 0;
}
