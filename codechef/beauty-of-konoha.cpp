#include <iostream>
#include <vector>

using namespace std;

void testcase() {
  int n;
  cin >> n;
  vector<bool> color(n+2);
  vector<int> degree(n+2);
  color[1] = true;
  degree[1] = 0;
  int remote1 = 1, remote2 = 0, sum = 0;
  for(int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if(degree[a] > 1) {
      if(color[a]) {
        remote2++;
      } else {
        remote1++;
      }
    } else if(degree[a] == 1) {
      if(color[a]) {
        remote1--;
        remote2++;
      } else {
        remote2--;
        remote1++;
      }
    } else if(degree[a] == 0) {
      if(color[a])
        remote2++;
      else
        remote1++;
    }
    color[i+1] = !color[a];
    degree[a]++;
    degree[i+1] = 1;
    sum += remote1 > remote2? remote1: remote2;
  }
  cout << sum << endl;
}

int main() {
  int T;
  cin >> T;
  for(int i = 0; i < T; i++)
    testcase();
  return 0;
}
