#include <iostream>
#include <stack>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(NULLptr), right(NULLptr) {}
 *     TreeNode(int x) : val(x), left(NULLptr), right(NULLptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorderResult;
        stack<TreeNode*> tStack;
        TreeNode* node = root;
        
        int lState = 100;
        int rState = 200;
        int upState = 300;
        int nodeState = lState;

        while(node != NULL)
        {
            if(nodeState == lState)
            {
                preorderResult.push_back(node->val);
                if(node->left != NULL)
                {
                    tStack.push(node);
                    node = node->left;
                }else
                {
                    nodeState = rState;
                }
            }
            else if(nodeState == rState)
            {
                // preorderResult.push_back(node.val);

                if(node->right != NULL)
                {
                    tStack.push(node);
                    node = node->right;
                    nodeState = lState;
                }else
                {
                    nodeState = upState;
                }
            }
            else if(nodeState == upState)
            {
                TreeNode* parent = NULL;

                if(!tStack.empty())
                {
                    parent = tStack.top();
                    tStack.pop();
                    if(parent->left == node)
                    {
                        nodeState = rState;
                    }
                }

                node = parent;
            }
        }

        return preorderResult;
    }
};