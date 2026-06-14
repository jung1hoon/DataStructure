#include "Node.h"
#include "../shared/SinglyLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    SinglyLinkedList<int> list(1);

    list.pushfront(2);
    list.Print();

    list.pushback(3);
    list.Print();

    list.popfront();
    list.Print();



    return 0;
}
