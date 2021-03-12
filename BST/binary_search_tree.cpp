#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct BST{
    T value;
    BST* left = nullptr;
    BST* right = nullptr;
    BST* insert(BST* node, T value) {
        if (node == nullptr) {
            node = new BST();
            node->value = value;
            node->left = node->right = nullptr;
            return node;
        }
        if (node->value < value)
            node->right = insert(node->right, value);
        node->left = insert(node->left, value);
        return node;
    }
    BST* find(BST* node, T value) {
        if (node == nullptr || node->value == value)
            return node;
        if (node->value < value)
            return find(node->right, value);
        return find(node->left, value);
    }
    pair<BST*, BST*> erase_max(BST* node) {
        if (node == nullptr) 
            return {nullptr, nullptr};
        if (node->right == nullptr)
            return {node, node->left};
        pair<BST*, BST*> tmp = erase_max(node->right);
        BST* erased = tmp.first;
        BST* new_node = tmp.second;
        node->right = new_node;
        return {erased, node};
    } 
    BST* remove(BST* node) {
        if (node->left == nullptr){
            delete node;
            node = node->right;
            return node;
        }
        if (node->right == nullptr) {
            delete node;
            node = node->left;
            return node;
        }
        pair<BST*, BST*> tmp = erase_max(node->left);
        BST* erased = tmp.first;
        BST* new_left = tmp.second;
        node->left = new_left;
        swap(node->value, erased->value);
        delete erased;

        return node;
    }
};



int main() {

    BST<int> *root = nullptr;
    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        int cmd, x; cin >> cmd >> x;

        if (cmd == 1) {
            if (root == nullptr) {
                root = new BST<int>;
                root->value = x;
            } else {
                root->insert(root,x);
            }
        }
        if (cmd == 2) {
            if (root != nullptr && root->find(root, x) != nullptr) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        if (cmd == 3 && root != nullptr) {
            root->remove(root->find(root,x));
        }
    }
    


    return 0;
}