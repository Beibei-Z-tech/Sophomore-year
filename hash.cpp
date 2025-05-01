#include <iostream>
#include <vector>
#include <list>
using namespace std;
vector<list<int> > hashTable(5); 
int hashFunction(int key){
    return key % 5;
}
void insert(int key){
    int index = hashFunction(key);
    hashTable[index].push_back(key);
}
void printHashTable(){
    cout << "哈希表内容：" << endl;
    for (int i = 0; i < hashTable.size(); ++i) {
        cout << "Bucket"<<i<<":";
        for (list<int>::iterator it=hashTable[i].begin();it!=hashTable[i].end(); ++it) {
            cout<<*it<<"->";
        }
        cout<< "NULL"<<endl;
    }
}
int main(){
    int keys[]={17, 29, 33, 12, 89, 25, 26, 77, 15, 55};
    int n=sizeof(keys)/sizeof(keys[0]);
    for (int i = 0; i < n; ++i) {
        insert(keys[i]);
    }
    printHashTable();
    return 0;
}
