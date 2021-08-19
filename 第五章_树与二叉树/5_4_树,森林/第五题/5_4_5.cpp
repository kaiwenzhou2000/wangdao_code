//
// Created by kaiven on 2021/8/19.
//

#include "../public.h"

/*
 * 求以孩子兄弟表示法存储的森林的叶子节点
 * 算法思想
 *  由于是通过孩子兄弟表示法存储，
 *  左指针指向的该节点的孩子，
 *  而叶子节点没有孩子，
 *  所以只需要寻找没有左指针的节点就可以了
 *  这里我采用先序遍历来遍历整颗二叉树
 *
 * */
int cnt = 0;
void find_leaves(CSTree T){
    if (T == nullptr){
        return;
    }
    if (T->firstchild == nullptr){
        cnt++;
    }
    find_leaves(T->firstchild);
    find_leaves(T->nextsibling);

}


int main(){
    CSTree T = get_CSTree();
    find_leaves(T);
    cout << cnt << endl;
    return 0;
}