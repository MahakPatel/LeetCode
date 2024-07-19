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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp; // for storing vertical ,level,nodes
        queue<pair<TreeNode*,pair<int,int>>> q; // for storing node,vertical,level
        q.push({root,{0,0}}); // push root

        while(!q.empty()){
            auto p = q.front(); // get the front of queue
            q.pop();

            TreeNode* node = p.first; // get front node
            int x = p.second.first; // get verticals
            int y = p.second.second; // get levels

            mp[x][y].insert(node->val); // put the node value in map at vertical and leb=vels
            if(node->left != NULL) q.push({node->left,{x-1,y+1}}); // if valid then push the node with vertical and level in queue
            if(node->right != NULL) q.push({node->right,{x+1,y+1}});// if valid then push the node with vertical and level in queue
        }
        vector<vector<int>> ans; // for storing ans
        for(auto p:mp){ // take value from map
            vector<int> col; // for storing vertical wise
            for(auto q:p.second){ // take level and nodes
                col.insert(col.end(),q.second.begin(),q.second.end()); // at every level we are putting node ex (-1 - 1 {9} -- vertical - level - node)
            }

            ans.push_back(col);
        }

        return ans;

    }
};