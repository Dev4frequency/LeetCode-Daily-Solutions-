/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count=0;
    int averageOfSubtree(TreeNode* root) {
        average(root,count);
    return count;
    }
    private:
    void average(TreeNode* root, int& count){
        if(root==NULL){
            return;
        }
        int sum=0,n=0;
        traverse(root,sum,n);
       n=(n==0)?1:n;
       if(root->val==sum/n){
           count++;
       }
     
       average(root->left, count);
       average(root->right,count);

    }

    void traverse(TreeNode *root, int& sum,int& n){
        if(root==NULL){
            return;
        }
        traverse(root->left, sum,n);
        sum+=root->val;
        n++;
        traverse(root->right, sum,n);
    }
};