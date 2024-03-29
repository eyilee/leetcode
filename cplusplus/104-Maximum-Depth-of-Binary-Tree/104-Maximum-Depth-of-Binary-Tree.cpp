#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int x) : val (x), left (nullptr), right (nullptr) {}
};

class Solution
{
public:
    int maxDepth (TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        return max (maxDepth (root->left), maxDepth (root->right)) + 1;
    }
};

int main ()
{
    TreeNode* tree = new TreeNode (3);
    tree->left = new TreeNode (9);
    tree->right = new TreeNode (20);

    TreeNode* node20 = tree->right;
    node20->left = new TreeNode (15);
    node20->right = new TreeNode (7);

    Solution solution;
    cout << solution.maxDepth (tree) << endl;
}
