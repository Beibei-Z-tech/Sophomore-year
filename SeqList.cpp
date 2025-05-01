#include <iostream>
using namespace std;

#define MAXSIZE 100 

typedef int ElemType; 

typedef struct {
    ElemType data[MAXSIZE]; 
    int length; 
} SqList;

void InitList(SqList &L) {
    L.length = 0;
}

void DestroyList(SqList &L) {
    L.length = 0; 
}

void ClearList(SqList &L) {
    L.length = 0;
}

void ListTraverse(SqList L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

bool GetElem(SqList L, int i, ElemType &e) {
    if (i < 1 || i > L.length) return false;
    e = L.data[i - 1];
    return true;
}

int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) return i + 1; 
    }
    return -1; 
}

bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1 || L.length == MAXSIZE) return false;
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

int ListLength(SqList L) {
    return L.length;
}

bool ListEmpty(SqList L) {
    return L.length == 0;
}

int main() {
    SqList L;
    InitList(L);

    for (int i = 1; i <= 5; i++) {
        ListInsert(L, 1, i);
    }
    ListTraverse(L); 

    ListInsert(L, 6, 6);
    ListTraverse(L);

    cout << "元素5的位置: " << LocateElem(L, 5) << endl;
    cout << "元素6的位置: " << LocateElem(L, 6) << endl;
    cout << "元素2的位置: " << LocateElem(L, 2) << endl;

    for (int i = 7; i <= 11; i++) {
        ListInsert(L, 2, i);
    }
    ListTraverse(L); 

    ElemType e;
    ListDelete(L, 1, e);
    cout << "删除的元素: " << e << endl;

    ListDelete(L, 1, e);
    cout << "删除的元素: " << e << endl;

    ListTraverse(L); 

    ListDelete(L, 9, e);
    cout << "删除的元素: " << e << endl;
    cout << "当前顺序表长度: " << ListLength(L) << endl;

    ListTraverse(L); 

    ClearList(L);
}