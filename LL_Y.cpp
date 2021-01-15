#include <iostream>
using namespace std;

class node
{
public:
    int key, data;
    node *next;

    node()
    {
        key = 0, data = 0;
        next = NULL;
    }
    node(int k, int d)
    {
        key = k, data = d;
    }
};

class LinkedList
{
public:
    node *head;

    LinkedList()
    {
        head = nullptr;
    }
    LinkedList(node *n)
    {
        head = n;
    }
    // 1. Check if node exists using key value
    node *NodeExists(int k)
    {
        node *temp = NULL;
        node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // 2. Append a node to the list
    // At the end always
    void appendnode(node *n)
    {

        // n->key = k;
        // n->data = d;
        n->next = NULL;
        if (NodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value" << n->key << " , append node with some other value." << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended" << endl;
            }
            else
            {
                node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node Appended" << endl;
            }
        }
    }
    // 3. Prepend Node: add node at beginning
    void prependnode(node *n)
    {
        // n->key = k;
        if (NodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value" << n->key << " , append node with some other key value." << endl;
        }
        else
        {
            n->next = head;
            // n->data = d;
            head = n;
            cout << "Node Prepended" << endl;
        }
    }
    // 4. Insert a node after a node
    void insertnode_after(int k, node *n)
    {
        node *ptr = NodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exits with key value" << k << endl;
        }
        else
        {
            if (NodeExists(n->key) != NULL)
            {
                cout << "Node already exists with key value" << n->key << " , add node with some other key value." << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node Inserted" << endl;
            }
        }
    }
    // 5. Delete node by unique key
    void deleteNode_byKey(int k)
    {
        if (head == NULL)
        {
            cout << "Linked List already empty, can't delete" << endl;
        }
        else
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node unlinked with key value: " << k << endl;
            }
            else
            {
                node *temp = NULL;
                node *prev = head;
                node *curr = head->next;
                while (curr != NULL)
                {
                    if (curr->key == k)
                    {
                        temp = curr;
                        curr = NULL;
                    }
                    else
                    {
                        prev = curr;
                        curr = curr->next;
                    }
                }
                if (temp != NULL)
                {
                    prev->next = temp->next;
                    cout << "Node unlinked with key value: " << k << endl;
                }
                else
                {
                    cout << "Node doesn't exists with key value: " << k << endl;
                }
            }
        }
    }
    // 6. Update Node
    void updatenode_bykey(int k, int d)
    {
        node *ptr = NodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node Data updated successfully" << endl;
        }
        else
        {
            cout << "Node doesn't exist with key value: " << k << endl;
        }
    }
    // 7. Printing list
    void print_list()
    {
        if (head == NULL)
        {
            cout << "No nodes in Linked List";
        }
        else
        {
            cout << endl
                 << "Linked List values: " << endl;
            node *temp = head;

            while (temp != NULL)
            {
                cout << endl
                     << "Key: " << temp->key << "  Data: " << temp->data;
                temp = temp->next;
            }
        }
    }
};

int main()
{

    LinkedList l1;
    node *n1 = new node(1, 34);
    node *n2 = new node(2, 66);
    node *n4 = new node(3, 34);
    node *n3 = new node(-67, 7);
    // node *n5 = new node();
    l1.prependnode(n1);
    l1.appendnode(n2);
    l1.appendnode(n4);
    l1.insertnode_after(3, n3);
    // l1.deleteNode_byKey(-67);
    l1.updatenode_bykey(-67, 90);
    l1.print_list();

    return 0;
}
