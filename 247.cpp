#include<iostream>
#include<cstdio>
#include<map>
#include<string>
# include<vector>
#include<stack>
#include<queue>
using namespace std;

class Circle{
    map<string,int> M;
    map<string,int>::iterator it;

    vector<string> v[30];
    vector<int> Mat[30];
    vector<int>rMat[30];
    bool flag[30];
    string s1,s2;
    char ch,str[30];
    stack<int> s;
    vector<int> Q;
public:

    void clear(int node){
        node+=1;
        for(int I=0;I<node;I++)
            flag[I]=true;
        }

    void input(int node,int edge){
        int letter=0,n=0,f1,f2;
        clear(node);
        while(edge--){
            letter=0;
            while((ch=getchar())!=' ')
                str[letter++]=ch;

            str[letter++]='\0';
            s1=str;
            cin>>s2;
            getchar();
            if(!M[s1]){
                M[s1]=++n;
                v[n].push_back(s1);
                }
            if(!M[s2]){
                M[s2]=++n;
                v[n].push_back(s2);
                }
             f1=M.find(s1)->second;
             f2=M.find(s2)->second;
            Mat[f1].push_back(f2);
            rMat[f2].push_back(f1);

            }
        finding(node);
        //print();
        }

    void DFS(int node){
    flag[node]=false;
        for(int I=0;I<Mat[node].size();I++)
            if(flag[ Mat[node][I] ])
                DFS(Mat[node][I]);
    s.push(node);
    }

    void revDFS(int node){
    flag[node]=true;
        for(int I=0;I<rMat[node].size();I++)
            if(!flag[ rMat[node][I] ])
                revDFS(rMat[node][I]);
    Q.push_back(node);
    }

    void finding(int node){
        node+=1;
        for(int I=1;I<node;I++)
            if(flag[I])
                DFS(I);

        while(!s.empty()){
            if(!flag[s.top()]){
                revDFS(s.top());
                int I=0;
                for(I=0;I<Q.size()-1;I++)
                    cout<<v[Q[I]][0]<<", ";
                cout<<v[Q[I]][0]<<"\n";
                Q.clear();
                }
            s.pop();
            }

        }
    void print(){
        //map print
        for(it=M.begin();it!=M.end();it++)
            cout<<(*it).first<<"->"<<(*it).second<<endl;

        cout<<"Original Matrix:\n";
        for(int I=1;I<=M.size();I++){
            cout<<I<<" : ";
            for(int J=0;J<Mat[I].size();J++)
                cout<<Mat[I][J]<<" ";
            cout<<endl;
            }
        cout<<"\nReverse MAtrix:\n";
        for(int I=1;I<=M.size();I++){
            cout<<I<<" : ";
            for(int J=0;J<rMat[I].size();J++)
                cout<<rMat[I][J]<<" ";
            cout<<endl;
            }

        }
    };

int main(){

    int node,edge,I=0,J=0;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(scanf("%d %d",&node,&edge)==2&&node!=0){
    getchar();
    Circle call;
    if(J)
        printf("\n");
    cout<<"Calling circles for data set "<<++I<<":\n";
    call.input(node,edge);
    //<<endl<<;
    J++;
    }
    return 0;
    }