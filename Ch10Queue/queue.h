/*
 * IA_10.1queue.h
 *
 *  Created on: Feb 13, 2015
 *      Author: sunyj
 */

#ifndef IA_10_1QUEUE_H_
#define IA_10_1QUEUE_H_

#include <iostream>

// ENQUEUE(Q, x)
// Q[Q.tail] = x
// if Q.tail = Q.length
//     Q.tail = 1
// else Q.tail = Q.tail + 1

// DEQUEUE(Q)
// x = Q[Q.haed]
// if Q.head == Q.length
//     Q.head = 1
// Q.head = Q.head + 1
// return x

template < class T > class queue {
public:
    queue( int64_t const n ) : head( 0 ), tail( 0 ), length( n )
    {
        data = new T[ n ]( );
    }
    bool full( )
    {
        if ( head == tail + 1 || ( 0 == head && length == tail + 1 ) )
        {
            return true;
        }
        return false;
    }
    bool empty( ) { return head == tail; }
    void print( )
    {
        if ( empty( ) )
        {
            return ;
        }
        if ( head < tail )
        {
            for ( int64_t i = head; i < tail; i++ )
            {
                std::cout << data[i] << " ";
            }
        }
        else
        {
            for ( int64_t i = head; i < length; i++ )
            {
                std::cout << data[ i ] << " ";
            }
            for ( int64_t i = 0; i < tail; i++ )
            {
                std::cout << data[ i ] << " ";
            }
        }
        std::cout << std::endl;
        return;
    }
    int64_t enqueue( T const x )
    {
        if ( full( ) )
        {
            std::cout << "queue is full, enqueue failed" << std::endl;
            return -1;
        }
        data[ tail ] = x;
        if ( length == tail + 1 )
        {
            tail = 0;
        }
        else
        {
            ++tail;
        }
        return 0;
    }
    int64_t dequeue( T& x )
    {
        if ( empty( ) )
        {
            return -1;
        }
        x = data[ head ];
        if ( length - 1 == head )
        {
            head = 0;
        }
        else
        {
            ++head;
        }
        return 0;
    }
    void clear( )
    {
        while ( !empty( ) )
        {
            T x;
            dequeue( x );
        }
    }
private:
    int     head;   // points to the first element of the queue, the element has already been in queue
    int     tail;   // points to the next coming element
    T*      data;
    int64_t const length; // the queue can hold at most length-1 element
};

#endif /* IA_10_1QUEUE_H_ */
