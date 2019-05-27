//
//  StackNode.h
//  TestRevisionP6
//
//  Created by Laura Walsh on 01/05/2019.
//  Copyright © 2019 Laura Walsh. All rights reserved.
//

#ifndef StackNode_h
#define StackNode_h

template <typename T>
class StackNode
{
public:
    StackNode(T i, StackNode<T>* nxt);
    ~StackNode() {};
    
    T item;
    StackNode<T>* next;
    
private:
};

template <typename T>
StackNode<T>::StackNode(T i, StackNode<T>* nxt)
: item(i), next(nxt)
{
}

#endif /* StackNode_h */
