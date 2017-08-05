#include <iostream>
#include <cstring>
#include <assert.h>

class StackOnArray {
public:
    StackOnArray(int n);
    ~StackOnArray();

    // Добавление элемента в стек.
    void push_stack(int value);
    // Извлечение элемента из стека.
    char pop_stack();
    // Размер стека
    int GetCount() const;

private:
    char* stack;
    int count;
};

StackOnArray::StackOnArray(int n)
{
    stack = new char [n];
    count = 0;
}

StackOnArray::~StackOnArray()
{
    delete[] stack;
}

void StackOnArray::push_stack(int value)
{
    stack[count++] = value;
}

char StackOnArray::pop_stack()
{
    return stack[--count];
}

int StackOnArray::GetCount() const
{
    return count;
}

// 1 если скобки открываются
int TryInput (char value)
{
    return (value == '[' || value == '(' || value == '{') ? 1 : 0;
}

// Проверка на соответствие скобок из стека и закрывающей ее из input
int TryPop (char a, char b)
{
    return (a == '[' && b == ']' ||
            a == '(' && b == ')' ||
            a == '{' && b == '}') ? 1 : 0;
}

// Подбор открывающей скобки
char OpenBrace (char value)
{
    if (value == ')'){
        return '(';
    }
    if (value == '}'){
        return '{';
    }
    if (value == ']'){
        return '[';
    }
}

// Подбор закрывающей скобки
char CloseBrace (char value)
{
    if (value == '('){
        return ')';
    }
    if (value == '{'){
        return '}';
    }
    if (value == '['){
        return ']';
    }
}

std::string GetString (const std::string& input)
{
    std::string ERROR = "IMPOSSIBLE";
    int LenInput = input.length();
    StackOnArray StackOpen (LenInput);
    StackOnArray StackClose (LenInput);

    for (int i = 0; i < LenInput; i++){
        // Скобки открываются.
        if (TryInput(input[i]) == 1){
            StackOpen.push_stack(input[i]);
        }
        // Скобки закрываются.
        else{
            // Размер стека с открывающимися скобками равен 0.
            if (StackOpen.GetCount() == 0){
                StackClose.push_stack(input[i]);
            }
            else{
                int value = StackOpen.pop_stack();
                // Проверка на соответствие открывающейся скобки из списка и нашей закрывающейся,
                                                              // если они не подходят, то ошибка.
                if (TryPop (value, input[i]) == 0){
                    return ERROR;
                }
            }
        }
    }
    // Дописываем открывающиеся скобки в начало
    std::string Open_Brace = "";
    while (StackClose.GetCount() != 0){
        Open_Brace += OpenBrace(StackClose.pop_stack());
    }
    // Дописываем закрывающиеся скобки в конец
    std::string Close_Brace = "";
    while (StackOpen.GetCount() != 0){
        Close_Brace += CloseBrace(StackOpen.pop_stack());
    }

    return Open_Brace + input + Close_Brace;
}

int main()
{
    std::string input;
    std::cin >> input;

    assert (!input.empty());

    std::string output = GetString(input); // получение последовательности
    std::cout << output;

    return 0;
}
