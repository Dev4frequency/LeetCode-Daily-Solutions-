class Solution {
public:

    
    TreeNode*construct(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int  inend,map<int,int>&inmap)
    {
        if(prestart>preend || instart>inend)
        {
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[prestart]);
        int inroot=inmap[root->val];
        int numsleft=inroot-instart;
        root->left=construct(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,inmap);
        root->right=construct(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,inmap);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        map<int,int>inmap;
        for(int i=0;i<preorder.size();i++)
        {
            inmap[inorder[i]]=i;

        }
        TreeNode*root=construct(preorder,0,preorder.size()-1,inorder,0,preorder.size()-1,inmap);
        return root;
        
        
        
    }
};