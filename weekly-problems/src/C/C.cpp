#include <iostream>
using namespace std;

bool ZeManel(int len) {
  if all nodes were visited
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
          links[j]--
}

int main() {
  return 0;
}