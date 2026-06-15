#include "Node.h"
#include "../shared/SinglyLinkedList.h"
#include "../shared/DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    DoublyLinkedList<int> list;

    list.pushfront(1);
    list.pushfront(2);
    list.pushfront(3);
    list.pushfront(4);
    list.pushfront(5);

    list.pushback(1);
    list.pushback(2);
    list.pushback(3);
    list.pushback(4);
    list.pushback(5);

    list.Remove(1);
    list.Print();
    list.popfront();

    std::cout << endl;

    list.Erase(list.Find_index(4));

    list.Print();

    list.Reverse();
    list.Print();

    return 0;
}
