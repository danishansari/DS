
/**
 * Description:
 *
 * Author: Md Danish
 *
 * Date: 
**/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val=0)
    {
        data = val;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *iter = head;

    cout << "HEAD-->";
    while (iter)
    {
        cout << "[" << iter->data << "]-->";
        iter = iter->next;
    }
    cout << "NULL" << endl;
}

void reverseList(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;

    while (curr)
    {  
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

void insertNode(Node *&head, Node *newNode, int pos=0)
{
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *iter = head;
        for (int i = 1; (i < pos); i++)
        {
            if (!iter)
                break;
            
            iter = iter->next;
        }

        if (iter)
        {
            newNode->next = iter->next;
            iter->next = newNode;
        }
        else
            cout << "error: index out of bound" << endl;
    }
}

int main()
{
    Node *head = NULL; 
 
    int data = 0;
    int pos = 0;
    char ch = 'a';

    while (true)
    { 
        cout << "Enter a no and pos(pos = -1 to delete): ";
        cin >> ch;

        if (ch == 'q')
            break;

        data = int(ch)-48;

        cin >> pos;

        if (pos >= 0)
        {
            Node *node = new Node();
            node->data = data;
            insertNode(head, node, pos);
        }
    
    }
    cout << endl;
    printList(head);
    reverseList(head);
    //printList(head);

    Node *iter = head;

    Node *head1 = NULL;

    int c = 1;

    while (iter)
    {
        int data = iter->data + c;

        if (data > 9)
        {
            c = 1;
            data = 0;
        }
        else
            c = 0;

        Node *node = new Node();
        node->data = data;

        insertNode(head1, node, 0);

        iter = iter->next;
    }

    if (c == 1)
    {
        Node *node = new Node();
        node->data = 1;
        insertNode(head1, node, 0);
    }
    
    printList(head1);

    return 0;
}
