#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

struct Node{
    char ch;            
    int freq;           
    Node* left;         
    Node* right;        
    Node(char c, int f):ch(c),freq(f),left(nullptr),right(nullptr){}
};

struct Compare{
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

Node* buildHuffmanTree(const unordered_map<char, int>& freqMap){
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    for (unordered_map<char,int>::const_iterator it=freqMap.begin();it!=freqMap.end();++it) {
        minHeap.push(new Node(it->first, it->second));
    }
    while (minHeap.size()>1){
        Node* left=minHeap.top();minHeap.pop();
        Node* right=minHeap.top();minHeap.pop();
        Node* parent=new Node('\0', left->freq + right->freq);
        parent->left=left;
        parent->right=right;
        minHeap.push(parent);
    }
    return minHeap.top();
}

void generateHuffmanCodes(Node* root,const string& code,unordered_map<char,string>& huffmanCode){
    if (!root) return;
    if (!root->left&&!root->right){
        huffmanCode[root->ch]=code;
    }
    generateHuffmanCodes(root->left,code+"0", huffmanCode);
    generateHuffmanCodes(root->right,code+"1", huffmanCode);
}

void deleteTree(Node* root){
    if (!root)return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main(){
    string S = "ABBADFKASDFAASDFSDDDSDA";
    unordered_map<char, int>freqMap;
    for (size_t i = 0; i < S.size(); ++i) {
        freqMap[S[i]]++;
    }
    cout<<"字符频次："<<endl;
    for (unordered_map<char, int>::iterator it=freqMap.begin();it !=freqMap.end();++it){
        cout << it->first<<":"<<it->second << endl;
    }
    Node* root = buildHuffmanTree(freqMap);
    unordered_map<char, string> huffmanCode;
    generateHuffmanCodes(root, "", huffmanCode);
    cout << "\n字符最优编码：" << endl;
    for (unordered_map<char, string>::iterator it = huffmanCode.begin(); it != huffmanCode.end(); ++it) {
        cout<<it->first<<": "<<it->second<<endl;
    }
    int totalLength = 0;
    for (size_t i = 0;i < S.size();++i){
        totalLength += huffmanCode[S[i]].size();
    }
    cout<<"\n最优编码后目标报文总长度："<<totalLength<< endl;
    string encoded = "";
    for (size_t i = 0; i < S.size(); ++i) {
        encoded += huffmanCode[S[i]];
    }
    cout << "\n编码后的目标报文：" << encoded << endl;
    string decoded = "";
    Node* current = root;
    for (size_t i = 0; i < encoded.size(); ++i) {
        if (encoded[i] == '0') {
            current=current->left;
        }else{
            current=current->right;
        }
        if (!current->left&&!current->right){
            decoded+=current->ch;
            current=root;
        }
    }
    cout << "\n解码后的源报文：" << decoded << endl;
    deleteTree(root);
    return 0;
}