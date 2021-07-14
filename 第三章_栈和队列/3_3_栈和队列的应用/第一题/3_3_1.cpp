//
// Created by kaiven on 2021/7/14.
//

#include "../public.h"

char mapping(char a){
    if (a == '{'){
        return '}';
    } else if (a == '['){
        return ']';
    } else if(a == '('){
        return ')';
    }
    return '\0';
}

/*
 * 遇到左括号压入栈内
 * 遇到右括号，看看第一个弹出的是不是这个右括号对应的括号
 * */
bool matching(char str[]){
    int i = 0;
    stack_char S;
    stack_init(S);

    while (str[i] != '\0'){
        if (str[i] == '{' || str[i] == '[' || str[i] == '('){
            push(S,str[i]);
        } else if (str[i] == '}' || str[i] == ']' || str[i] == ')'){
            char temp;
            // 放置栈为空的情况
            if (!pop(S, temp)){
                return false;
            }

            if (mapping(temp) != str[i]){
                return false;
            }
        } else{
            return false;
        }
        i++;
    }

    // 最后要判断栈里面的括号有没有弹出完毕
    if (S.top == -1){
        return true;
    } else{
        return false;
    }
}

int main(){
    char str[] = "{{[{}]}}";
    cout << matching(str) << endl;
    return 0;
}
