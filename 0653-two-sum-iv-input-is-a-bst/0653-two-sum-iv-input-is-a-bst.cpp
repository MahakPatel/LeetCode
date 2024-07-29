/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class BSTIterator {
    stack<TreeNode*> st; // create empty stack

    // reverse = true -> before
    // reverse = false -> next

    bool reverse = true;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* tempNode = st.top(); // get stack top
        st.pop();

        if (!reverse) // if false push all  right node
            pushAll(tempNode->right);
        else
            pushAll(tempNode->left); // if true push all  left node

        return tempNode->val;
    }

private:
    void pushAll(TreeNode* node) {
        for (; node != NULL;) {
            st.push(node); // push node in to the stack
            if (reverse == true) // true move right
                node = node->right;
            else // if false move left
                node = node->left; 
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next(); // 1st index
        int j = r.next(); // 2nd index

        while (i < j) {
            if (i + j == k) // if same is equal to value 
                return true; // return true
            else if (i + j < k) // if same is less then value the move i because i has small value so if you move ith  next value then and then the sum will be greater
                i = l.next();
            else
                j = r.next();// if same is greater then value the move j because j has bigger value so if you move jth next value then and then the sum will be lesser

        }
        return false;
    }
};