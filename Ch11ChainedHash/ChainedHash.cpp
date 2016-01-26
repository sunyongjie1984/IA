/*
 * IA_11.2ChainedHash.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: sunyj
 */

#include "ChainedHash.h"

int main()
{
	/*
	 * A prime not too close to an exact power of 2 is often a good choice for m. For
example, suppose we wish to allocate a hash table, with collisions resolved by
chaining, to hold roughly n = 2000 character strings, where a character has 8 bits.
We don't mind examining an average of 3 elements in an unsuccessful search, and
so we allocate a hash table of size m = 701. We could choose 701 because
it is a prime near 2000=3 but not near any power of 2.
	 */
    ChainedHashTable<int64_t> table(701); // The division method,

    Node<int64_t, int64_t> node1(1, 100);
    Node<int64_t, int64_t> node4(4, 400);
    Node<int64_t, int64_t> node16(16, 1600);
    Node<int64_t, int64_t> node9(9, 900);
    if (nullptr == table.search(node1.key))
    {	// search before insert
        table.insert(&node1);
    }
    else
    {
    	std::cout << "node1 already exist" << std::endl;
    }
    if (nullptr == table.search(node1.key))
    {
        table.insert(&node1);
    }
    else
    {
    	std::cout << "node1 already exist" << std::endl;
    }
    table.insert(&node4);
    table.insert(&node16);
    table.insert(&node9);
    table.print(4);
    Node<int64_t, int64_t> node25(25, 2500);
    table.insert(&node25);
    table.print(16);
    // search before del, or you are clearly sure that, there are this node exist.
    // if node1 is not exist, and you invoke del, program will crush
    table.del(&node1);
    table.print(9);
    Node<int64_t, int64_t>* tmp;
    tmp = table.search(9);
    table.del(tmp);
    table.print(9);
    return 0;
}
