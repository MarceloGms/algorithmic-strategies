#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Path(int n, vector<vector<int>> P) {
  vector<vector<int>> DP(n, vector<int>(n, 0));
  DP[0][0] = P[0][0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      DP[i][j] = P[i][j] + max((j > 0) ? DP[i-1][j-1] : 0, DP[i-1][j]);
    }
  }
  int max_value = -1;
  for (int i = 0; i < n; i++) {
    if (DP[n-1][i] > max_value) {
      max_value = DP[n-1][i];
    }
  }
  return max_value;
}

int main() {
  vector<vector<int>> hill;
  vector<int> row;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    hill = {};
    int n_rows;
    cin >> n_rows;
    for (int j = 0; j < n_rows; j++) {
      row = {};
      for (int k = 0; k <= j; k++) {
        int flag;
        cin >> flag;
        row.push_back(flag);
      }
      hill.push_back(row);
    }
    cout << Path(n_rows, hill) << endl;
  }
  return 0;
}