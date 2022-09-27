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
class Stack{
    Node *head;
    public:
    Stack(){
        head=nullptr;
    }
    bool isempty(){
        if(head==nullptr){
            return true;
        }
        return false;
    }
    void Push(int val){
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }
    int pop(){
        if(isempty()){
            return -1;
        }
        else{
            int n=head->data;
            head=head->next;
            return n;
        }
    }
};
int main()
{
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
    return 0;
}