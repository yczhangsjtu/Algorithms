#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> KMP;

void createKMP(KMP &kmp, const string &p) {
  kmp = KMP(p.size()+1);
  kmp[0] = -1;
  kmp[1] = 0;
  for(int i = 2; i <= p.size(); i++) {
    int q = kmp[i-1];
    while(q >= 0 && p[q] != p[i-1])
      q = kmp[q];
    kmp[i] = q+1;
  }
}

int countOccurs(const string &s, const string &p, const KMP &kmp) {
  int i = 0, j = 0, count = 0;
  while(s.size() - i >= p.size() - j) {
    while(i < s.size() && j < p.size() && s[i] == p[j]) {
      i++;
      j++;
    }
    if(j == p.size()) count++;
    if(j > 0) j = kmp[j];
    else i++;
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string p, s;
    cin >> p >> s;
    KMP kmp;
    createKMP(kmp, p);
    cout << countOccurs(s, p, kmp) << endl;
  }
	return 0;
}
