#include<iostream>
using namespace std;

class Queue
{
    private:

    int MAXIMUM_NUMBER_OF_ITEMS{5};
    int beginningIndex = -1;
    int currentIndex = -1;
    int mainQueue[5]{};


    public:

    Queue() = default;

    void enqueue(int element);
    int dequeue();
    void moveLeft();
    bool isEmpty();
    bool isFull();
    int peek();
    int count();
    //void change(int element, int index);
    void display();
};

bool Queue::isFull()
{
    return((beginningIndex == 0) && (currentIndex == MAXIMUM_NUMBER_OF_ITEMS - 1));
}

bool Queue::isEmpty()
{
    return((beginningIndex == -1) && (currentIndex == -1));
}

int Queue::peek()
{
    return mainQueue[currentIndex];
}

int Queue::count()
{
    return(currentIndex - beginningIndex + 1);
}

void Queue::display()
{
    if(isEmpty())
    {
        cout << "Queue is empty\n";
        return;

    }

    cout << "Front -> ";

    for(int i = 0; i < MAXIMUM_NUMBER_OF_ITEMS; i++)
    {
        cout << mainQueue[i] << " -> ";
    }

    cout << "Rear\n";
}

void Queue::enqueue(int element)
{
    if(isFull())
    {
        cout << "Queue is Full\n";
        return;
    }
    if(beginningIndex == -1)
    {
        ++beginningIndex;
    }
    currentIndex = (currentIndex + 1) % MAXIMUM_NUMBER_OF_ITEMS;
    mainQueue[currentIndex] = element;
    
}

/*
void Queue::moveLeft()
{
    for(int i = 1; i <= currentIndex; i++)
    {
        mainQueue[i-1] = mainQueue[i];
    }
    if(beginningIndex == currentIndex)
    {
        --beginningIndex;
    }
    --currentIndex;
}
*/

int Queue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is Empty\n";
        
    }
    int temp = mainQueue[beginningIndex];
    mainQueue[beginningIndex] = 0;


    beginningIndex = (beginningIndex+1) % MAXIMUM_NUMBER_OF_ITEMS;
    
    return temp;
    
}

/* void Queue::change(int element, int index)
{
    if((index >= 0) && (index < MAXIMUM_NUMBER_OF_ITEMS))
    {
        mainQueue[index] = element;
        return;
    }
    cout << "Please Input Valid Index\n";
    return;

} */

int main()
{
    Queue S;
    S.display();

    S.enqueue(1);
    S.enqueue(2);
    S.enqueue(3);

    S.display();

    S.dequeue();
    S.display();

    S.dequeue();
    S.display();
    
    S.dequeue();
    S.display();

    return 0;
}