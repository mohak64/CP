// striver jod

int findMaxPathSum(node * root, int & maxi) {
  if (root == NULL) return 0;

  int leftMaxPath = max(0, findMaxPathSum(root -> left, maxi));
  int rightMaxPath = max(0, findMaxPathSum(root -> right, maxi));
  int val = root -> data;
  maxi = max(maxi, (leftMaxPath + rightMaxPath) + val);
  return max(leftMaxPath, rightMaxPath) + val;

}

int maxPathSum(node * root) {
  int maxi = INT_MIN;
  findMaxPathSum(root, maxi);
  return maxi;

}


// techdose

 int maxPathSum_util(TreeNode *root,int &result)
    {
        if(!root)
            return 0;
        
        int left = maxPathSum_util(root->left,result);
        int right = maxPathSum_util(root->right,result);
        
        int max_straight = max(max(left,right)+root->val, root->val);
        int max_caseVal = max(max_straight,left+right+root->val);
        result = max(max_caseVal,result);
        
        return max_straight;
    }
public:
    int maxPathSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int result = INT_MIN;
        maxPathSum_util(root,result);
        return result; 
    }
