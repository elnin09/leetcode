/* Leetcode questions for binary trees/binary search tree and their functional solutions*/

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


//Right side view of BST
    void rightSideViewHelper(TreeNode* root, int level, vector<int> &rightView)
    {
        if(root==nullptr) return ;
        
        if(level>rightView.size())
        {
           rightView.push_back(root->val);   
        }
        else
        {
          rightView[level-1]=root->val;   
        }
        rightSideViewHelper(root->left,level+1,rightView);
        rightSideViewHelper(root->right,level+1,rightView);
        
    }


    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> retval;
        rightSideViewHelper(root,1,retval);
        return retval;
            
    }
    

