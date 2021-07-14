//
// Created by kaiven on 2021/7/13.
//

#include "iostream"

using namespace std;

#define maxSize 10

/*
 * 设计一个带tag的循环队列
 * */
typedef struct SqQueue_tag{
    int data[maxSize];
    int front;
    int rear;
    /*
     * 表示上次的操作
     * 1 表示上次是插入
     *  只有上一次是插入，才可能导致下一次会出现满的情况
     * 0 表示上次是删除
     *  只有上一次是删除，才可能导致下一次是空的情况
     * */
    int tag;
}SqQueue_tag;

void SqQueue_tag_init(SqQueue_tag &Q){
    Q.front = 0;
    Q.rear = 0;
    Q.tag = 0;
}

// 出队
bool deQueue(SqQueue_tag &Q, int &res){
    if (Q.front == Q.rear && Q.tag == 0){
        // 表示现在是空队列
        return false;
    }

    Q.tag = 0;
    res = Q.data[Q.front];
    Q.front = (Q.front+1)%maxSize;
    return true;
}

// 入队
bool enQueue(SqQueue_tag &Q, int e){
    if (Q.front == Q.rear && Q.tag == 1){
        // 表示现在是满的
        return false;
    }

    Q.tag = 1;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear+1)%maxSize;
    return true;
}

// 打印队列中的元素
void show_queue(SqQueue_tag Q){
    int res;
    while (deQueue(Q, res)){
        cout << res << ' ';
    }
}

int main(){
    int res;
    SqQueue_tag Q;
    SqQueue_tag_init(Q);
    enQueue(Q,1);
    enQueue(Q,2);
    enQueue(Q,3);
    deQueue(Q,res);
    show_queue(Q);

}


