#include<iostream>

using namespace std;

int main(){
    for(int i=1;i<9;i++){
        for(int j=9;j>i;j--){
            cout<<i<<'X'<<j<<'='<<i*j<<' ';
        }
        cout<<i<<'X'<<i<<'='<<i*i<<endl;
    }
    cout <<"9X9=81";
    
    return 0;
}