#include <iostream>
using namespace std;

struct TreeNode{
    char value;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* createNode(char value){
    TreeNode* newNode=new TreeNode();
    newNode->value=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
TreeNode* buildTreePreorder(const char pre[],const char in[],int qianxu, int preEnd, int inStart, int inEnd) {
    if (qianxu>preEnd||inStart>inEnd)
        return NULL;
    TreeNode* root=createNode(pre[qianxu]);
    int k;
    for (k=inStart;k<=inEnd;++k){
        if (in[k]==root->value)
            break;
    }
    int leftSize=k-inStart;
    root->left=buildTreePreorder(pre,in,qianxu+1,qianxu+leftSize,inStart,k - 1);
    root->right=buildTreePreorder(pre,in,qianxu+leftSize+1,preEnd,k + 1,inEnd);
    return root;
}

void inorderTraversal(TreeNode* node){
    if (!node)
        return;
    inorderTraversal(node->left);
    cout << node->value << " ";
    inorderTraversal(node->right);
}
void postorderTraversal(TreeNode* node){
    if (!node)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout<<node->value<<" ";
}

void destroyTree(TreeNode* node) {
    if (!node)
        return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}
int main(){
    const char preorder[] = {'A','B','F','G','D','C','E'};
    const char inorder[] = {'F','G','B','D','A','C','E'};
    TreeNode* root=buildTreePreorder(preorder,inorder,0,sizeof(preorder)/sizeof(preorder[0])-1,
                                        0, sizeof(inorder)/sizeof(inorder[0]) - 1);
    cout<<"中序序列:";
    inorderTraversal(root);
    cout<<endl;
    cout<<"后序序列: ";
    postorderTraversal(root);
    cout<<endl;
    destroyTree(root);
    return 0;
}
