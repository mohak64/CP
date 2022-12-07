class Solution {
public:
     int sum = 0;
    void Preorder(TreeNode* root, int low, int high){
        if(root == NULL)
            return;
        if(root->val >= low && root->val <= high)
            sum +=root->val;
        
        Preorder(root->left, low, high);
        Preorder(root->right, low, high);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        Preorder(root, low, high);
        return sum;
    }
};
