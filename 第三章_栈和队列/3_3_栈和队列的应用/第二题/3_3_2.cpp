//
// Created by kaiven on 2021/7/14.
//

#include "../public.h"

/*
 * 调度火车，S先出，H后出
 * 这道题遇到S就直接输出
 * 遇到H就进栈
 * 最后将栈清空
 *
 * */
bool train_plan(string train){
    stack_char S;
    stack_init(S);

    for (int i = 0; i < train.length(); ++i) {
        if (train[i] == 'S'){
            cout << train[i] << ' ';
        } else if (train[i] == 'H'){
            push(S,train[i]);
        } else{
            return false;
        }
    }

    char res;
    while (pop(S,res)){
        cout << res << ' ';
    }
    cout << endl;
    return true;
}


int main(){
    string train = "SSSHHHHHSSHH";
    train_plan(train);
    return 0;
}

