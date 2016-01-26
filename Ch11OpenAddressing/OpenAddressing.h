/*
 * IA_11.4OpenAddressing.h
 *
 *  Created on: Feb 13, 2015
 *      Author: sunyj
 */

#ifndef IA_11_4OPENADDRESSING_H_
#define IA_11_4OPENADDRESSING_H_

#include <stdint.h>
#include <string.h>
#include <iostream>
class Node {
public:
	Node() { }
	Node(int64_t const k, int64_t const d) : key(k), data(d) { }
	int64_t key;
	int64_t data;
};

class OpenAddressingLinerProb {

public:
	OpenAddressingLinerProb(int64_t const n) : length(n)
	{
		data = new Node[n]();
		memset(data, -1, n * sizeof(Node));
	}
	int64_t HashFunc(int64_t const key)
	{
		return key % length;
	}
	Node HashFuncLinerProbSearch(int64_t const key)
	{
		for (int64_t i = 0; i < length; i++)
		{
			if (data[HashFunc(key) + i].key == key)
			{
				return data[HashFunc(key) + i];
			}
		}
		return Node();
	}
	void HashFuncLinerProbInsert(Node const x)
	{
		for (int64_t i = 0; i < length; i++)
		{
			if (data[HashFunc(x.key) + i].key == -1)
			{
				data[HashFunc(x.key) + i] = x;
				return ;
			}
		}
	}
private:
	Node*   data;
	int64_t length;
};

#endif /* IA_11_4OPENADDRESSING_H_ */
