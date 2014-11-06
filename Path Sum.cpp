/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    typedef struct _SumNode {
        int sum;
        TreeNode* node;
        _SumNode() {sum=0;node=NULL;}
    }SumNode;
    bool hasPathSum(TreeNode *root, int sum) {
        if (NULL == root)
            return false;
        std::stack<SumNode> stacks;
        
        TreeNode *cur = root;
        TreeNode *next = NULL;
        SumNode sumnode;
        sumnode.node = root;
        sumnode.sum = root->val;
        stacks.push(sumnode);
        while (!stacks.empty()) {
            SumNode& curnode = stacks.top();
            cur = curnode.node;

            bool back = false;
            if (sum == curnode.sum && cur->left == NULL && cur->right == NULL) {
                return true;
            } else {
                if (cur->left == NULL) {
                    if (cur->right == NULL)
                        back = true;
                    else
                        next = cur->right;
                } else {
                    next = cur->left;
                }
            } 
            
            if (back) {
                do {
                    SumNode& prevnode = stacks.top();
                    stacks.pop();
                    if (stacks.empty()) {
                        return false;
                    }
                    SumNode& nextnode = stacks.top();
                    if (nextnode.node->left == prevnode.node) {
                        if (nextnode.node->right){
                            SumNode sumnode;
                            sumnode.node = nextnode.node->right;
                            sumnode.sum = nextnode.sum+nextnode.node->right->val;
                            stacks.push(sumnode);
                            break;
                        }
                    }
                }while(true);
            } else {
                SumNode nextnode;
                nextnode.node = next;
                nextnode.sum = curnode.sum+next->val;
                stacks.push(nextnode);
            }
        }
        return false;
    }
};
