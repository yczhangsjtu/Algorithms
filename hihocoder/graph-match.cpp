#include <iostream>

using namespace std;

int main() {
  int n, q, b;
  cin >> n;
  bool a[300001];
  for(int i = 1; i <= n; i++) {
    cin >> b;
    a[i] = b == 1;
  }
  cin >> q;
  for(int i = 0; i < q; i++) {
    int l,r;
    cin >> l >> r;
    int countone = 0, match = 0;
    for(int i = l; i <= r; i++) {
      if(a[i]) {
        countone++;
      } else {
        if(countone > 0) {
          countone--;
          match++;
        }
      }
    }
    cout << match << endl;
  }
	return 0;
}
