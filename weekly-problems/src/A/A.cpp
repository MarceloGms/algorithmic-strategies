#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isFair(vector<int> guests, int n){
  sort(guests.begin(), guests.end());
  for(int i = 0; i < n-2; i++){
    int j = i + 1;
    int k = n -1;
    while (j < k) {
      int sum = guests[i] + guests[j] + guests[k];
      if (sum == 0)
        return true;
      else if (sum < 0)
        j++;
      else if (sum > 0)
        k--;
    }
  }
return false;
}

int main() {
  int n;
  while (cin >> n) {
    if (n == 0)
      continue;

    vector<int> guests;
    for (int i = 0; i < n; ++i) {
      int inp;
      cin >> inp;
      guests.push_back(inp);
    }
    /*
    for (auto e : guests)
      cout << e << " ";
    cout << endl;
    */

    bool result = isFair(guests, n);

    if (result) {
      cout << "Fair" << endl;
    } else {
      cout << "Rigged" << endl;
    }
  }

  return 0;
}

