/*
 * IA_11.1DirectAddressTables.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: sunyj
 */
#include <stdint.h>
#include <iostream>
#include <string.h>
// DIRECT-ADDRESS-SEARCH(T, k)
// return T[k]

// DIRECT-ADDRESS-INSERT(T, x)
// T[x.key] = x

// DIRECT-ADDRESS-DELETE(T, x)
// T[x.kdy] = NIL

template <class Type> class ElemType {
public:
    ElemType() : key(0), data('\0') { }
    ElemType(int64_t const k, Type const d) : key(k), data(d) { }

    int64_t key; // key belongs to a small range like [0, 1, 2, 7, 99.... ]
    Type data;
};

template <class Type> class DirectAddressTable {
public:
    DirectAddressTable(int64_t const n) : size(n)
    {
        data = new ElemType<Type>[n];
        memset(data, -1, n * sizeof(ElemType<char>));
    }
    ~DirectAddressTable() { delete [] data; }
    ElemType<Type> search(int64_t const key)
    {
        if (-1 == data[key].key)
        {
            std::cout << "not found search failed" << std::endl;
        }
        return data[key];
    }
    void insert(ElemType<Type> x)
    {
        if (-1 != data[x.key].key)
        {
            std::cout << "x.key already exist, insert failed" << std::endl;
            return ;
        }
        data[x.key] = x;
    }
    void del(ElemType<Type> x)
    {
        if (-1 == data[x.key].key)
        {
            std::cout << "x.key not exist, delete failed" << std::endl;
            return ;
        }
        data[x.key].key = -1;
    }
private:
    ElemType<Type>* data;
    int64_t size;
};

int main()
{
    ElemType<char> a(2, 'b');
    ElemType<char> q(3, '8');
    ElemType<char> c(22, 'q');
    ElemType<char> w(9, 'N');

    // Assume there are at most 100 ElemType element,

    DirectAddressTable<char> table(100);
    table.insert(a);
    table.insert(q);
    table.insert(c);
    ElemType<char> tmp;
    tmp.key = 3;
    tmp = table.search(tmp.key);
    std::cout << tmp.data << std::endl;
    tmp.key = 4;
    tmp = table.search(tmp.key);
    std::cout << tmp.data << std::endl;

    table.insert(a); // insert failed
    table.del(a);
    table.insert(a); // ok
    tmp = table.search(2);
    std::cout << tmp.data << std::endl;
    return 0;
}
