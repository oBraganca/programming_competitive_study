

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool cl = true, cr = true;
        if(p == NULL && q == NULL){
            return true;
        }
        if(p != NULL && q != NULL && p->val == q->val){
            cl = isSameTree(p->left, q->left);
            cr = isSameTree(p->right, q->right);
            return cl && cr;
        }
        return false;
    }
};