#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct BST{
    T value;
    BST* pr = nullptr;
    BST* left = nullptr;
    BST* right = nullptr;
    friend BST* insert(BST* node, T value) {
        if (node == nullptr) {
            node = new BST();
            node->value = value;
            node->left = node->right = nullptr;
            return node;
        }
        if (node->value < value){
            node->right = insert(node->right, value);
            node->right->pr = node;
        } else {
            node->left = insert(node->left, value);
            node->left->pr = node;
        }
        return node;
    }
    friend BST* find(BST* node, T value) {
        if (node == nullptr || node->value == value)
            return node;
        if (node->value < value)
            return find(node->right, value);
        return find(node->left, value);
    }
    friend pair<BST*, BST*> erase_max(BST* node) {
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
    friend BST* remove(BST* node) {
        if (node->left == nullptr)
            return node->right;
        if (node->right == nullptr) 
            return node->left;
            
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
    root = new BST<int>;
    root->value = -1e9;
    root->left = root->right = nullptr;
    root->pr = root;
    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        int cmd, x; cin >> cmd >> x;

        if (cmd == 1) {
            root = insert(root,x);
        }
        if (cmd == 2) {
            if (find(root, x) != nullptr) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        if (cmd == 3) {
            BST<int>* tmp = find(root,x);
            if (tmp != nullptr) {
                if (tmp->value <= tmp->pr->value)
                    tmp->pr->left = remove(tmp);
                else 
                    tmp->pr->right = remove(tmp);
            } else {
                //no node
            }
        }
    }
    


    return 0;
}