#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

bool AlphabeticallySort(const char &ch1,const char &ch2){

    if(tolower(ch1)>tolower(ch2))
        return 0;
    if(tolower(ch1)<tolower(ch2))
        return  1;
    return ch1<ch2;
}


int main(){

int test;
char ch;
cin>>test;
getchar();
while(test--){
    vector<char> v;
    while((ch=getchar())!='\n'){
        v.push_back(ch);
    }
    sort(v.begin(),v.end(),AlphabeticallySort);
    do{

    for(int I=0;I<v.size();I++)
        cout<<v[I];
    cout<<endl;
    }while(next_permutation(v.begin(),v.end(),AlphabeticallySort));
}

return 0;
}
