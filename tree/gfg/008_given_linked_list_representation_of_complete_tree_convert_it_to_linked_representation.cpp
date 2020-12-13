#include "../../template.hpp"

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int value) : value(value), next(nullptr) {}
};

ListNode* MakeList(vi arr) {
    ListNode* head = nullptr;
    ListNode* node = nullptr;
    for (int v : arr) {
        if (head == nullptr) {
            head = new ListNode(v);
            node = head;
        }
        else {
            ListNode* current = new ListNode(v);
            node->next = current;
            node = current;
        }
    }
    return head;
}

void Inorder(TreeNode* root) {
    if (not root) return;
    Inorder(root->left);
    cout << root->value << ' ';
    Inorder(root->right);
}

TreeNode* Make(ListNode* head) {
    deque<TreeNode*> q;

    TreeNode* root = new TreeNode(head->value);
    q.push_back(root);
    head = head->next;

    while (not q.empty()) {
        TreeNode* node = q.front(); q.pop_front();
        if (head) {
            node->left = new TreeNode(head->value);
            q.push_back(node->left);
            head = head->next;
        }
        if (head) {
            node->right = new TreeNode(head->value);
            q.push_back(node->right);
            head = head->next;
        }
    }

    return root;
}

void ConstructCompleteBinaryTree(ListNode* head) {
    if (not head) return;
    Inorder(Make(head));
}

int main() { TimeMeasure _; __x();
    ListNode* head = MakeList({10, 12, 15, 25, 30, 36});
    ConstructCompleteBinaryTree(head); // 25 12 30 10 36 15
}
