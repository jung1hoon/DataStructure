#include "AdjMat.h"
#include "AdjList.h"

using namespace std;

int main()
{
    AdjMat<int> g(6);
    AdjList<int> g2(6);

    g.InsertVertex(0);
    g.InsertVertex(1);
    g.InsertVertex(2);
    g.InsertVertex(3);
    g.InsertVertex(4);
    g.InsertVertex(5);

    g.InsertEdge(0, 1);     g.InsertEdge(1, 0);
    g.InsertEdge(0, 2);     g.InsertEdge(2, 0);
    g.InsertEdge(1, 3);     g.InsertEdge(3, 1);
    g.InsertEdge(1, 5);     g.InsertEdge(5, 1);
    g.InsertEdge(2, 4);     g.InsertEdge(4, 2);
    g.InsertEdge(2, 5);     g.InsertEdge(5, 2);
    g.InsertEdge(3, 4);     g.InsertEdge(4, 3);

    g.ResetVisited();

    g2.InsertVertex(0);
    g2.InsertVertex(1);
    g2.InsertVertex(2);
    g2.InsertVertex(3);
    g2.InsertVertex(4);
    g2.InsertVertex(5);

    g2.InsertEdge(0, 1);     g2.InsertEdge(1, 0);
    g2.InsertEdge(0, 2);     g2.InsertEdge(2, 0);
    g2.InsertEdge(1, 3);     g2.InsertEdge(3, 1);
    g2.InsertEdge(1, 5);     g2.InsertEdge(5, 1);
    g2.InsertEdge(2, 4);     g2.InsertEdge(4, 2);
    g2.InsertEdge(2, 5);     g2.InsertEdge(5, 2);
    g2.InsertEdge(3, 4);     g2.InsertEdge(4, 3);

    g2.ResetVisited();


    //g.DFS(0);
    g.DFS(0);

    cout << endl;

    g2.DFS(0);


    return 0;
}

