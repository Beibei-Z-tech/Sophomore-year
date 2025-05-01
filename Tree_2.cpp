#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    char value;
    TreeNode* left;
    TreeNode* right;
};
struct QueueNode{
    TreeNode* treeNode;
    QueueNode* next;
    QueueNode(TreeNode* node, QueueNode* nextNode) : treeNode(node), next(nextNode){}
};
class Queue{
public:
    Queue():front(nullptr),rear(nullptr){}
    void enqueue(TreeNode* node){
    QueueNode* newQueueNode=new QueueNode(node, nullptr);
    if(rear==nullptr){
        front=rear=newQueueNode;
    }else{
        rear->next=newQueueNode;
        rear=newQueueNode;
    }
}
    TreeNode* dequeue(){
        if(front==nullptr)return nullptr;
        TreeNode* node=front->treeNode;
        QueueNode* temp=front;
        front=front->next;
        if(front==nullptr)rear=nullptr;
        delete temp;
        return node;
    }
    bool isEmpty(){
        return front == nullptr;
    }
    ~Queue(){
        while(!isEmpty()){
            dequeue();
        }
    }
private:
    QueueNode* front;
    QueueNode* rear;
};
TreeNode* createNode(char value){
    TreeNode* newNode=new TreeNode();
    newNode->value=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

TreeNode* buildTreePreorder(const char pre[], const char in[], int qianxu, int preEnd, int inStart, int inEnd) {
    if(qianxu >preEnd||inStart>inEnd)
        return NULL;
    TreeNode* root=createNode(pre[qianxu]);
    int k;
    for(k=inStart;k<=inEnd;++k){
        if(in[k]==root->value)
            break;
    }
    int leftSize = k - inStart;
    root->left=buildTreePreorder(pre,in,qianxu+1,qianxu+leftSize,inStart,k-1);
    root->right=buildTreePreorder(pre,in,qianxu+leftSize+1,preEnd,k+1,inEnd);
    return root;
}
void destroyTree(TreeNode* node){
    if (!node)
        return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}
void levelOrderTraversal(TreeNode* root){
    if (!root) return;
    Queue queue;
    queue.enqueue(root);
    while (!queue.isEmpty()){
        TreeNode* node=queue.dequeue();
        cout<<node->value<<" ";
        if (node->left) queue.enqueue(node->left);
        if (node->right) queue.enqueue(node->right);
    }
}
int main(){
    const char preorder[]={'A','B','F','G','D','C','E'};
    const char inorder[]={'F','G','B','D','A','C','E'};
    TreeNode* root = buildTreePreorder(preorder,inorder,0,sizeof(preorder)/sizeof(preorder[0])-1,
                                        0, sizeof(inorder)/sizeof(inorder[0]) - 1);
    cout<<"层次遍历序列: ";
    levelOrderTraversal(root);
    cout<<endl;
    destroyTree(root);
    return 0;
}
