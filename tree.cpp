/* Leetcode questions for binary trees/binary search tree and their functional solutions*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), next(nullptr) {}
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

/*
https://leetcode.com/problems/merge-two-binary-trees/solution/

Merge two trees together
*/

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return nullptr;

    if (root1 == nullptr)
    {
        return root2;
    }
    else if (root2 == nullptr)
    {
        return root1;
    }
    else
    {
        TreeNode *newNode = new TreeNode();
        newNode->val = root1->val + root2->val;
        newNode->left = mergeTrees(root1->left, root2->left);
        newNode->right = mergeTrees(root1->right, root2->right);
        return newNode;
    }

    return nullptr;
}

/*
    https://leetcode.com/problems/maximum-depth-of-binary-tree/
    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
    */

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

/*
    https://leetcode.com/problems/diameter-of-binary-tree/
    Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
    This path may or may not pass through the root. 
*/

int diameterOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return max(height(root->left) + height(root->right), max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}

/*
   https://leetcode.com/problems/invert-binary-tree/
   Invert a binary tree
   */

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return root;
    invertTree(root->left);
    invertTree(root->right);
    TreeNode *temp;
    temp = root->right;
    root->right = root->left;
    root->left = temp;
    return root;
}

/*
    https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
    Use two queues to migrate to next levels
    */

TreeNode *connect(TreeNode *root)
{
    if (root == nullptr)
        return root;

    TreeNode *prev;
    queue<TreeNode *> l1;
    queue<TreeNode *> l2;

    l1.push(root);

    while (!(l1.empty() && l2.empty()))
    {
        prev = nullptr;
        while (!l1.empty())
        {
            TreeNode *front = l1.front();
            front->next = prev;
            l1.pop();
            prev = front;
            if (front->right != nullptr)
            {
                l2.push(front->right);
            }
            if (front->left != nullptr)
            {
                l2.push(front->left);
            }
        }

        prev = nullptr;
        while (!l2.empty())
        {
            TreeNode *front = l2.front();
            front->next = prev;
            l2.pop();
            prev = front;
            if (front->right != nullptr)
            {
                l1.push(front->right);
            }
            if (front->left != nullptr)
            {
                l1.push(front->left);
            }
        }
    }

    return root;
}

/*
https://leetcode.com/problems/symmetric-tree/submissions/
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/


bool isMirror(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    if (root1->val == root2->val)
    {
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
    return false;
}

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    return isMirror(root->left, root->right);
}
