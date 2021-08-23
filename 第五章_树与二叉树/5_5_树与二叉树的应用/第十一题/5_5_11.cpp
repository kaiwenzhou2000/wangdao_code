//
// Created by kaiven on 2021/8/23.
//

#include "../public.h"

/*
 * 构造哈弗曼树
 * 并计算WPL
 *
 * */
BiTree make_haffman(int w[], int len){
    // 首先将节点全部创建
    BiTNode *p, *q, *t;
    int min_1 = maxN;      // 最小的元素, 初值为一个很大的数
    int min_1_index;
    int min_2 = maxN;      // 第二小的元素，初值为一个很大的数
    int min_2_index;
    int temp = len;

    BiTNode* a[len];
    for (int i = 0; i < len; ++i) {
        p = (BiTNode*)malloc(sizeof(BiTNode));
        p->data = w[i];
        p->lchild = nullptr;
        p->rchild = nullptr;
        a[i] = p;
    }

    // 不断的找出里面最小的节点，知道节点全部找完
    while (temp > 1){
        // 循环中不仅要保证数组没有越界，还要考虑是否已经节点已经使用过
        int i;
        for (i = 0; i < len; ++i) {
            if (a[i] == nullptr){
                continue;
            }
            if (a[i]->data < min_1){
                min_1 = a[i]->data;
                min_1_index = i;
                p = a[i];
            }
        }
        a[min_1_index] = nullptr;
        for (i = 0; i < len; ++i) {
            if (a[i] == nullptr){
                continue;
            }
            if (a[i]->data < min_2){
                min_2 = a[i]->data;
                min_2_index = i;
                q = a[i];
            }
        }
        a[min_2_index] = nullptr;

        t = (BiTNode*)malloc(sizeof(BiTNode));
        t->data = min_1+min_2;
        t->lchild = p;
        t->rchild = q;

        a[min_1_index] = t;;      // 放入新元素
        min_1 = maxN;
        min_2 = maxN;
        temp--;
    }
    return t;
}

int ans = 0;
void WPL(BiTree T, int level){
    if (T == nullptr){
        return;
    }

    WPL(T->lchild, level+1);
    WPL(T->rchild, level+1);

    if (T->lchild == nullptr && T->rchild == nullptr){
        // 叶结点
        ans += T->data*(level-1);
    }

}

int main(){
    int w[7] = {5, 7, 2, 3, 6, 8, 9};
    BiTree  T = make_haffman(w, 7);
    WPL(T, 1);
    cout << ans << endl;
    return 0;
}