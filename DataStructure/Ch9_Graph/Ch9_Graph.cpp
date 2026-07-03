#include "AdjMat.h"
#include "AdjList.h"

int main()
{
    AdjMat<int> g(6);

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

    //g.DFS(0);
    g.BFS(0);





    return 0;
}

