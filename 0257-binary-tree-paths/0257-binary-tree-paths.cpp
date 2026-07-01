class Solution {
public:

    void dfs(TreeNode* root, string &path, vector<string>& ans) {

        if(root == NULL)
            return;

        int len = path.size();

        if(path.empty())
            path += to_string(root->val);
        else
            path += "->" + to_string(root->val);

        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
        }

        dfs(root->left, path, ans);
        dfs(root->right, path, ans);

        path.resize(len);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;
        string path = "";

        dfs(root, path, ans);

        return ans;
    }
};