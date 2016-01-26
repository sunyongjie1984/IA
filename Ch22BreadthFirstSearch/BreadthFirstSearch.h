/*
 * IA_22.2BreadthFirstSearch.h
 *
 *  Created on: Feb 13, 2015
 *      Author: sunyj
 */

#ifndef IA_22_2BREADTHFIRSTSEARCH_H_
#define IA_22_2BREADTHFIRSTSEARCH_H_

#include <vector>
#include <map>

#include "queue.h"
#include "LinkedLists.h"
#include <cstdint>

using std::map;
using std::vector;
using std::pair;
using std::cout;
using std::endl;

enum Color { white, grey, black };

class NodeData {
public:

    // use INT64_MAX must include <cstdint> and using compiler g++ 4.7.0
    // and then g++ -std=c++11, be carefull not c++0x in the centos 64bit operating system
    NodeData() : color(white), par(nullptr), depth(INT64_MAX) { }
    NodeData(Color const c) : color(c), par(nullptr), depth(INT64_MAX) { }
    NodeData(const NodeData& nd)
    {
        color = nd.color;
        par   = nd.par;
        depth = nd.depth;
    }
private:
public:
    Color    color;
    void*    par;
    int64_t  depth;
};

// BFS(G, s)
// for each vertex u belongs to G.V - {s}
//     u.color = white
//     u.d = INT64_MAX
//     u.par = NIL
// s.color = grey
// s.d     = 0
// s.par   = NIL
// Q = empty
// ENQUEUE(Q, s)
// while(Q != empty)
//     u = DEQUEUE(Q);
//     for each v belongs to G.Adj[u]
//         if v.color == white
//             v.color = grey
//             v.d = u.d + 1
//             v.par = u
//             ENQUEUE(Q, v)
//     u.color = black

// PRINT-PATH(G, s, v)
// if v == s
//     print s
// elseif v.par == NIL
//     print "no path from" s "to" v "exists"
// else PRINT-PATH(G, s, v.par)
//     print v
template <class Type, class T> class Graph {
public:
	typedef Node<Type, T>* PVertex;
	bool PrintPath(PVertex s, PVertex v)
	{
		if (s == v)
		{
			cout << s->key << " ";
			return true;
		}
		else if (nullptr == v->data.par)
		{
			cout << "no path from s to v exists" << endl;
			return false;
		}
		else
		{
			if (PrintPath(s, static_cast<PVertex>(v->data.par)))
			{
				cout << v->key << " ";
				return true;
			}
			else
			{
				return false;
			}
		}
	}
    // Type: int, charactor
    // T: the data that the Node carry
    void DFS(PVertex s)
    {
        s->data.color = grey;
        s->data.depth = 0;

        QueueDFS.enqueue(s);
        while (!QueueDFS.empty())
        {
            PVertex u;
            QueueDFS.dequeue(u);
            typename map<Type, LinkedList<Type, PVertex>* >::iterator iter = MapAdj.find(u->key);
            if (MapAdj.end() != iter) //
            {
                Node<Type, PVertex >* pNil = iter->second->GetNil();
                Node<Type, PVertex >* x = pNil->next;
                while (pNil != x)
                {
                    // cout << x->key << " ";
                    if (white == (*x->data).data.color)
                    {
                    	(*x->data).data.color = grey;
                    	(*x->data).data.depth += u->data.depth + 1;
                    	(*x->data).data.par   = u;
                    	QueueDFS.enqueue(x->data);
                    	cout << "node " << (*x->data).key << " is grey now" << endl;
                    }
                    x = x->next;
                }
                u->data.color = black;
                cout << "node " << u->key << " is black now" << endl;
            }
        }
        return ;
    }
    Graph(int const n) : MaxCount(n), QueueDFS(MaxCount)  { }// assume the graphic has less than 100 vertex
    void InsertVertex(Node<Type, T>* v)
    {
        MapVertex.insert(pair<Type, PVertex >(v->key, v));
        LinkedList<Type, PVertex>* pLinkedList = new LinkedList<Type, PVertex>;
        MapAdj.insert(pair<Type, LinkedList<Type, PVertex>* >(v->key, pLinkedList));
    }
    void InsertEdge(PVertex v1, PVertex v2)
    {
        typename map<Type, PVertex >::const_iterator VIter = MapVertex.find(v1->key);
        if (MapVertex.end() == VIter)
        {
            cout << "v1 is not a vertex of graphic" << endl;
            return ;
        }
        VIter = MapVertex.find(v2->key);
        if (MapVertex.end() == VIter)
        {
            cout << "v2 is not a vertex of graphic" << endl;
            return ;
        }
        typename map<Type, LinkedList<Type, PVertex>* >::iterator iter = MapAdj.find(v1->key);
        if (MapAdj.end() != iter) // should be found, otherwise program logic is wrong
        {
            if (nullptr == iter->second->search(v2->key))
            {
                // Node<Type, T> is a Type, and the type is for Vertex of Graph
                // Type is a Type, and the type is for the key of the Node(Vertex), key is the attr and diff one
                // node(Vertex) to another.
                // T is a Type, and the type is for other information of the Node(Vertex), something like color, etc.
                Node<Type, PVertex >* pNode = new Node<Type, PVertex >;
                pNode->data = v2;
                pNode->key  = v2->key;
                iter->second->insert(pNode);
            }
            else
            {
                cout << "edge has already exist" << endl;
            }
        }
    }
    void PrintAdj(Node<Type, T>* p)
    {
        typename map<Type, LinkedList<Type, PVertex>* >::iterator iter = MapAdj.find(p->key);
        if (MapAdj.end() != iter)
        {
            Node<Type, PVertex >* pNil = iter->second->GetNil();
            Node<Type, PVertex >* x = pNil->next;
            while (pNil != x)
            {
                cout << x->key << " ";
                // cout << (*x->data).key << " " ;
                x = x->next;
            }
            cout << endl;
        }
    }
private:
    map<Type, PVertex >      MapVertex;    // vertex
    map<Type, LinkedList<Type, PVertex >* > MapAdj;       // adjacency list
    int const MaxCount;
    queue<PVertex > QueueDFS;
};


#endif /* IA_22_2BREADTHFIRSTSEARCH_H_ */
