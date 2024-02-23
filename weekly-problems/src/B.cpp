#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef struct knight{
  int posX;
  int posY;
  int nMoves;
} Knight;

void chessboard(int n, int x, int y, int &count, set<pair<int, int>> &visited) {
  if (n != 0) {
    pair<int, int> currentPosition = make_pair(x, y);
    if (visited.find(currentPosition) == visited.end()) {
      count++;
      visited.insert(currentPosition);
    }
    chessboard(n-1, x+2, y+1, count, visited);
    chessboard(n-1, x+2, y-1, count, visited);
    chessboard(n-1, x+1, y-2, count, visited);
    chessboard(n-1, x-1, y-2, count, visited);
    chessboard(n-1, x-2, y-1, count, visited);
    chessboard(n-1, x-2, y+1, count, visited);
    chessboard(n-1, x-1, y+2, count, visited);
    chessboard(n-1, x+1, y+2, count, visited);
  }
}

int main() {
  int n;
  cin >> n;
  if (n < 1 || n > 30)
    return 1;
  int count = 0;
  vector<Knight> knights;
  Knight k;
  set<pair<int, int>> visited;

  for(int i = 0; i < n; i++) {
    cin >> k.posX;
    cin >> k.posY;
    cin >> k.nMoves;
    if (k.nMoves < 0 || k.nMoves > 7)
      return 1;
    cin.ignore();
    knights.push_back(k);
  }

  for(auto e : knights)
    chessboard(e.nMoves, e.posX, e.posY, count, visited);

  cout << count << endl;
  return 0;
}