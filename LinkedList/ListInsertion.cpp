
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
    while(iter)
    {
        cout << "[" << iter->data << "]-->";
        iter = iter->next;
    }
    cout << "NULL" << endl;
}

void insertNode(Node *&head, Node *newNode, int pos=0)
{
    cout << "Inserting new node: " << newNode->data << " at: " << pos << endl;

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
 
    int data = 1;
    int pos = 0;

    for (int i = 0; i < 5; i++)
    {
        Node *node = new Node();
        
        cout << "Enter a no and pos: ";
        cin >> data;
        cin >> pos;

        node->data = data;

        insertNode(head, node, pos);
        printList(head);
    }

    return 0;
}
