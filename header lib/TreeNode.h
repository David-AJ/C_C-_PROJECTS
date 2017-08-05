#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

string tree2str(TreeNode* t) {
    string str = "";
    if(!t) return str;
    if(t->left || t->right){
        if(t->right) return str+to_string(t->val)+"("+tree2str(t->left)+")"+"("+tree2str(t->right)+")";
        else return str+to_string(t->val)+"("+tree2str(t->left)+")";
    }
    else return str+to_string(t->val);
}

void print(TreeNode* tree){
    printf("%s",tree2str(tree).c_str());
}