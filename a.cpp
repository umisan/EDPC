#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n, 0);
  for(int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  vector<int> dp(n, 0);
  dp[1] = abs(h[0] - h[1]);
  for(int i = 2; i < n; i++)
  {
    dp[i] = min(abs(h[i] - h[i - 1]) + dp[i - 1], abs(h[i] - h[i - 2]) + dp[i - 2]);
  }
  cout << dp[n - 1] << endl;
}
