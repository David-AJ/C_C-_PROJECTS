#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<TreeNode.h>


struct TreeNode* A2B(int* nums, int start, int end){
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (start>end) return NULL;
    else {
        int mid = (end+start)/2;
        p->val = nums[mid];
        p->left = A2B(nums,start,mid-1);
        p->right = A2B(nums,mid+1,end);
    }
    return p;
}


int main(){
    int ary[] = {0,1,2,3};
    struct TreeNode* tree = A2B(ary,0,3);
    print(tree);
    return 0;
}
