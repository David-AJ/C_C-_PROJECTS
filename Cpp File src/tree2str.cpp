#include<iostream>
#include<string>
using namespace std;



#define null  0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* array2tree(int ary[], int arySize, int index){
    if(index<arySize&&ary[index]){
        TreeNode* p = new TreeNode(ary[index]);
        p->left = array2tree(ary, arySize, 2*index+1);
        p->right = array2tree(ary, arySize, 2*index+2);
        return p;
    }
    return NULL;
}

string tree2str(TreeNode* t) {
    string str = "";
    if(!t) return str;
    if(t->left || t->right){
        if(t->right) return str+to_string(t->val)+"("+tree2str(t->left)+")"+"("+tree2str(t->right)+")";
        else return str+to_string(t->val)+"("+tree2str(t->left)+")";
    }
    else return str+to_string(t->val);
}

int main(){
    int ary1[] = {1,2,3,null,4};
    int ary2[] = {1,2,3,4};
    TreeNode* test1 = array2tree(ary1,5,0);
    TreeNode* test2 = array2tree(ary2,4,0);
    string str1 = tree2str(test1);
    string str2 = tree2str(test2);
    printf("[1,2,3,NULL,4]:\nexpect: 1(2()(4))(3)\nout:    %s\
    \n\n[1,2,3,4]:\nexpect: 1(2(4))(3)\nout:    %s",str1.c_str(),str2.c_str());
    return 0 ;
}

/* Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"

Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"   */