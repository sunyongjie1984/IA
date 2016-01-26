/*
 * IA_10.1queue.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: sunyj
 */
#include "queue.h"

int main()
{
    queue<int> q(4);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3); // after enqueue 3, the queue is full
    q.enqueue(4); // enqueue failed, because the queue is full
    q.print();
    int x;
    if (0 == q.dequeue(x))
    {
        std::cout << x << std::endl;
    }
    if (0 == q.dequeue(x))
    {
        std::cout << x << std::endl;
    }
    q.print();
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6); // enqueue failed, because the queue is full
    q.print();    // elements 3, 4, 5
    q.clear();
    q.print();
    return 0;
}
