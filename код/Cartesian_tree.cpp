#include "Cartesian_tree.h"
#include <iostream>

void CartesianTree::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void CartesianTree::print(Node* node) const {
    if (node) {
        print(node->left);
        std::cout << node->key << "(" << node->priority << ") ";
        print(node->right);
    }
}

//рекурсивное построение использую
Node* CartesianTree::buildTree(std::vector<std::pair<int, int>>& data, int start, int end) {
    if (start > end) return nullptr;

    int maxIdx = start;
    for (int i = start + 1; i <= end; i++) {
        if (data[i].second > data[maxIdx].second) {
            maxIdx = i;
        }
    }

    Node* node = new Node(data[maxIdx].first, data[maxIdx].second);
    node->left = buildTree(data, start, maxIdx - 1);
    node->right = buildTree(data, maxIdx + 1, end);

    return node;
}

std::pair<Node*, Node*> CartesianTree::split(Node* node, int key) {
    if (!node) return {nullptr, nullptr};

    if (node->key < key) {
        auto [left, right] = split(node->right, key);
        node->right = left;
        return {node, right};
    } else {
        auto [left, right] = split(node->left, key);
        node->left = right;
        return {left, node};
    }
}

Node* CartesianTree::merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        return left;
    } else {
        right->left = merge(left, right->left);
        return right;
    }
}

CartesianTree::CartesianTree() : root(nullptr) {}

CartesianTree::CartesianTree(std::vector<std::pair<int, int>> data) {
    root = buildTree(data, 0, data.size() - 1);
}

CartesianTree::~CartesianTree() {
    clear(root);
}

void CartesianTree::insert(int key, int priority) {
    auto [left, right] = split(root, key);
    root = merge(merge(left, new Node(key, priority)), right);
}

void CartesianTree::remove(int key) {
    auto [left, temp] = split(root, key);
    auto [toDelete, right] = split(temp, key + 1);
    delete toDelete;
    root = merge(left, right);
}

bool CartesianTree::contains(int key) const {
    Node* current = root;
    while (current) {
        if (key == current->key) return true;
        current = key < current->key ? current->left : current->right;
    }
    return false;
}

void CartesianTree::print() const {
    print(root);
    std::cout << std::endl;
}