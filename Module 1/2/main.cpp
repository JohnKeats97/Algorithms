#include <iostream>
#include <assert.h>


// Нода списка
struct Node{

    int num;
    struct Node* next;
    struct Node* prev;

};

//двусвязный кольцевой список
struct DoubleList{

    struct Node* head;
    struct Node* last;

    int count;

};

// Добавление в конец списка
void AddLast (DoubleList* List, int value)
{
    Node* node = (Node*) malloc (sizeof(Node));

    assert (node != NULL);

    (List->count)++;

    if (List->count==1)
    {
        node->num = value;
        node->next=NULL;
        node->prev=NULL;
        List->last = node;
        List->head=node;
    }
    else
    {
        node->num = value;
        node->next = NULL;
        node->prev=List->last;
        List->last->next=node;
        List->last = node;
    }

}

// Заполнение списка числами от 1 до n и закольцевание списка
void CreateList (DoubleList* Dlist, int n)
{
    Dlist->count = 0;
    Dlist->head = NULL;
    Dlist->last = NULL;

    for (int i = 1; i <= n; i++){
        AddLast (Dlist,i);
    }
    Dlist->head->prev=Dlist->last;
    Dlist->last->next=Dlist->head;
}

// Удаление ноды
void DeleteNode (Node* node, DoubleList* Dlist)
{
    // Переопределение начала и конца списка
    if (node == Dlist->head){
        Dlist->head = node->next;
    }
    if (node == Dlist->last){
        Dlist->last = node->prev;
    }

    node->next->prev = node->prev;

    node->prev->next = node->next;


    free(node);

}

// Возвращает номер оставшегося человека
int GetNumber (int n, int k)
{
    DoubleList* Dlist = (DoubleList*) malloc(sizeof(DoubleList));

    assert (Dlist != NULL);

    CreateList(Dlist,n);

    int i = 1;
    for (Node* node = Dlist->head; Dlist->count>1;){
        node = node->next;
        if (i%k == 0){
            DeleteNode(node->prev, Dlist);
            (Dlist->count)--;
        }
        i++;
    }
    i = Dlist->head->num;

    free(Dlist->head);
    free(Dlist);

    return i;
}


int main()
{
    int n = 0, k = 0;
    std::cin >> n >> k;

    assert (n > 0 && k > 0);

    n = GetNumber (n,k);

    std::cout << n;

    return 0;
}
