#include<iostream>
using namespace std;

class Stack
{
    private:

    int MAXIMUM_NUMBER_OF_ITEMS{10};
    int currentIndex = -1;
    int mainStack[10]{};


    public:

    Stack() = default;

    void push(int elementToBePushed);
    int pop();
    bool isEmpty();
    bool isFull();
    int peek();
    int count();
    void change(int element, int index);
    void display();
};

bool Stack::isFull()
{
    return(currentIndex == MAXIMUM_NUMBER_OF_ITEMS - 1);
}

bool Stack::isEmpty()
{
    return(currentIndex < 0);
}

int Stack::peek()
{
    return mainStack[currentIndex];
}

int Stack::count()
{
    return(currentIndex + 1);
}

void Stack::display()
{
    if(isEmpty())
    {
        cout << "Stack is empty\n";
        return;

    }

    cout << "Bottom of Stack -> ";

    for(int i = 0; i <= currentIndex; i++)
    {
        cout << mainStack[i] << " ";
    }

    cout << "End of Stack\n";
}

void Stack::push(int elementToBePushed)
{
    if(Stack::isFull())
    {
        cout << "Stack is Full\n";
        return;
    }

    ++currentIndex;
    mainStack[currentIndex] = elementToBePushed;
    
}

int Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack is Empty\n";
        
    }

    int temp = mainStack[currentIndex];
    --currentIndex;
    return temp;
}

void Stack::change(int element, int index)
{
    if((index >= 0) && (index < MAXIMUM_NUMBER_OF_ITEMS))
    {
        mainStack[index] = element;
        return;
    }
    cout << "Please Input Valid Index\n";
    return;

}

int main()
{
    Stack S;
    S.display();

    S.push(1);
    S.push(2);
    S.push(3);

    S.display();

    S.pop();
    S.display();

    S.pop();
    S.display();
    
    S.pop();
    S.display();

    return 0;
}