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
private:
    TreeNode* first; // first violation
    TreeNode* prev; // for previous node
    TreeNode* middle; // next node of first violation
    TreeNode* last; // last or second violation

private:
// to convert into inorder traversal
void inorder(TreeNode* root){
    if(root == NULL) return; // base case

    inorder(root->left); // move left

    if(prev !=  NULL && (root->val < prev->val)){ // if current value is less then previuos one

    // if it is first violation then assign first with prev node and current node to middle
        if(first == NULL){ 
            first = prev;
            middle = root;
    // if last violation then assign last to current node
        }else{
            last = root;
        }
    }

    prev = root; // move prev to current node
    inorder(root->right); // move right
}

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL; // atfirst all are NULL
        prev = new TreeNode(INT_MIN); // atfirst previous is always out of range(-1)

        inorder(root);

        if(first && last) swap(first->val,last->val); // if first and last is violated then swap them with each other
        else if(first && middle) swap(first->val,middle->val);    // if first and middle if violated then swap each other     
    }
};