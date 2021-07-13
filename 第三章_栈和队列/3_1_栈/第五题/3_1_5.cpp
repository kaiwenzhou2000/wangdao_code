//
// Created by kaiven on 2021/7/12.
//

#include "../public.h"

#define maxSize 10

typedef struct share_stack{
    int s1;
    int s2;
    int data[maxSize];
}share_stack;

/*
 * 初始化
 * */
void share_stack_ini(share_stack &ss){
    ss.s1 = -1;
    ss.s2 = maxSize;
    for (int i = 0; i < maxSize; ++i) {
        ss.data[i] = -1;
    }
}

void show_share_stack(share_stack ss){
    for (int i = 0; i < maxSize; ++i) {
        cout << ss.data[i] << ' ';
    }
    cout << endl;
}

/*
 * 向s1或s2加入元素
 * */
bool push_s1(share_stack &ss, int e){
    if (ss.s2-ss.s1 == 1){
        // 说明栈已经满了
        return false;
    }

    // 向s1添加元素
    ss.data[++ss.s1] = e;
    return true;
}

bool push_s2(share_stack &ss, int e){
    if (ss.s2-ss.s1 == 1){
        // 说明栈已经满了
        return false;
    }

    // 向s1添加元素
    ss.data[--ss.s2] = e;
    return true;
}

/*
 * 在s1或s2弹出元素
 * 返回-1说明里面没有元素
 * */
int pop_s1(share_stack &ss){
    if (ss.s1 < 0){
        // 说明s1是空的
        return -1;
    }
    return ss.data[ss.s1--];
}

int pop_s2(share_stack &ss){
    if (ss.s2 < 0){
        // 说明s1是空的
        return -1;
    }
    return ss.data[ss.s2++];
}



int main(){
    share_stack ss;
    share_stack_ini(ss);
    push_s1(ss,1);
    push_s1(ss,1);
    push_s1(ss,1);
    push_s2(ss,2);
    push_s2(ss,2);
    push_s2(ss,2);
    show_share_stack(ss);
    return 0;
}
