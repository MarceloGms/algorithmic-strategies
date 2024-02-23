#include <iostream>
#include <set>
using namespace std;

typedef struct knight{
  int posX;
  int posY;
  int nMoves;
} Knight;

int chessboard(int n, int x, int y, set<pair<int, int>> &visited) {
  int count = 0;

  pair<int, int> currentPosition = make_pair(x, y);
  if (visited.find(currentPosition) == visited.end()) {
    visited.insert(currentPosition);
    count++;
  }

  if (n > 0) {
    count += chessboard(n-1, x+2, y+1, visited);
    count += chessboard(n-1, x+2, y-1, visited);
    count += chessboard(n-1, x+1, y-2, visited);
    count += chessboard(n-1, x-1, y-2, visited);
    count += chessboard(n-1, x-2, y-1, visited);
    count += chessboard(n-1, x-2, y+1, visited);
    count += chessboard(n-1, x-1, y+2, visited);
    count += chessboard(n-1, x+1, y+2, visited);
  }

  return count;
}

int main() {
  int n;
  cin >> n;
  if (n < 1 || n > 30)
    return 1;
  int totalCount = 0;
  Knight k;
  set<pair<int, int>> visited;

  for(int i = 0; i < n; i++) {
    cin >> k.posX >> k.posY >> k.nMoves;
    if (k.nMoves < 0 || k.nMoves > 7)
      return 1;
    cin.ignore();
    totalCount += chessboard(k.nMoves, k.posX, k.posY, visited);
  }

  cout << totalCount << endl;
  return 0;
}