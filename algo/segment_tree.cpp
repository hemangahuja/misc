struct Tree{
    int val;
    Tree *left;
    Tree *right;
    Tree(){this->val = 0; this->left = nullptr; this->right = nullptr;}
    Tree(int val){this->val = val; this->left = nullptr; this->right = nullptr;}
};


class NumArray {
    vector<int> nums;
    Tree *root;
public:
    Tree *build(Tree *root, int left, int right){
        if(left == right){
            root = new Tree(nums[left]);
            return root;
        }
        root = new Tree();
        int mid = (left + right) / 2;
        root->left = build(root->left , left , mid);
        root->right = build(root->right, mid + 1, right);
        root->val = root->left->val + root->right->val;
        return root;
    }
    int query(Tree *root, int left, int right, int start, int end){  
        if(end < left || start > right) return 0;
        if(start == end) return root->val;
        if(left <= start && end <= right){
            return root->val;
        }
        int mid = (start + end) / 2;
        int leftAns = query(root->left , left , right , start , mid);
        int rightAns = query(root->right , left, right, mid + 1, end);
        return leftAns + rightAns;
    }
    void updateInternal(Tree *root, int start, int end, int idx, int val, int old){
        int mid = (start + end) / 2;
        if(start == end){
            root->val = val;
        }
        else if(mid >= idx){
            updateInternal(root->left,start, mid , idx, val, old);
            root->val += (val - old);
        } else {
            updateInternal(root->right,mid + 1, end, idx , val, old);
            root->val += (val - old);
        }
    }
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->root = build(this->root,0,nums.size() - 1);
    }
    
    void update(int index, int val) {
        updateInternal(root, 0 , nums.size() - 1, index, val, nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return query(root,left,right,0,nums.size() - 1);
    }
};
