//
// Created by kaiven on 2021/7/12.
//

#include "../public.h"

#define maxSize 100

/*
 * 判断对栈操作是否合法
 * */
bool is_legal(string str){
    int cnt = 0;
    for (int i = 0; i < str.length(); ++i) {
        // 操作cnt
        if (str[i] == 'I'){
            cnt++;
        } else{
            cnt--;
        }
        if (cnt < 0){
            return false;
        }
    }

    // 保证最后是空栈
    if (cnt == 0){
        return true;
    } else{
        return false;
    }
}

int main(){
    string str;
    cout << "请输入I/O" << endl;
    cin >> str;
    cout << is_legal(str) << endl;
    return 0;
}

