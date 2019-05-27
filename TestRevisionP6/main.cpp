//
//  main.cpp
//  TestRevisionP6
//
//  Created by Laura Walsh on 01/05/2019.
//  Copyright © 2019 Laura Walsh. All rights reserved.
//

#include <iostream>
#include <string>
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "StackNode.h"
using namespace std;

template<typename T>void setUpStack(ArrayStack<T>* s, int num){
    T in_val;
    for(int i =0; i< num; i++){
    cout << "Please enter a value to add to the stack: " << endl;
        cin>> in_val;
        s->push(in_val);
}
}

template<typename T>
void printStack(ArrayStack<T>* s)
{
    ArrayStack<T> temp;
    while (!s->isEmpty()) {
        T* t = s->pop();
        cout << *t << endl;
        temp.push(*t);
    }
    cout << endl;
    
    while (!temp.isEmpty())
        s->push(*temp.pop());
}

template<typename T> void removeAt (ArrayStack<T>& s, int p){
    ArrayStack<T> temp(s.size());
    if (p >= s.size()) {
        cout << "Can't remove item at position " << p << endl;
        return;
    }
    
    // Move the top items above position p to temp
    while (s.size() > p + 1)
        temp.push(*s.pop());
    // Remove item at p
    s.pop();
    // Move items in temp back to s
    while (!temp.isEmpty())
        s.push(*temp.pop());
}

// Evaluating postfix expression inputted from cin
void evaluateExpression()
{
    cout << "Enter symbol # to end calculation" << endl << endl;
    
    ArrayStack<int> s;
    string in;
    
    // Take 1st input
    cin >> in;
    while (in != "#") {
        int i;
        try {
            i = stoi(in);    // stoi converts a character string to an integer. It throws an exception for invalid argument
        }
        catch (exception& e) {
            // Pop the top two items for postfix calculation
            int* x = s.pop();
            int* y = s.pop();
            if (!x || !y) {
                cout << e.what() << endl;
                break;
            }
            
            // Perform +, -, *, / operation
            if (in == "+") s.push(*x + *y);
            else if (in == "-") s.push(*y - *x);
            else if (in == "*") s.push(*x * *y);
            else if (in == "/" && *x != 0) s.push(*y / *x);
            // An unknown operator is encountered
            else {
                cout << e.what() << endl;
                break;
            }
            // Take next input
            cin >> in;
            continue;    // jump straight to the top of the innermost loop (here it's while)
        }
        // Push an int value onto stack
        s.push(i);
        
        // Take next input
        cin >> in;
    }
    
    int* result = s.pop();
    if (result) cout << "Reulst = " << *result << endl;
    cout << endl;
}


int main(){
    
    ArrayStack<string> days(7);
    
    setUpStack<string>(&days, 7);
    cout << "Days: " << endl;
    printStack(&days);
    
    removeAt(days, 4);
    printStack(&days);
    cout << endl;
    int p = days.searchStack("mon");
    cout << p << endl;
    cout << endl;
    int p2 = days.searchStack("fri");
    cout << p2 << endl;
    
    evaluateExpression();
    
    return 0;
}
