/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* getParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parentMap,int start){
        queue<pair<TreeNode*,TreeNode*>>q;
        TreeNode* startNode=NULL;
        q.push({root,NULL});

        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            TreeNode* node=curr.first;
            TreeNode* parent=curr.second;
            parentMap[node]=parent;
            if(node->val==start) startNode=node;

            if(node->left){
                q.push({node->left,node});
            }

            if(node->right){
                q.push({node->right,node});
            }
        }
        return startNode;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parentMap;
        TreeNode* startNode=getParent(root,parentMap,start);
        queue<TreeNode*>q;
        int minutes=0;
        unordered_map<TreeNode*,bool>visited;
        q.push(startNode);
        visited[startNode]=true;

        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    visited[node->left]=true;
                    q.push(node->left);
                }

                if(node->right && !visited[node->right]){
                    visited[node->right]=true;
                    q.push(node->right);
                }

                if(parentMap[node]!=NULL && !visited[parentMap[node]]){
                    visited[parentMap[node]]=true;
                    q.push(parentMap[node]);
                }

            }
            minutes++;
        }
        return minutes-1;
    }
};