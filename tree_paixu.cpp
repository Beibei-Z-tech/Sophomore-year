#include <iostream>
using namespace std;
struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr){}
};
//插入操作
TreeNode* insert(TreeNode* root,int key){
    if (root==nullptr){
        return new TreeNode(key);
    }
    TreeNode* current=root;
    TreeNode* parent=nullptr;
    while (current !=nullptr){
        parent=current;
        if (key<current->value){
            current=current->left;
        }else{
            current=current->right;
        }
    }
    if(key<parent->value){
        parent->left=new TreeNode(key);
    }else{
        parent->right=new TreeNode(key);
    }
    return root;
}
//中序遍历
void inorderTraversal(TreeNode* root){
    if (root!=nullptr) {
        inorderTraversal(root->left);
        cout<<root->value<<" ";
        inorderTraversal(root->right);
    }
}
//查找操作
TreeNode* search(TreeNode* root, int key){
    while(root != nullptr){
        if(key == root->value){
            return root;
        }else if(key < root->value){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    return nullptr;
}
int main(){
    int keys[]={1, 53, 78, 65, 17, 87, 9, 81, 15};
    TreeNode* root=nullptr;

    for(int i=0;i<sizeof(keys)/sizeof(keys[0]);++i){
    root=insert(root, keys[i]);
}
    inorderTraversal(root);
    cout<<endl;
    
    TreeNode* result=search(root,15);
    if (result!=nullptr){
            cout<<"Found:"<<result->value<<endl;
        } else {
            cout << "Not found" << endl;
        }
    return 0;
}
