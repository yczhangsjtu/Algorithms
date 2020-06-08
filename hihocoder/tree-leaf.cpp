#include <iostream>
#include <cmath>

using namespace std;

typedef struct Node {
  int father;
  int life;
} Node;

int main() {
  int N, Q;
  cin >> N >> Q;
  Node nodes[100001];
  int lives[100001];
  int alive[100001];
  lives[0] = 0;
  for(int i = 1; i <= N; i++) {
    nodes[i].life = 0;
    lives[i] = 0;
    cin >> nodes[i].father;
  }
  for(int i = 1; i<= N; i++) {
    int curr = i;
    while(nodes[curr].father && nodes[nodes[curr].father].life < nodes[curr].life + 1) {
      nodes[nodes[curr].father].life = nodes[curr].life + 1;
      curr = nodes[curr].father;
    }
  }
  for(int i = 1; i <= N; i++) {
    lives[nodes[i].life]++;
  }
  alive[0] = N;
  for(int i = 1; i <= N; i++) {
    alive[i] = alive[i-1] - lives[i-1];
  }
  for(int i = 0; i < Q; i++) {
    int M;
    cin >> M;
    int diff = abs(alive[0] - M);
    for(int j = 1; j <= N; j++) {
      if(j == N) {
        cout << j << endl;
        break;
      }
      if(abs(alive[j] - M) >= diff) {
        cout << j << endl;
        break;
      }
      diff = abs(alive[j] - M);
    }
  }
	return 0;
}
