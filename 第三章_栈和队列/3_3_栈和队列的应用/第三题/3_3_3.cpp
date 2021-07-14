//
// Created by kaiven on 2021/7/14.
//

#include "../public.h"

/*
 * x是定值，而n是变量
 * 所以在递归栈中，只有n在变
 * 栈中存放的运算的结果
 * 最后输出栈底的结果
 *
 * */

struct stack{
    int n;              // 表示现在是n的大小
    int v;              // 表示现在pn的大小
}st[100];

int fun(int n, int x){
    int top = -1;               // 栈顶指针
    // 递归出口
    int fv1 = 1;
    int fv2 = 2*x;
    // 入栈
    for (int i = n; i >= 2; --i) {
        st[++top].n = i;
    }

    // 出栈, 但栈空的时候就找到了结果
    while (top >= 0){
        st[top].v = 2*x*fv2 - 2*(st[top].n-1)*fv1;
        fv1 = fv2;
        fv2 = st[top].v;
        top--;
    }

    if (n == 0) return 1;

    return fv2;
}

int main(){
    cout << fun(3, 1);
    return 0;
}