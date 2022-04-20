#include <bits/stdc++.h>

using namespace std;

void cinsert(vector<int> &arr, int last, int size)
{
    // H - Insert the `last` at corrected position in sorted arr.
    // I - Since arr is sorted, if `last` is GE last ele in arr then push_back, else pop the last element and call cinsert
    // B - If arr is empty of last ele of arr is LE `last` , just push_back `last` into arr

    if (size == 0 or arr[size - 1] > last)
        return arr.push_back(last);

    int val = arr[size - 1];
    arr.pop_back();
    cinsert(arr, last, size - 1);
    arr.push_back(val);
}

void csort(vector<int> &arr)
{
    // H - Shrink the arryay until , its sorted. (Single element is sorted)
    // I - Pop element if array is not empty, then in backtracking, insert popped element at crt pos in sorted array.
    // B - If size is 1 the its sorted.
    int size = arr.size();
    if (size == 1)
        return;
    int last = arr[size - 1];
    arr.pop_back();
    csort(arr);
    cinsert(arr, last, size - 1);
}
int main()
{
    vector<int> arr = {9, 2, 5, 8, 4, 0};
    csort(arr);
    for (auto i : arr)
    {
        cout << i << endl;
    }
    return 0;
}