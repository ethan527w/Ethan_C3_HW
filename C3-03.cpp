#include <cstring>
#include <iostream>

using namespace std;

void solve1() {
  int n, m;
  cin >> n >> m;
  int arr[9999];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int s[9999];
  s[0] = 0;
  for (int i = 1; i < n + 1; i++) {
    s[i] = s[i - 1] + arr[i - 1];
  }
  int ans = 0;
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      int curr = s[r] - s[l - 1];
      int len = r - l + 1;
      if (curr == m * len) ans++;
    }
  }
  cout << ans;
}  // maybe use hashtable + prefix sum

void solve2() {
  int n, k, a, b, c, d;
  cin >> n >> k >> a >> b >> c >> d;
  // construct n
  int arr[999];
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  // simulation
  while (k--) {
    int lAB = a - 1;
    int rAB = b - 1;
    while (lAB < rAB) {
      swap(arr[lAB], arr[rAB]);
      rAB--;
      lAB++;
    }
    int lCD = c - 1;
    int rCD = d - 1;
    while (lCD < rCD) {
      swap(arr[lCD], arr[rCD]);
      rCD--;
      lCD++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

void solve3() {
  int n, k;
  cin >> n >> k;
  int arr[9999];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int curr = 0;
  int maxS = 0;
  for (int i = 0; i < k; i++) {
    curr += arr[i];
  }
  for (int i = k; i < n; i++) {
    int newSum = curr + arr[i];
    newSum -= arr[i-k];
    maxS = max(newSum, curr);
  }
  cout << maxS;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve3();
}