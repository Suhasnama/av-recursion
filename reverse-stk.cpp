#include <bits/stdc++.h>

using namespace std;

void cinsert(stack<int> &stk, int val)
{
    if (stk.empty())
        return stk.push(val);

    int top = stk.top();
    stk.pop();
    cinsert(stk, val);
    stk.push(top);
}

/**
 * @brief Custom stack reverse function.
 *
 * @param stk Stack instance
 */
void creverse(stack<int> &stk)
{
    if (stk.empty())
        return;
    int top = stk.top();
    stk.pop();
    creverse(stk);
    cinsert(stk, top);
}

int main()
{
    stack<int> stk;
    stk.push(9);
    stk.push(2);
    stk.push(5);
    stk.push(8);
    stk.push(4);
    stk.push(1);
    stk.push(0);
    creverse(stk);
    while (!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
    }

    return 0;
}