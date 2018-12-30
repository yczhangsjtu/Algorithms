#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct TreeNode {
  int count;
  int children[26];
  TreeNode(): count(0) {
    for(int i = 0; i < 26; i++)
      children[i] = 0;
  }
} TreeNode;
typedef vector<TreeNode> Tree;

void addWord(Tree &tree, const string &s) {
  if(tree.empty()) tree.push_back(TreeNode());
  int curr = 0;
  tree[curr].count++;
  for(int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    if(!tree[curr].children[c]) {
      tree[curr].children[c] = tree.size();
      tree.push_back(TreeNode());
    }
    curr = tree[curr].children[c];
    tree[curr].count++;
  }
}

int countPrefix(Tree &tree, const string &s) {
  int curr = 0;
  for(int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    if(!tree[curr].children[c]) return 0;
    curr = tree[curr].children[c];
  }
  return tree[curr].count;
}

int main() {
  int n;
  Tree tree;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    addWord(tree, s);
  }

  int m;
  cin >> m;
  for(int i = 0; i < m; i++) {
    string s;
    cin >> s;
    cout << countPrefix(tree, s) << endl;
  }

	return 0;
}
