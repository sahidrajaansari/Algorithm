#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class Queue{
    Node *head;
    public:
    Queue(){
        head=nullptr;
    }
    bool isempty(){
        if(head==nullptr){
            return true;
        }
        return false;
    }
    void enque(int val)
    {
        if (head == NULL)
        {
            head=new Node(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    int deque(){
        if(isempty()){
            return -1;
        }
        else{
            int n=head->data;
            head=head->next;
            return n;
        }
    }
    void display(){
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            if(temp->next!=nullptr){
                cout<<",";
            }
            temp = temp->next;
        }
    }
    
};
int main()
{
    Queue q;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    // q.display();
    cout<<q.deque();
    cout<<q.deque();
    cout<<q.deque();
    cout<<q.deque();
    cout<<q.deque();
    return 0;
}