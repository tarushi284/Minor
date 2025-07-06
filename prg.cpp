#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find LCA
TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == nullptr) return nullptr;

    if (root->val == n1 || root->val == n2)
        return root;

    TreeNode* leftLCA = findLCA(root->left, n1, n2);
    TreeNode* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

// an example of the tree
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int node1 = 4;
    int node2 = 5;

    TreeNode* lca = findLCA(root, node1, node2);

    if (lca != nullptr)
        cout << "LCA of " << node1 << " and " << node2 << " is: " << lca->val << endl;
    else
        cout << "LCA not found!" << endl;

    return 0;
}
