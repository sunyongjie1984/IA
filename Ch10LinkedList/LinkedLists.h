/*
 * IA_10.2LinkedLists.h
 *
 *  Created on: Feb 13, 2015
 *      Author: sunyj
 */

#ifndef IA_10_2LINKEDLISTS_H_
#define IA_10_2LINKEDLISTS_H_

#include <iostream>

// T is void* is a good idea for some application
// key is a variable of type "Type"
// data is a variable of Type "T"
template <class Type, class T> class Node {
public:
	/*friend bool operator< <T>(const Node<T>&, const Node<T>&);
	friend bool operator== <T>(const Node<T>& lhs, const Node<T>& rhs);*/
	Node() : key(0), prev(nullptr), next(nullptr) { }
	Node(Type k) : key(k), prev(nullptr), next(nullptr) { }
	Node(Type const k, T const d) : key(k), data(d), prev(nullptr), next(nullptr) { }

    Type key;
    T data;
    Node* prev;
    Node* next;
};

// LIST-SEARCH(L, k)
// x = L.nil.next
// while ( x != L.nil and x.key != k)
//     x = x.next
// return x

// LIST-INSERT(L, x)
// x.next = L.nil.next
// L.nil.next.prev = x
// L.nil.next = x
// x.prev = L.nil

// LIST-DELETE(L, x)
// x.prev.next = x.next
// x.next.prev = x.prev

template <class Type, class T> class LinkedList {
public:
    LinkedList() : nil(&m_nil)
    {
        nil->prev = nil;
        nil->next = nil;
    }
    Node<Type, T>* search(Type const k) // find node by key
    {
    	Node<Type, T>* x = nil->next;
        while (x != nil && k != x->key)
        {
            x = x->next;
        }
        if (nil == x)
        {
        	return nullptr;
        }
        return x;
    }
    // insert the address of the node, at the head of the list
    void insert(Node<Type, T>* x)
    {
        x->next         = nil->next;
        nil->next->prev = x;
        nil->next       = x;
        x->prev         = nil;
    }
    void del(Node<Type, T>* x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }
    Node<Type, T>* GetNil()
    {
        return nil;
    }
    void print()
    {
        Node<Type, T>* x = nil->next;
        while (nil != x)
        {
            std::cout << x->key << " ";
            x = x->next;
        }
        std::cout << std::endl;
    }
private:
    Node<Type, T>  m_nil; // empty list has one node, pointer nil points to it.
    Node<Type, T>* nil;
};


#endif /* IA_10_2LINKEDLISTS_H_ */
