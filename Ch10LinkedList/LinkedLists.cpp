/*
 * IA_10.2LinkedLists.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: sunyj
 */
#include "LinkedLists.h"

int main()
{
	// first int64_t means the class type of key is int64_t
	// second int64_t means the class type of data stored in node is int64_t
    LinkedList<int64_t, int64_t> list;
    Node<int64_t, int64_t> node1(1, 100);
    Node<int64_t, int64_t> node4(4, 400);
    Node<int64_t, int64_t> node16(16, 1600);
    Node<int64_t, int64_t> node9(9, 900);
    list.insert(&node1);
    list.insert(&node4);
    list.insert(&node16);
    list.insert(&node9);
    list.print();
    Node<int64_t, int64_t> node25(25, 2500);
    list.insert(&node25);
    list.print();
    list.del(&node1);
    list.print();
    Node<int64_t, int64_t>* tmp;
    tmp = list.search(9);
    list.del(tmp);
    list.print();


    return 0;
}
