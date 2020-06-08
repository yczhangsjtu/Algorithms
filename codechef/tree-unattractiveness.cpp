/*
6
8
0 0 0 1 2 2 2 2
1 3
2 3
3 4
3 5
3 6
6 7
6 8
8
0 0 1 2 2 2 2 2
1 3
2 3
3 4
3 5
3 6
6 7
6 8
8
0 1 2 2 2 2 2 2
1 3
2 3
3 4
3 5
3 6
6 7
6 8
7
0 0 0 1 2 2 2
1 2
1 3
2 4
2 5
3 6
3 7
10
0 1 2 2 2 2 2 2 2 2
1 2
1 3
1 4
1 5
1 6
2 7
2 8
2 9
2 10
12
0 0 0 0 0 1 1 2 2 2 2 2
1 4
1 5
1 6
1 3
1 2
3 12
3 11
3 10
2 7
2 8
2 9
*/

#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef set<int> Neighbors;
typedef Neighbors::iterator NeighborIter;
typedef vector<Neighbors> Graph;
typedef set<int> Children;
typedef struct TreeNode {
  int father;
  int index;
  Children children;
  TreeNode(int i, int f): index(i), father(f) {}
} TreeNode;
typedef vector<TreeNode> Tree;
typedef struct State {
  int n0, n1, rootColor;
  State(int _n0, int _n1, int _root): n0(_n0), n1(_n1), rootColor(_root) {}
  bool operator<(const State &rh) {
    if(n0 < rh.n0) return true;
    if(n0 > rh.n0) return false;
    if(n1 < rh.n1) return true;
    if(n1 > rh.n1) return false;
    return rootColor < rh.rootColor;
  }
} State;
typedef map<State, int> StateTable;

void _graphToTree(Tree &tree, const Graph &graph, int root, int father) {
  TreeNode node(root, father);
  for(NeighborIter iter = graph[root].begin(); iter != graph[root].end(); iter++) {
    if(*iter == father) continue;
    node.children.push_back(*iter);
    _graphToTree(tree, graph, *iter, root);
  }
  tree[root] = node;
}

void graphToTree(Tree &tree, const Graph &graph, int root) {
  _graphToTree(tree, graph, root, 0);
}

void count_marker_types(const vector<int> &markers, int &zero, int &one, int &two) {
  zero = one = two = 0;
  for(int i = 0; i < markers.size(); i++) {
    if(markers[i] == 0) zero++;
    else if(markers[i] == 1) one++;
    else two++;
  }
}

// // Recursively compute the size of the subtrees rooted at each vertex
// // If father is 0, it means the entire tree; else father specifies the
// // father node of the subtree
// void subtree_size(Graph &tree, vector<int> &sizes, int root, int father) {
//   for(NeighborIter iter = tree[root].begin(); iter != tree[root].end(); iter++) {
//     // If neighbor is father, skip; else the neighbor is a child
//     if(*iter == father) continue;
//     // Recursively compute the subtree size of the child
//     subtree_size(tree, sizes, *iter, root);
//     sizes[root] += sizes[*iter];
//   }
//   // Count the root itself
//   sizes[root] += 1;
// }

void computeStates(StateTable &states, const Tree &tree, const vector<int> &sizes, int root, int n0, int n1) {
  vector<StateTable> stateTables;
  Children children = tree[root].children;
  if(children.empty()) {
    states[State(1,0,0)] = 0;
    states[State(0,1,1)] = 0;
    states[State(0,0,2)] = 0;
    return;
  }
  for(Children::iterator iter = children.begin(); iter != children.end(); iter++) {
    int child = *iter;
    stateTables.push_back(StateTable());
    computeStates(stateTables.back(), tree, child, n0, n1);
  }
  int n = sizes[root];
  for(int 
}

void computeTreeSize(const Tree &tree, int root, vector<int> &sizes) {
  sizes[root] = 1;
  Children children = tree[root].children;
  for(Children::iterator iter = children.begin(); iter != children.end(); iter++) {
    int child = *iter;
    computeTreeSize(tree, child, sizes);
    sizes[root] += sizes[child];
  }
}

int tree_unattractiveness(vector<int> &markers, Graph &graph) {
  int N = markers.size();
  if(N == 1) return 0;

  int n0, n1, n2;
  count_marker_types(markers, n0, n1, n2);

  // Only one type of marker? Of course 0.
  // if(zero == N || one == N || two == N) return 0;

  // // Markers contain only 0 and 1, or only 1 and 2, then must be 1.
  // if(zero == 0 || two == 0) return 1;

  // // Markers contain only 0 and 2, then must be 2.
  // if(one == 0) return 2;

  // Now, markers contain all 0, 1 and 2. The result is at least 1,
  // and at most 2. To find out which is the answer, consider if it
  // is possible to allocate 0s and 2s such that they do not reside
  // in the same edge. This is equivalent to the existence of an
  // edger e, which divides the tree into two subtrees T1 and T2,
  // such that |T1| >= n0, |T2| >= n2, and at least one inequality
  // holds.
  // vector<int> sizes(N+1, 0);
  // subtree_size(tree, sizes, 1, 0);
  // for(int i = 2; i <= N; i++) {
  //   if(sizes[i] >= zero && N-sizes[i] > two) return 1;
  //   if(sizes[i] > zero && N-sizes[i] >= two) return 1;
  //   if(sizes[i] >= two && N-sizes[i] > zero) return 1;
  //   if(sizes[i] > two && N-sizes[i] >= zero) return 1;
  // }
  // return 2;
  Tree tree(N+1);
  vector<int> sizes(N+1);
  graphToTree(tree, graph, 1);
  computeTreeSize(tree, 1, sizes);
  StateTable states;
  computeStates(states, tree, sizes, 1, n0, n1);
}

void input_tree(Graph &tree, int N) {
  for(int i = 0; i < N-1; i++) {
    int u, v;
    cin >> u >> v;
    tree[u].insert(v);
    tree[v].insert(u);
  }
}

void testcase() {
  int N;
  cin >> N;

  vector<int> markers(N);
  for(int i = 0; i < N; i++)
    cin >> markers[i];

  Graph tree(N+1);
  input_tree(tree, N);

  int result = tree_unattractiveness(markers, tree);
  cout << result << endl;
}

int main() {
  int T;
  cin >> T;
  for(int i = 0; i < T; i++)
    testcase();
  return 0;
}
