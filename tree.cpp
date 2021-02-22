/* Leetcode questions for binary trees/binary search tree and their functional solutions*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
  Right side view of BST idea is that leftmost element at ith level will first push[ith element] and then ultimately it will be replaced by
  rightmost element on ith level
*/
void rightSideViewHelper(TreeNode *root, int level, vector<int> &rightView)
{
    if (root == nullptr)
        return;

    if (level > rightView.size())
    {
        rightView.push_back(root->val);
    }
    else
    {
        rightView[level - 1] = root->val;
    }
    rightSideViewHelper(root->left, level + 1, rightView);
    rightSideViewHelper(root->right, level + 1, rightView);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> retval;
    rightSideViewHelper(root, 1, retval);
    return retval;
}
/* Second approach to find right side view*/
vector<int> rightSideView2(TreeNode *root)
{
    vector<int> retval;
    if (root == nullptr)
        return retval;

    //initialize nodes
    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    q1.push(root);

    while (!(q1.empty() && q2.empty()))
    {

        while (!q1.empty())
        {
            if (q1.size() == 1)
            {
                retval.push_back(q1.front()->val);
            }
            TreeNode *front = q1.front();
            if (front->left != nullptr)
                q2.push(front->left);
            if (front->right != nullptr)
                q2.push(front->right);
            q1.pop();
        }

        while (!q2.empty())
        {
            if (q2.size() == 1)
            {
                retval.push_back(q2.front()->val);
            }
            TreeNode *front = q2.front();
            if (front->left != nullptr)
                q1.push(front->left);
            if (front->right != nullptr)
                q1.push(front->right);
            q2.pop();
        }
    }
    return retval;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
