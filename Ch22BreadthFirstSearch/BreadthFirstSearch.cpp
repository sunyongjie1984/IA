/*
 * IA_22.2BreadthFirstSearch.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: sunyj
 */
#include "BreadthFirstSearch.h"

int main()
{
    Graph<char, NodeData> g(1000); // 1000 vertex at most


    Node<char, NodeData> r('r');
    Node<char, NodeData> s('s');
    Node<char, NodeData> t('t');
    Node<char, NodeData> u('u');
    Node<char, NodeData> v('v');
    Node<char, NodeData> w('w');
    Node<char, NodeData> x('x');
    Node<char, NodeData> y('y');

    g.InsertVertex(&r);
    g.InsertVertex(&s);
    g.InsertVertex(&t);
    g.InsertVertex(&u);
    g.InsertVertex(&v);
    g.InsertVertex(&w);
    g.InsertVertex(&x);
    g.InsertVertex(&y);

    g.InsertEdge(&r, &s);
    g.InsertEdge(&r, &v);
    g.InsertEdge(&s, &r);
    g.InsertEdge(&s, &w);

    g.InsertEdge(&w, &x);
    g.InsertEdge(&w, &t);

    g.InsertEdge(&t, &x);
    g.InsertEdge(&t, &u);
    g.InsertEdge(&x, &y);
    g.InsertEdge(&x, &u);
    g.InsertEdge(&u, &y);


    g.InsertEdge(&v, &r);
    g.InsertEdge(&w, &s);
    g.InsertEdge(&t, &w);
    g.InsertEdge(&x, &w);
    g.InsertEdge(&x, &t);
    g.InsertEdge(&u, &t);
    g.InsertEdge(&y, &x);
    g.InsertEdge(&u, &x);
    g.InsertEdge(&y, &u);

    g.PrintAdj(&r);
    g.PrintAdj(&s);
    g.PrintAdj(&t);
    g.PrintAdj(&u);
    g.PrintAdj(&v);
    g.PrintAdj(&w);
    g.PrintAdj(&x);
    g.PrintAdj(&y);

    g.DFS(&s);
    g.PrintPath(&r, &v);
    cout << endl;
    g.PrintPath(&s, &v);
    cout << endl;
    g.PrintPath(&s, &t);
    cout << endl;
    g.PrintPath(&s, &x);
    cout << endl;
    g.PrintPath(&s, &y);
    cout << endl;
    g.PrintPath(&r, &x);
    cout << endl;
    return 0;
}
