#include "../shared/BinaryTree.h"

using namespace std;

int main()
{
    using Node = BinaryTree<int>::Node;

    Node* n6 = new Node{ 6 , nullptr, nullptr };
    Node* n5 = new Node{ 5 , n6, nullptr };
    Node* n4 = new Node{ 4 , nullptr, nullptr };
    Node* n3 = new Node{ 3 , nullptr, nullptr };
    Node* n2 = new Node{ 2 , n3, n4 };
    Node* n1 = new Node{ 1 , n2, n5 };

    BinaryTree<int> tree(n1);
    
    tree.IterInorder();

    //cout << tree.Sum() << endl;

    return 0;
}

