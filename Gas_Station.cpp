//134. Gas Station
#include <iostream>
#include<iterator>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int index = -1; //just create a table with 5 rows (gas, cost, diff, balance(summ of all diff), balance_of_pretendent (starting + diff from pretendent index), index (pretendent)
        int balance = 0;
        int balance_of_pretendent = 0;
        int diff = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            diff = gas[i] - cost[i];
            balance += diff;

            balance_of_pretendent += diff;
            if (diff < 0 && balance < 0 && balance_of_pretendent < 0)
            {
                index = -1;
                continue;
            }
            if (index == -1 && diff >= 0)
            {
                balance_of_pretendent = diff;
                index = i;
                continue;
            }
        }
        if (balance < 0)
        {
            return -1;
        }
        return index;
    }

};
int main()
{
    //try
    Solution S;
    vector<int> gas = { 6,1,4,3,5 };
    vector<int> cost = { 3,8,2,4,2 };
    cout << S.canCompleteCircuit(gas, cost) << endl;
}