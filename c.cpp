#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  for(int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<vector<int>> dp(n, vector<int>(3));
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];
  for(int i = 1; i < n; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(j == 0)
      {
        dp[i][j] = max(dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]);
      }else if(j == 1){
        dp[i][j] = max(dp[i - 1][0] + b[i], dp[i - 1][2] + b[i]);
      }else{
        dp[i][j] = max(dp[i - 1][0] + c[i], dp[i - 1][1] + c[i]);
      }
    }
  } 
  int max_hap = dp[n - 1][0];
  max_hap = max(max_hap, dp[n - 1][1]);
  max_hap = max(max_hap, dp[n - 1][2]);
  cout << max_hap << endl;
}
