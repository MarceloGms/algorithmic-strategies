#include <iostream>
using namespace std;

void ZeManel(int len) {
  /* if all nodes were visited
    if best > len
    best = len
  for i = 1 ... N
    if visited[i]=true
      for j = 1 = 1 ... N
        if links[i] < X
        if visited[j] = false
          links[i]++
          links[j]++
          visited[j] = true
          ZeManel(len + M[i,j])
          visited[j] = false
          links[i]--
          links[j]-- */
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n > 12 || m > 40 || k > n)
    return 1;
  
  cout << n << m << k << endl;
  cin >> n >> m >> k;
  cout << n << m << k << endl;
  return 0;
}