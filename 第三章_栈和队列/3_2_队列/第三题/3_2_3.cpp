//
// Created by kaiven on 2021/7/13.
//

#include "../public.h"

/*
 * 用两个栈来模拟队列
 * s1用来存放元素
 * s2用来输出元素
 *
 * */

// 判断是否为空
bool QueueEmpty(SqStack s1, SqStack s2){
    if (is_empty_stack(s1) && is_empty_stack(s2)){
        return true;
    }
    return false;
}

// 判断是否满
bool QueueFull(SqStack s1, SqStack s2){
    if (is_full_stack(s1) && is_full_stack(s2)){
        return true;
    }
    return false;
}


// 入队
bool Enqueue(SqStack &s1, SqStack &s2, int e){
    // 查看是否已满
    if (QueueFull(s1, s2)){
        return false;
    }
    // 先推入s1
    push(s1,e);

    // 当s1满了，但是s2不是空的，不能再加元素的了
    if (is_full_stack(s1) && !is_empty_stack(s2)){
        return false;
    }

    // 当s1满了之后，且s2是空的，全部放入s2
    if (is_full_stack(s1) && is_empty_stack(s2)){
        int res;
        while (pop(s1, res)){
            push(s2, res);
        }
    }

    return true;
}


// 出队
bool Dequeue(SqStack &s1, SqStack &s2, int &res){
    // 查看是不是空的
    if (QueueEmpty(s1, s2)){
        return false;
    }

    // s2是空且s1不为空的情况下，需要将s1中的元素转移到s2中
    if (is_empty_stack(s2)){
        int temp;
        while (pop(s1, temp)){
            push(s2, temp);
        }
    }

    // 要是s2中有元素，直接弹出s2中的元素
    pop(s2, res);

    return true;
}

int main(){
    SqStack s1;
    SqStack s2;
    SqStack_init(s1);
    SqStack_init(s2);
    Enqueue(s1, s2, 1);
    Enqueue(s1, s2, 2);
    Enqueue(s1, s2, 3);
    Enqueue(s1, s2, 4);
    int res;
    Dequeue(s1, s2, res);
    cout << res << endl;
    Dequeue(s1, s2, res);
    cout << res << endl;
    Dequeue(s1, s2, res);
    cout << res << endl;

    Enqueue(s1, s2, 5);
    Dequeue(s1, s2, res);
    cout << res << endl;
    Dequeue(s1, s2, res);
    cout << res << endl;

    return 0;
}

