class Solution {
public:
    int count = 0;
    int status = 5;
    TreeNode* parent = NULL;
    
    
    int minCameraCover(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) return 1;
        
        return dfs(root, parent);
    }
    
    
    int dfs(TreeNode* node, TreeNode* parent) {
        
        if (node->left == NULL && node->right == NULL) {
            if (node->val == 1)
                return 0;      // Leaf Node but covered
            return -1;      // Leaf Node
        }
        
        if (node->left != NULL) {
            status = dfs(node->left, node);

            if (status == -1) {
                node->val = 1;
                if (node->left != NULL) node->left->val = 1;
                if (node->right != NULL) node->right->val = 1;
                if (parent != NULL) parent->val = 1;

                count++;
            }
        }
        
        if (node->right != NULL) {
            status = dfs(node->right, node);

            if (status == -1) {
                node->val = 1;
                if (node->left != NULL) node->left->val = 1;
                if (node->right != NULL) node->right->val = 1;
                if (parent != NULL) parent->val = 1;

                count++;
                
                if (parent == NULL) return count;
                
                return 0;
            }
        }
        
        if (status == 0) {
            if (parent == NULL && node->val == 0) {
                count++;
                return count;
            } else if (parent == NULL && node->val == 1) {
                return count;
            }
            
            if (node->val == 1) return 0;
            else if (node->val == 0) return -1;      // -1 here means cover this one
        }
        
        if (parent == NULL) return count;
        
        return 0;
    }
};