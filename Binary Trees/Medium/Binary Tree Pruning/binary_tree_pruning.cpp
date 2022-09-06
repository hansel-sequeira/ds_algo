/*
Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.

 

Example 1:


Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
Example 2:


Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
Example 3:


Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
 

Constraints:

The number of nodes in the tree is in the range [1, 200].
Node.val is either 0 or 1.
*/

//inoptimal two pass, O(n) space soln:
class Solution {
    
private: unordered_set<TreeNode*> uset;
    
public:
    
    bool containsOne(TreeNode* root){
        if(root == NULL)
            return false;
        bool left = containsOne(root->left);
        bool right = containsOne(root->right);
        bool res = false;
        if(left || right || root->val == 1){
            res = true;
            uset.insert(root);
        }
        return res;
    }
    
    
    TreeNode* helper(TreeNode* root){
        if(root == NULL || uset.find(root)==uset.end())
            return NULL;
        root->left = helper(root->left);
        root->right = helper(root->right);
        return root;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        containsOne(root);
        return helper(root);
    }
};


//optimal one pass, O(1) space soln (not counting the recursive stack space)
class Solution {    
public:

    TreeNode* helper(TreeNode* root){
        if(root == NULL)
            return NULL;
        root->left = helper(root->left);
        root->right = helper(root->right);
        if(!root->left and !root->right){
            return (root->val == 1) ? root : NULL;
        }
        return root;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return helper(root);
    }
};
