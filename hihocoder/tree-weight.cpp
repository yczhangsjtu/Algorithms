#include <iostream>
#include <cmath>

using namespace std;

typedef long long int Int;
typedef struct Node {
  int father;
  Int weight;
  Int min;
} Node;
Node nodes[100001];
int N, Q;
int u, v;
int ancestor;

inline int min(Int a, Int b) {
  if(a == -1) return b;
  if(b == -1) return a;
  return a > b ? b : a;
}

int common_ancestor() {
  for(int i = 1; i <= N; i++) {
    nodes[i].min = -1;
  }
  int pu = u, pv = v, minu = -1, minv = -1;
  while(pu || pv) {
    if(pu) {
      if(nodes[pu].father == 0) {
        pu = 0;
      } else if(nodes[nodes[pu].father].min >= 0) {
        return min(minu, min(nodes[pu].weight, nodes[nodes[pu].father].min));
      } else if(nodes[pu].father == v) {
        return min(minu, nodes[pu].weight);
      } else {
        minu = min(minu, nodes[pu].weight);
        pu = nodes[pu].father;
        nodes[pu].min = minu;
      }
    }
    if(pv) {
      if(nodes[pv].father == 0) {
        pv = 0;
      } else if(nodes[nodes[pv].father].min >= 0) {
        return min(minv, min(nodes[pv].weight, nodes[nodes[pv].father].min));
      } else if(nodes[pv].father == u) {
        return min(minv, nodes[pv].weight);
      } else {
        minv = min(minv, nodes[pv].weight);
        pv = nodes[pv].father;
        nodes[pv].min = minv;
      }
    }
  }
  return min(minu, minv);
}

int main() {
  cin >> N >> Q;
  for(int i = 1; i <= N; i++) {
    cin >> nodes[i].father;
    cin >> nodes[i].weight;
  }
  for(int i = 0; i < Q; i++) {
    cin >> u >> v;
    cout << common_ancestor() << endl;
  }
	return 0;
}
