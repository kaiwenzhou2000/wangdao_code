//
// Created by kaiven on 2021/7/13.
//

#include "../public.h"

/*
 * 将队列中的元素通过栈转置
 * 将队列中的元素全部放置栈中
 * 然后再通过栈弹出到队列
 * */
void reverse_queue(SqQueue &Q){
    int res;
    SqStack S;
    SqStack_init(S);

    while(deQueue(Q,res)){
        push(S,res);
    }

    while (pop(S,res)){
        enQueue(Q,res);
    }
}


int main(){
    SqQueue Q;
    int a[3] = {1, 2, 3};
    make_queue(Q, a, 3);

    // 展示原来的队列
    cout << "原来的队列" << endl;
    show_queue(Q);
    reverse_queue(Q);
    // 展示转置之后的队列
    cout << "转置之后的队列" << endl;
    show_queue(Q);


    return 0;
}
