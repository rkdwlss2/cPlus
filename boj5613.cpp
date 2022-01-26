//
//  boj5613.cpp
//  boj1926bfs
//
//  Created by 강명진 on 2022/01/26.
//

#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum;
    cin>>sum;
    while(true){
        char eq;
        cin>>eq;
        if (eq=='='){
            break;
        }
        int num;
        cin>>num;
        
        if (eq=='+'){
            sum+=num;
        }else if (eq=='-'){
            sum-=num;
        }else if (eq=='*'){
            sum*=num;
        }else if (eq=='/'){
            sum/=num;
        }
    }
    cout<<sum<<'\n';
}

