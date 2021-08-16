//
// Created by kaiven on 2021/8/15.
//

#include "../public.h"

/*
 * 满二叉树，知道先序，求后序序列
 *  pre[] 指的是先根遍历数组
 *  pre_start 指的是先根遍历当前子树的开始点
 *  pre_end 指的是先根遍历当前子树的结束点
 *  post[] 指的是后根遍历数组
 *  post_start 指的是后根遍历当前子树的开始点
 *  post_end 指的是后根遍历当前子树的结束点
 *
 *  算法思想：
 *      主要还是通过递归来完成，因为在先序遍历中，根节点永远是第一个
 *      然后后面集中跟着两块，一个是左子树，一个是右子树，然后就可以递归的确地其位置
 *      而在后序遍历中，正好与先序相反，根节点永远在最后一个
 *
 * */
void get_post_array(char pre[], int pre_start, int pre_end, char post[], int post_start, int post_end){
    if (pre_start > pre_end){
        return;
    }
    // 首先先将当前pre中第一个元素转移到，post的当前的最后一个位置上
    post[post_end] = pre[pre_start];
    // 下面对左右子树进行分割
    // 分割的临界点的是 half = (pre_end - pre_start)/2

    // 在pre中：
    //  - 左子树的第一个元素是pre_start+1, 最后一个元素是pre_start+half
    //  - 右子树的第一个元素是pre_start+half+1, 最后一个元素pre_end

    // post中：
    //  - 左子树的第一个元素post_start, 最后一个元素是post_start+half-1
    //      （half 表示的是左子树的长度）
    //  - 右子树的第一个元素是post_start+(half-pre_start), 最后一个元素是post_end-1
    int half = (pre_end - pre_start)/2;
    // 对左子树进行递归
    get_post_array(pre, pre_start+1, pre_start+half, post, post_start, post_start+half-1);
    // 对右边子树进行递归
    get_post_array(pre, pre_start+half+1, pre_end, post, post_start+half, post_end-1);
}


int main(){
    char pre_order_array[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char post_order_array[7];
    get_post_array(pre_order_array, 0, 6, post_order_array, 0, 6);
    for (int i = 0; i < 7; ++i) {
        cout << post_order_array[i] << ' ';
    }
    return 0;
}
