#include <cstring>
#include <iostream>

using namespace std;

void solve1() {
  int n;
  cin >> n;
  int arr[9999];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int ev, od;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) ev++;
    if (arr[i] % 2 != 0) od++;
  }
  cout << ev << " " << od;
}

void solve2() {
  int n;
  cin >> n;
  int arr[9999];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n / 2; i++) {
    swap(arr[i], arr[n - 1 - i]);
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

void solve3() {
  int n;
  cin >> n;
  int arr[9999];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int k = 0;
  for (int i = 0; i < n; i++) {
    int curr = arr[i];
    bool ifUniq = true;
    for (int l = 0; l < i; l++) {
      if (arr[l] == curr) {
        ifUniq = false;
        break;
      }
    }
    if (ifUniq) {
      arr[k] = curr;
      k++;
    }
  }
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

void solve4_hashOptimize() {
  int n, m;
  cin >> m >> n;
  int arr[10000];
  bool seen[10000] = {0};
  int target = n + 1;
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    seen[arr[i]] = true;
  }
  for (int i = 0; i < m; i++){
    int curr = arr[i];
    int need = target - curr;
    if (seen[need]){
        cnt ++;
    }
  }
  cout << cnt/2 << "";
}

void solve4_firstTry() {
  int n, m;
  cin >> m >> n;
  int arr[10000];
  int target = n + 1;
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }
  for (int l = 0; l < m; l++) {
    for (int r = 0; r < m; r++) {
      if (arr[l] + arr[r] == target) {
        cnt++;
      }
    }
  }
  cout << cnt / 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve4_hashOptimize();
}