

// this one is O(n^2)
int helper(TreeNode *root){
    if(root==NULL){
        return 0;
    }

    return 1+max(helper(root->left),helper(root->right));
}

bool balanced(TreeNode *root){
    if(root == NULL){
        return true;
    }

    int left_height = helper(root->left);
    int right_height = helper(root->right);

    if(balanced(root->right) && balanced(root->right) && abs(left_height-right_height)<=1){
        return true;
    }

    return false;
}

// O(n)-

bool balanced(TreeNode *root, int &height){
    if(root==NULL){
        return true;
    }

    int lh = 0, rh = 0;
    
    bool l = balanced(root->right,lh);
    bool r = balanced(root->left,rh);

    height = 1+max(lh,rh);

    if(abs(lh-rh)>=2){
        return false;
    }

    else{
        return l && r;
    }
}
bool isbalanced(TreeNode* root){
    int height=0;
    return balanced(root,height);
}
