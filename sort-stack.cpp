#include <bits/stdc++.h>

using namespace std;

void cinsert(stack<int> &stk, int last, int size)
{
    // H - Insert the `last` element at crt pos in sorted stack.
    // I - If stack top is greater than `last`, the pop it and call cinsert
    // B - If stack is empty or top element is LE `last` then push it into stack.

    if (size == 0 or stk.top() <= last)
        return stk.push(last);

    int val = stk.top();
    stk.pop();
    cinsert(stk, last, size - 1);
    stk.push(val);
}

void csort(stack<int> &stk)
{
    // H - Takes a stack and sorts it.
    // I - Shrink the stack until its, sorted, once sorted insert the last removed element at its correct pos.
    // B - One element stack is sorted stack.

    int size = stk.size();

    if (size == 1)
        return;
    int last = stk.top();
    stk.pop();
    csort(stk);
    cinsert(stk, last, size - 1);
}

int main()
{

    stack<int> stk;
    //  {9, 2, 5, 8, 4, 0};
    stk.push(9);
    stk.push(2);
    stk.push(5);
    stk.push(8);
    stk.push(4);
    stk.push(0);
    csort(stk);
    while (!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
    }
    return 0;
}