// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;
 
int minimize_coins(vector<int> coins,int x)
{
    int ways=0;
    vector<int> min_coins(x+1,INT_MAX);
    int number_of_coins = coins.size();
    for(int i=0;i<number_of_coins;i++)
    {
        if(coins[i]<=x)
            min_coins[coins[i]] = 1;
    }
    
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<number_of_coins;j++)
        {
            if(i-coins[j]>0&&min_coins[i-coins[j]]!=INT_MAX)
                min_coins[i] = min(min_coins[i],1+min_coins[i-coins[j]]);
        }
    }
    return min_coins[x]==INT_MAX?-1:min_coins[x];
    
}
 
int main() {
    // Write C++ code here
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    cout<<minimize_coins(coins,x);
 
    return 0;
}