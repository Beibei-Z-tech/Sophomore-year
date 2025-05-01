#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct newStack{
    vector<int>stack;
    void putIn(int x){
        stack.push_back(x);
    }
    int takeOut(){
        if(stack.size()>0){
            int last=stack.back();
            stack.pop_back();
            return last;
        }
        return -1;
    }
    bool kong(){
        return stack.empty();
    }
};
int main(){
    string shupian;
    cin>>shupian; 
    newStack bigBro,lilBro;
    vector<char>snack; 
    int snackNum=0;
    int ren=0; 
    for(int p=0;p<shupian.size();p++){
        if(shupian[p]=='N'||shupian[p]=='S'){
            char what=shupian[p];
            p++;
            int howMany=0;
            while(p<shupian.size()&&isdigit(shupian[p])){
                howMany=howMany*10+(shupian[p]-'0');
                p++;
            }
            for(int q=0;q<howMany;q++){
                snack.push_back(what);
            }
        }
    }
    for(int i=snack.size()-1;i>=0;i--){
        snackNum++;
        if(snack[i]=='N'){
            cout<<snackNum<<"."<<(ren==0?"哥哥":"弟弟")<<"吃掉"<<snackNum<<"号普通薯片"<<endl;
        }
        else{
            cout<<snackNum<<"."<<(ren==0?"哥哥":"弟弟")<<"得到"<<snackNum<<"号特殊薯片"<<endl;
            if(ren==0){
                bigBro.putIn(snackNum);
            }
            else{
                lilBro.putIn(snackNum);
            }
        }
        ren=1-ren;
    }
    ren=0;
    while(!bigBro.kong()||!lilBro.kong()){
        if(ren==0&&!bigBro.kong()){
            int spSnack;
            spSnack=bigBro.takeOut();
            int snackNum_;
            snackNum_=++snackNum;
            cout<<snackNum_<<".弟弟拿出他面前的"<<spSnack<<"号特殊薯片,再次炫耀一番,并吃掉它"<<endl;
        }
    }
}