// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>
using namespace std;
 
int get_ways(vector<int> coins,int x)
{
    
    vector<int> min_coins(x+1,0);
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
            if(i-coins[j]>0)
                min_coins[i] = (min_coins[i]+min_coins[i-coins[j]])%1000000007;
        }
    }
    return min_coins[x];
    
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
    cout<<get_ways(coins,x);
 
    return 0;
}