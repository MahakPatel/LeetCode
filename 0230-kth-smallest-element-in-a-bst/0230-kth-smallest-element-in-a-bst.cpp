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
class Solution {
public:
    //+++++++++++++++++ Optimal solution ++++++++++++++++
    int kthSmallest(TreeNode* root, int k) {
        int kSmallest = INT_MIN;
        // Counter to track visited nodes
        int counter = 0;

        // Find Kth smallest element
        // (perform inorder traversal)
        inorder(root, counter, k, kSmallest);

        // for kth largest
        //  // Reset counter for Kth largest element
        // counter = 0;
        // // Find Kth largest element
        // // (perform reverse inorder traversal)
        // reverseInorder(root, counter, k, kLargest);

        return kSmallest;
    }

    // for kth largest
    //     // Helper function to perform reverse inorder
    // // traversal to find Kth largest element
    // void reverseInorder(TreeNode* node, int& counter, int k, int& kLargest) {
    //     if (!node || counter >= k) return;

    //     // Traverse right subtree
    //     reverseInorder(node->right, counter, k, kLargest);

    //     // Increment counter after
    //     // visiting right subtree
    //     counter++;

    //     // Check if current node
    //     // is the Kth largest
    //     if (counter == k) {
    //         kLargest = node->val;
    //         return;
    //     }

    //     // Traverse left subtree if
    //     // Kth largest is not found yet
    //     reverseInorder(node->left, counter, k, kLargest);
    // }

    // Helper function to perform inorder
    // traversal to find Kth smallest element
    void inorder(TreeNode* node, int& counter, int k, int& kSmallest) {
        if (!node || counter >= k)
            return;

        // Traverse left subtree
        inorder(node->left, counter, k, kSmallest);

        // Increment counter after visiting left subtree
        counter++;

        // Check if current node is the Kth smallest
        if (counter == k) {
            kSmallest = node->val;
            return;
        }

        // Traverse right subtree if
        // Kth smallest is not found yet
        inorder(node->right, counter, k, kSmallest);
    }

    // +++++++++++++++++ Brute Force ++++++++++++++++++++
    // int kthSmallest(TreeNode* root, int k) {
    //     // Vector to store the
    //     // elements of the BST
    //     vector<int> arr;

    //     // Perform inorder traversal
    //     // to populate the vector
    //     inorder(root, arr);

    //     // Calculate Kth largest
    //     // and smallest elements
    //     // int kLargest = arr[arr.size() - k]; // for kth largest
    //     int kSmallest = arr[k-1];

    //     // Returning a pair containing
    //     // Kth smallest and largest elements

    //     return kSmallest;
    // }

    // // Inorder traversal to populate
    // // Used InOrder traversal because it gives sorted array
    // // the vector with BST elements
    // void inorder(TreeNode* node, vector<int>& arr){
    //     if(!node){
    //         return;
    //     }
    //     // Recursive call to the left subtree
    //     inorder(node->left, arr);

    //     // Push the value of current
    //     // node into the vector
    //     arr.push_back(node->val);

    //     // Recursive call to the right subtree
    //     inorder(node->right, arr);
    //     return;
    // }
};