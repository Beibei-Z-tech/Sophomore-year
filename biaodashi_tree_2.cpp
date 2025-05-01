#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct TreeNode {
    char value;
    TreeNode *left, *right;
    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};
TreeNode* biaodashishu(const string& postfix) {
    stack<TreeNode*> nodes;
    for (size_t i=0;i<postfix.length(); ++i){
        char c=postfix[i];
        if (c=='+'||c=='-'||c=='*'||c=='/'){
            TreeNode* right=nodes.top();nodes.pop();
            TreeNode* left=nodes.top();nodes.pop();
            TreeNode* node=new TreeNode(c);
            node->left=left;
            node->right=right;
            nodes.push(node);
        } else {
            nodes.push(new TreeNode(c));
        }
    }
    return nodes.top();
}

void postorderTraversalNonRecursive(TreeNode* root){
    if (!root) return;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while (!s1.empty()){
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()){
        TreeNode* node=s2.top();
        s2.pop();
        cout << node->value << " ";
    }
}

int main() {
    string postfix = "abcd-ef/-";
    TreeNode* root = biaodashishu(postfix);
    cout << "Postorder traversal (non-recursive): ";
    postorderTraversalNonRecursive(root);
    cout << endl;
    return 0;
}
