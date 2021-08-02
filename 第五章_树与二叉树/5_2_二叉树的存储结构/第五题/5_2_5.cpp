//
// Created by kaiven on 2021/8/2.
//

#include "../public.h"


/*
 * a 表示用一维数组来存放二叉树
 * i 表示第一个传入的节点的位置
 * j 表示第二个传入的节点的位置
 *
 * 算法很简单，就是不断寻找祖先
 * 但是不同同时开始循环，因为这样会错过最近的公共父节点
 * 直到找到相同的祖先
 *
 * */
int find_common_parent(int a[], int i, int j){
    while(i != j){
        if (i > j){
            i /= 2;
        } else{
            j /= 2;
        }
    }
    return a[i];
}

int main(){
    int a[8];
    for (int i = 1; i <= 7; ++i) {
        a[i] = i;
    }

    cout << find_common_parent(a, 4, 6) << endl;

    return 0;
}
