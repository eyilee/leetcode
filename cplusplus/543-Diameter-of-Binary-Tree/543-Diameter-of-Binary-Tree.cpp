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
    int diameterOfBinaryTree (TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        diameter = 0;

        maxDepth (root);

        return diameter;
    }

    int maxDepth (TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        int left = maxDepth (root->left);
        int right = maxDepth (root->right);
        diameter = max (diameter, left + right);

        return max (left, right) + 1;
    }
private:
    int diameter;
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
    cout << solution.diameterOfBinaryTree (tree) << endl;
}
