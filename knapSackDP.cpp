#include <bits/stdc++.h>


using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}


int knapsack(int W, int weights[], int values[], int n){
    vector<vector<int> > dp(n+1, vector<int>(W+1));

    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if (i == 0 || w == 0){
                dp[i][w] = 0;
            }
            else if (weights[i-1] <= W){
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][W];

}


int main()
{
    int val[] = { 1, 2, 3 };
    int wt[] = {10, 15, 40 };
    int W = 6;
    int n = 3;
     
    cout << knapsack(W, wt, val, n);
     
    return 0;
}
