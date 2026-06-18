#include "../shared/BinaryTree.h"
#include "Heap.h"
#include "../shared/BinarySearchTree.h"


using namespace std;

int main()
{
    //using Node = BinaryTree<int>::Node;

    //Node* n6 = new Node{ 6 , nullptr, nullptr };
    //Node* n5 = new Node{ 5 , n6, nullptr };
    //Node* n4 = new Node{ 4 , nullptr, nullptr };
    //Node* n3 = new Node{ 3 , nullptr, nullptr };
    //Node* n2 = new Node{ 2 , n3, n4 };
    //Node* n1 = new Node{ 1 , n2, n5 };

    //BinaryTree<int> tree(n1);
    //
    //tree.IterPostorder();

    //MinHeap<int> mh;

    //for (auto h : { 8,4,3,2,5,6 })
    //{
    //    mh.Push(h);
    //}

    //mh.print();

    //mh.Pop();
    //mh.print();

    using Node = BinarySearchTree<int, char>::Node;

    Node* Root = new Node;
    Root->item.key = 5;
    Root->item.value = 'A';

    BinarySearchTree<int, char> bst(Root);

    bst.Insert(4, 'B');
    bst.Insert(7, 'C');
    bst.Insert(8, 'D');
    bst.Insert(2, 'E');
    bst.Insert(1, 'F');
    bst.Insert(3, 'G');
    bst.Insert(5, 'H');

    bst.Print();

    bst.Inorder();

    //bst.Remove2(5);

    //cout << endl;

    //bst.Print();

    cout << endl;

    cout << bst.RecurGet(3) << endl;



    return 0;
}

