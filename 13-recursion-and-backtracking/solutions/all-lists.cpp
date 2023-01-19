#include <iostream>

using namespace std;

void permute(int* permutation, bool* used, int n, int index) {
  if (index == n) {
    // print permutation
    for (int i = 0; i < n; i++) {
      cout << permutation[i] << " ";
    }
    cout << endl;
    return;
  }

  // try all possible values for the current index
  for (int i = 1; i <= n; i++) {
    // if i is not used in the permutation
    if (!used[i]) {
      permutation[index] = i;
      used[i] = true;
      // generate permutations for the next index
      permute(permutation, used, n, index + 1);
      // backtrack
      // we are going to try another value for the current index
      used[i] = false;
    }
  }
}

int main() {
  int n = 3;
  int* permutation = new int[n];
  // used[i] == true <=> i is used in the permutation
  bool* used = new bool[n + 1];
  permute(permutation, used, n, 0);
  delete[] permutation;
  delete[] used;
  return 0;
}
