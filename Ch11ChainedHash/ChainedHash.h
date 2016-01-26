/*
 * IA_11.2ChainedHash.h
 *
 *  Created on: Feb 13, 2015
 *      Author: sunyj
 */

#ifndef IA_11_2CHAINEDHASH_H_
#define IA_11_2CHAINEDHASH_H_

#include <iostream>
#include <string.h>

#include "LinkedLists.h"

// CHAINED-HASH-INSERT(T, x)
// insert x at the head of list T[h(x.key)]

// CHAINED-HASH-SEARCH(T, k)
// search for an element with key k in list T[h(k)]

// CHAINED-HASH-DELETE(T, x)
// delete x from the list T[h(x.key)]

template <class T> class ChainedHashTable {
public:
	ChainedHashTable(int64_t const n) : size(n)
    {
        data = new LinkedList<int64_t, T>[n]();
    }
    ~ChainedHashTable() {}
    int64_t HashFunc(int64_t const key)
    {
    	return key % size;
    }
    Node<int64_t, T>* search(int64_t const key)
    {
    	return data[HashFunc(key)].search(key);
    }
    // the user of this class, has to invoke search first
    // this interface assume that x was not in the hash table
    void insert(Node<int64_t, T>* x)
	{
		(data[HashFunc(x->key)]).insert(x);
	}
    void del(Node<int64_t, T>* x)
    {
    	data[HashFunc(x->key)].del(x);
    }
    void print(int64_t key)
    {
    	data[HashFunc(key)].print();
    }
private:
    LinkedList<int64_t, T>* data;
    int64_t const size;
};

#endif /* IA_11_2CHAINEDHASH_H_ */
