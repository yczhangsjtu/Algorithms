#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N, S, M;
  cin >> N >> S >> M;
  vector<long long> a(N+1);
  a[1] = S;
  a[2] = (S * (S - 1)) % M;
  for(int i = 3; i <= N; i++) {
    a[i] = (a[i-1] * S - a[(i+1)/2]) % M;
  }
  cout << a[N] << endl;
  return 0;
}
