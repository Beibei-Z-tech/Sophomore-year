#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct TreeNode{
    char value;
    TreeNode *left, *right;
    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* biaodashitree(const string& postfix){
    stack<TreeNode*> nodes;
    for (size_t i = 0; i < postfix.length(); ++i){
        char c = postfix[i];
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

void preorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        cout << root->value << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversalNonRecursive(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        TreeNode* node = nodes.top(); nodes.pop();
        cout << node->value << " ";
        if (node->right) nodes.push(node->right);
        if (node->left) nodes.push(node->left);
    }
}

void inorderTraversalNonRecursive(TreeNode* root) {
    stack<TreeNode*> nodes;
    TreeNode* current = root;
    while (!nodes.empty() || current != nullptr) {
        if (current != nullptr) {
            nodes.push(current);
            current = current->left;
        } else {
            current = nodes.top(); nodes.pop();
            cout << current->value << " ";
            current = current->right;
        }
    }
}

void freeTree(TreeNode* root) {
    if (root != nullptr) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

int main() {
    string postfix = "abcd-*+ef/-";
    TreeNode* root = biaodashitree(postfix);

    cout << "Preorder traversal (recursive): ";
    preorderTraversal(root);
    cout << endl;

    cout << "Inorder traversal (recursive): ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal (non-recursive): ";
    preorderTraversalNonRecursive(root);
    cout << endl;

    cout << "Inorder traversal (non-recursive): ";
    inorderTraversalNonRecursive(root);
    cout << endl;

    freeTree(root);
    return 0;
}
