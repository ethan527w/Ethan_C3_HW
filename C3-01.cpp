#include <cstring>
#include <iostream>

using namespace std;

void solve1() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    cout << " " << arr[i];
  }
}

void solve2() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i += 2) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  for (int i = 1; i < n; i += 2) {
    cout << arr[i] << " ";
  }
}

void solve3() {
  int n;
  cin >> n;
  int arr1[n];
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  for (int i = 0; i < n; i++) {
    cout << arr1[i] << " ";
  }
}

void solve4_optimized() {
  int n, val;
  int arr[10000]; // a const big enough instead of n
  cin >> n >> val;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int l = 0;
  for (int r = 0; r < n; r++) {
    if (arr[r] != val) {
      arr[l] = arr[r];
      l++; // 2 ptr
    }
  }
  cout << l << "\n";
  for (int i = 0; i < l; i++) {
    cout << arr[i] << " ";
  }
}

void solve4_original() {
  int n, val;
  cin >> n >> val;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == val) continue;
    cnt++;
  }
  cout << cnt << "\n";
  for (int i = 0; i < n; i++) {
    if (arr[i] == val) continue;
    cout << arr[i] << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve4_optimized();
}