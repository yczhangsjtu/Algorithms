#include <iostream>

using namespace std;

typedef long long int Int;

int main() {
  Int prices[20];
  Int discount[20];
  Int N;
  Int C;
  cin >> N >> C;
  for(int i = 0; i < N; i++) {
    cin >> prices[i] >> discount[i];
  }
  if(prices[0] > C) {
    cout << 0 << " " << prices[0] - C << " " << discount[0] << endl;
  } else if(prices[N-1] <= C) {
    cout << discount[N-1] << endl;
  } else {
    for(int i = 0; i < N-1; i++) {
      if(prices[i] <= C && prices[i+1] > C) {
        cout << discount[i] << " " << prices[i+1] - C << " " << discount[i+1] << endl;
        break;
      }
    }
  }
	return 0;
}
