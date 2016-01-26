/*
 * IA_10.1_stack.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: sunyj
 */

#include <iostream>
#include <stdio.h>
#include "stack.h"

int main()
{
    stack<int64_t> st(3);
    std::cout << st.empty() << std::endl;
    int64_t e;
    if (0 == st.pop(e))
    {
        std::cout << e << std::endl;
    }

    st.PrintStack();
    st.push(1);
    st.push(5);
    st.push(3);
    st.push(4);
    st.PrintStack();


    if (0 == st.pop(e))
    {
        std::cout << e << std::endl;
    }

    st.PrintStack();
    return 0;
}
