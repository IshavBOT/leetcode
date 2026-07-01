/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getParent(TreeNode* root,unordered_map<TreeNode* ,TreeNode*>&parentMap){
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,NULL});
        while(!q.empty()){

            auto curr=q.front();
            q.pop();
            TreeNode* node=curr.first;
            TreeNode* parent=curr.second;
            parentMap[node]=parent;
            if(node->left){
                q.push({node->left,node});
            }

            if(node->right){
                q.push({node->right,node});
            }
            
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentMap;
        getParent(root,parentMap);

        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;

        while(!q.empty()){
            int n=q.size();
            int dist=q.front().second;
            if(dist==k) break;
            for(int i=0;i<n;i++){
                auto curr=q.front();
                q.pop();
                TreeNode* node=curr.first;
                int d=curr.second;
                visited[node]=true;

                if(node->left && !visited[node->left]){
                    q.push({node->left,d+1});
                }

                if(node->right && !visited[node->right]){
                    q.push({node->right,d+1});
                }

                if(parentMap[node]!=NULL && !visited[parentMap[node]]){
                    q.push({parentMap[node],d+1});
                }
            }
        }

        vector<int>ans;
        while(!q.empty()){
            TreeNode* ansnode=q.front().first;
            int value=ansnode->val;
            ans.push_back(value);
            q.pop();
        }

        return ans;

        
    }
};