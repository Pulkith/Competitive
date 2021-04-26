#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>
#include <bitset>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <random>
#include <initializer_list>
#include <ios>
#include <cstring>

using namespace std;

const int INF = (int)10e8;
 
// Function to find all subsets of given set. Any repeated
// subset is considered only once in the output
void PowerSet(int arr[], int n)
{
    vector<string> list;
    for (int i = 0; i < (int) pow(2, n); i++)
    {
        string subset = "";
        for (int j = 0; j < n; j++)
            if ((i & (1 << j)) != 0)
                subset += to_string(arr[j]) + "|";
        if (find(list.begin(), list.end(), subset) == list.end())
            list.push_back(subset);
    }
    for (string subset : list){
        vector<string> arr = split(subset, '|');
        for (string str: arr)
            cout << str << " ";
        cout << endl;
    }
}