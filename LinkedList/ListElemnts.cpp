
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

int countListElements(Node *node, int count)
{
    if (node)
    {  
        count ++;
        node = node->next;
        count = countListElements(node, count);
    }

    return count;
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
    
        printList(head);
    }
    
    int numElem = countListElements(head, 0);    
    cout << "No of elements in the list = " << numElem << endl;
    printList(head);

    return 0;
}
