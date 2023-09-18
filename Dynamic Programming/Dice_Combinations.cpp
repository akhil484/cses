// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
using namespace std;
 
int get_ways(int n)
{
    int ways=0;
    vector<int> ways_to_make_n(n+1,0);
    ways_to_make_n[1] = 1;
    ways_to_make_n[0] = 1;
    ways_to_make_n[2] = 2;
    for(int i=3;i<=n;i++)
    {
        int j=1;
        while(j<=i&&j<=6)
        {
            ways_to_make_n[i] = (ways_to_make_n[i]+ways_to_make_n[i-j])%1000000007;
            j++;
        }
    }
    return ways_to_make_n[n];
    
}
 
int main() {
    // Write C++ code here
    int n;
    cin>>n;
    cout<<get_ways(n);
 
    return 0;
}