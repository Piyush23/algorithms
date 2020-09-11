#include "iostream"
#include "bits/stdc++.h"
using namespace std;

int main(){
    int i = 8;
    int temp;
    //multiply by 2
    temp = i << 1;
    cout<<temp<<endl;

    //divide by 2
    temp = i >> 1;
    cout<<temp<<endl;

    //get last bit
    temp = i & 1;
    cout<<temp<<endl;

    //get nth bit
    int n = 4;
    temp = (i>>(n - 1)) & 1;
    cout<<temp<<endl;

    //set nth bit
    n = 2; temp=0;
    temp = temp | 1<<(n-1); 
    cout<<temp<<endl;

    //unset nth bit
    n = 2;
    temp = temp & 0<<(n-1);
    cout<<temp<<endl;

    //#of set bits
    temp = 23;//binary: 10111
    int cnt = 0;
    while(temp){
        if(temp & 1)
            cnt++;
        temp = temp>>1;
    }
    cout<<cnt<<endl;
    
    return 0;
}