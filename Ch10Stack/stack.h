/*
 * IA_10.1_stack.h
 *
 *  Created on: Feb 13, 2015
 *      Author: sunyj
 */

#ifndef IA_10_1_STACK_H_
#define IA_10_1_STACK_H_

#include <cstdint>
// STACK-EMPTY(S)
// if S.top == 0
//     return TRUE
// else return FALSE

// PUSH(S, x)
// S.top = S.top + 1
// S[S.top] = x

// POP(S)
// if STACK-EMPTY
//     error "under flow"
// else S.top = S.top - 1
//     return S[S.top + 1]

template <class Type> class stack {
public:
    // length is a const reference, be careful, if n is not a const reference, length would be attached to
    // a local variable n, see the constructor commented below
    stack(const int64_t& n) : top(-1), length(n)
    {
        data = new Type[n]();
    }
    /*
    stack(int64_t const n) : top(-1), length(n)
    {
        data = new int64_t[n]();
    }
    */
    bool empty() { return -1 == top; }
    int64_t push (Type x)
    {
        if (length == top + 1)
        {
            std::cout << "stack is full, push failed." << std::endl;
            return -1 ;
        }
        data[++top] = x;
        return 0 ;
    }
    int64_t pop(Type& x)
    {
        if(empty())
        {
            std::cout << "stack is empty, pop failed." << std::endl;
            return -1;
        }
        x = data[top--];
        return 0;
    }
    void PrintStack()
    {
        if (empty())
        {
            return;
        }
        for (int64_t i = 0; i < top + 1; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
private:
    Type*          data;
    int64_t        top; // point to the top element of the stack
    const int64_t& length;
};


#endif /* IA_10_1_STACK_H_ */
