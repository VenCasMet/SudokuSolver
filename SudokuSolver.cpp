#include<bits/stdc++.h>
using namespace std;

bool valid(int ar[9][9],int a,int s,int c){
    for(int j=0;j<9;j++){
        if(ar[a][j]==c){
            return false;
        }
    }
    for(int j=0;j<9;j++){
        if(ar[j][s]==c){
            return false;
        }
    }
    for(int j=0;j<9;j++){
        if(ar[3*(a/3)+j/3][3*(s/3)+j%3]==c){
            return false;
        }
    }
    return true;
}

void print(int ar[9][9]){
    cout<<endl;
    for(int j=0;j<9;j++){
        for(int i=0;i<9;i++){
            cout<<ar[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool solve(int ar[9][9],int j,int i,int n){
    if(j==n){
        print(ar);
        return true;
    }
    if(i==n){
        return solve(ar,j+1,0,n);
    }
    if(ar[j][i]!=0){
        return solve(ar,j,i+1,n);
    }
    for(int k=1;k<=9;k++){
        if(valid(ar,j,i,k)){
            ar[j][i]=k;
            bool sub=solve(ar,j,i+1,n);
            if(sub){
                return true;
            }
        }
        ar[j][i]=0;
    }
    return false;
}

int main(){
    int board[9][9];
    for(int j=0;j<9;j++){
        for(int i=0;i<9;i++){
            cin>>board[j][i];
        }
    }
    int n=9;
    solve(board,0,0,n);
}