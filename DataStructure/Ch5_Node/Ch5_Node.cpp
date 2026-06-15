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

    int result = list.Get(0);

    cout << result << endl;

    list.Insert(1,5);
    list.Print();

    list.Insert(1, 9);
    list.Print();
    list.Insert(3, 9);
    list.Print();
    list.Insert(3, 9);
    list.Print();
    list.Insert(2, 9);
    list.Print();


    //list.Erase(4);
    //list.Print();

    list.Remove(9);
    list.Print();
    
    list.Reverse();
    list.Print();


    return 0;
}
