#include <iostream>

using namespace std;

/**
 * Singly linked list is a data structure made of nodes with self referential structures.
 * Each of these nodes contain data and refrence to next list nodes
 * Only the reference node [head] to the first list node is required to access the whole linked list.
 * The last node in the list points to nothing so it stores NULL in that part.
 *  * */
struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head;

public:
    linked_list()
    {
        head = NULL;
    }

    void add_node(int n)
    {
        node *temp = new node;
        temp->data = n;
        temp->next = head;
        head = temp;
    }

    void print()
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.print();
    return 0;
}
