// https://cses.fi/problemset/task/1636
 
 
#include <bits/stdc++.h>
using namespace std;
 
int get_ways(vector<int> coins,int x)
{
    
    vector<int> min_coins(x+1,0);
    int number_of_coins = coins.size();
    min_coins[0]=1;
    
    for(int j=0;j<number_of_coins;j++)
    {
        for(int i=1;i<=x;i++)
        {
            if(i-coins[j]>=0)
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
