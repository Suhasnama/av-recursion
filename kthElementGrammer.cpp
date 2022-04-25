// https://leetcode.com/problems/k-th-symbol-in-grammar/

#include <bits/stdc++.h>

using namespace std;

/*
Pattern
1 -> 0
2 -> 0 1
3 -> 0 1 1 0
4 -> 0 1 1 0 1 0 0 1
5 -> 0 1 1 0 1 0 0 1 1 0  0  1  0  1  1  0
----------------------------------------
     1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16  => Position
     --- --- --- --- ---- ----- ----- -----
      0   1   1   0    1    0     0     1    => Deciding value.

    In above the value's at position 3,4 are decided by the the value at 2
    The formula is (3+1)/2 => 2 , i.e the value at position 2, which is 1.
                   (4+1)/2 => 2
    Now 1 means 1,0 Given in questiona (same as 0 means 0,1)
        If our k is 3 (odd value) the 0th value of 1. => 1
        If our k is 4 (even value) the 1st value of 1. => 0

    Below is the implementation of the above approach. 
        - (P.S I didn't copied this solution , i saw the question and derived it on my own!)
*/

int kthGrammar(int n, int k)
{
    if (k == 1 or k == 2)
        return k - 1;

    // The value of k depends up on the value of ((k+1)/2) in the grammer.
    int val = kthGrammar(n, ((k + 1) / 2));
    int possibilities[][2] = {{0, 1}, {1, 0}};
    // If the k is odd , the select the first value of , value returned by k+1/2.
    if (k & 1)
        return possibilities[val][0];
    else
        return possibilities[val][1];
    return 1;
}


// Same solution, but without array declaration.
// int kthGrammar(int n, int k)
// {
//     if (k == 1 or k == 2)
//         return k - 1;

//     int val = kthGrammar(n, ((k + 1) / 2));

//     if (k & 1)
//         if (val)
//             return 1;
//         else
//             return 0;
//     else if (val)
//         return 0;
//     else
//         return 1;

//     return 1;
// }

int main(int argc, char *argv[])
{
    cout << kthGrammar(6, 7) << endl;
    return 0;
}