#include <bits/stdc++.h>

using namespace std;

void cerase(stack<int> &stk, int size)
{
    if (stk.empty())
        return;

    int curPos = stk.size() - 1;
    int curVal = stk.top();
    stk.pop();

    if (curPos == (size >> 1))
        return;

    cerase(stk, size);
    stk.push(curVal);
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
    cerase(stk, stk.size());
    while (!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
    }
    return 0;
}