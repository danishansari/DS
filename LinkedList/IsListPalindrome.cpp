
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

int isListPalindrome(Node *ptr1, Node *ptr2)
{
    int ret = 1;
    while(ptr1 and ptr2)
    {
        if (ptr1->data != ptr2->data)
        {
            ret = 0;
            break;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ret;
}

Node* getMidNode(Node *head)
{
    Node *slowPtr = head;
    Node *fastPtr = head;

    while (slowPtr && fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    return slowPtr;
}

void printList(Node *head)
{
    Node *iter = head;

    cout << "\nHEAD-->";
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

    printList(head);

    Node *midNode = getMidNode(head);
    
    reverseList(midNode);    

    if (isListPalindrome(head, midNode))
        cout << "Palindrome!!" << endl;
    else
        cout << "Not Palindrome!!" << endl;

    return 0;
}
