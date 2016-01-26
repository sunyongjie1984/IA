/*
 * IA_11.4OpenAddressing.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: sunyj
 */
#include <stdint.h>
#include <string.h>
#include <iostream>

#include "OpenAddressing.h"

int main()
{
    OpenAddressingLinerProb linertable(7);
    Node node2(2, 200);
    Node node3(5, 300);
    Node node9(9, 900);
    Node node4(4, 400);

    linertable.HashFuncLinerProbInsert(node2);
    linertable.HashFuncLinerProbInsert(node3);
    linertable.HashFuncLinerProbInsert(node9);
    linertable.HashFuncLinerProbInsert(node4);

    Node tmp = linertable.HashFuncLinerProbSearch(4);
    std::cout << tmp.data << std::endl;
    tmp = linertable.HashFuncLinerProbSearch(2);
    std::cout << tmp.data << std::endl;
    tmp = linertable.HashFuncLinerProbSearch(9);
    std::cout << tmp.data << std::endl;
    return 0;
}

// Linear probing
