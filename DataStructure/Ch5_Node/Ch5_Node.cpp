#include "Node.h"
#include <iostream>

using namespace std;

int main()
{
    Node* first = new Node;

    Node* second = new Node;

    Node* third = new Node;

    first->next = second;
    second->next = third;

    Node* cur = first;

    for (int i = 1; i <= 3; i++)
    {    
        if (cur != nullptr)
        {
            SetItem(cur, i);
            cur = cur->next;
        }
    }


    Recurprint(first);

    std::cout << std::endl;

    Iterprint(first);

    std::cout << std::endl;

    delete_(first);

    return 0;
}
