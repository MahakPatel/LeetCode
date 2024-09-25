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
private:
    stack<TreeNode*> st; // Creating stack for storing node
public:
    BSTIterator(TreeNode* root) {
        pushAll(root); // push all the node
    }

    int next() {
        TreeNode* temp =
            st.top(); // create temp node and store top of the stack
        st.pop();
        pushAll(temp->right); // push all the node of "left node" of right mode

        return temp->val; // return temp node value
    }

    bool hasNext() {
        return !st.empty(); // if stack is not emprt return true
    }

private:
    void pushAll(TreeNode* node) {
        for (; node != NULL; st.push(node), node = node->left)
            ; // push all the left side node into stack
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */