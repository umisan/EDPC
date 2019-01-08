#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, k;
  cin >> n;
  cin >> k;
  vector<int> h(n, 0);
  for(int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  vector<int> dp(n, 0);
  for(int i = 0; i < n; i++)
  {
    int min_cost = 1e9;
    for(int j = 1; j <= k; j++)
    {
      if(i - j < 0) break;
      min_cost = min(abs(h[i] - h[i - j]) + dp[i - j], min_cost);
    }
    if(i == 0)
    {
      dp[0] = 0;
    }else{
      dp[i] = min_cost;
    }
  }
  cout << dp[n - 1] << endl;
}
