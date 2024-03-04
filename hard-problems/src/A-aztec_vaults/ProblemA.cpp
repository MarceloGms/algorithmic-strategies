#include<iostream>
#include<vector>
using namespace std;

int Vault(vector<vector<int>> grid) {
  int nMoves = 0;
  return nMoves;
}

int main() {
  int n;
  cin >> n;
  // cout << n << endl;
  vector<vector<int>> grid;
  vector<int> row;
  for (int i = 0; i < n; i++) {
    grid = {};
    int r, c, m;
    cin >> r >> c >> m;
    if (r < 2 || r > 5 || c < 2 || c > 5 || r > c || m < 1 || m > 7)
      return 1;
    // cout << r << " " << c << " " << m << endl;
    for (int j = 0; j < r; j++) {
      row = {};
      for (int k = 0; k < c; k++) {
        int value;
        cin >> value;
        row.push_back(value);
      }
      grid.push_back(row);
    }
    /* for (const auto& innerVec : grid) {
      for (int element : innerVec) {
        cout << element << " ";
      }
      cout << endl;
    } */
    int result = Vault(grid);
    if (result <= m)
      cout << result << endl;
    else 
      cout << "the treasure is lost!" << endl;
  }
  return 0;
}