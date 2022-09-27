#include <bits/stdc++.h>
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
class Linked_l
{
private:
    Node *head;

public:
    Linked_l()
    {
        head = nullptr;
    }
    void Push(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void display()
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
};
int main()
{
    Linked_l *l=new Linked_l;
    return 0;
}