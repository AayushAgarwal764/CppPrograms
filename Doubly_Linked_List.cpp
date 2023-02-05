//INCOMPLETE

#include<iostream>
using namespace std;

class Node
{
    public:
    int m_data{};
    Node* m_next{};
    Node* m_prev{};

    Node(int data = 0):m_data{data}
    {

    }
};

void appendAtTheEnd(Node** headptr, int newData)
{
    Node* newNode = new Node(newData);
    Node* temp{};
    if(*headptr == NULL)
    {
        *headptr = newNode;
        newNode->m_prev = NULL;
        newNode->m_next = NULL;
        return;
    }

    for(temp = *headptr; temp -> m_next != NULL; temp = temp -> m_next)
    {

    }
    temp -> m_next = newNode;
    newNode ->m_next = NULL;
    newNode ->m_prev = temp; 
}

void appendAtTheBeginning(Node** headptr, int newData)
{
    Node* newNode = new Node(newData);
    Node* temp = *headptr;
    *headptr = newNode;
    newNode ->m_next = temp; 
    newNode->m_prev = NULL;
}

void appendAfterNode(Node** headptr, int newData, int dataAfterWhichToAppend)
{
    Node* newNode = new Node(newData);
    
    Node* temp = *headptr;
    for(;temp != NULL; temp = temp->m_next)
    {
        if(temp ->m_data == dataAfterWhichToAppend)
        {
            break;
        }
    }
    if(temp != NULL)
    {
        Node* tempNew = temp -> m_next;
        temp -> m_next = newNode;
        newNode -> m_next = tempNew;
        newNode->m_prev = temp;
    }
    else
    {
        cout << "Element After which to be Appended Not Found\n";
    }
}

void deleteNode(Node** headptr, int dataToBeDeleted)
{
    Node* prev{};
    prev = *headptr;

    if(prev->m_data == dataToBeDeleted)
    {
        Node* temp = *headptr;
        *headptr = prev->m_next;
        temp->m_next = NULL;
        temp->m_prev = NULL;
        return;
    }

    for(prev = *headptr; prev -> m_next != NULL && prev -> m_next ->m_data != dataToBeDeleted; prev = prev -> m_next)
    {
        
    }
    
    Node* temp = prev -> m_next;
    prev -> m_next = temp -> m_next;
    temp ->m_prev = prev;
    temp -> m_next = NULL;
    

}

void updateNode(Node** headptr, int dataToBeUpdated, int newData)
{
    Node* temp = *headptr;
    while(temp != NULL)
    {
        if(temp ->m_data == dataToBeUpdated)
        {
            temp ->m_data = newData;
            break;
        }
        temp = temp->m_next;
    }
    if(temp == NULL)
    {
        cout << "Data to be updated Not Found\n";
    }

}

void printLinkedList(Node** headptr)
{
    Node* temp = *headptr;
    cout << "Head\n'\n'--";

    for(;temp != NULL; temp = temp -> m_next)
    {
        cout << temp ->m_data << " --> ";
    }
    cout << "NULL\n\n";
}

int main()
{
    Node* head{};
    appendAtTheEnd(&head, 10);
    printLinkedList(&head);
    appendAtTheBeginning(&head, 20);
    printLinkedList(&head);
    appendAfterNode(&head, 30, 20);
    printLinkedList(&head);
    updateNode(&head, 30, 40);
    printLinkedList(&head);
    deleteNode(&head, 10);
    printLinkedList(&head);

    return 0;

}