#ifndef CARTESIAN_TREE_H
#define CARTESIAN_TREE_H

#include <vector>
#include <utility>
//в основном везде написано именно про treap, но как я поняла надо было именно cartesian, поэтому реализовывала потсроение без рандома
struct Node {
    int key;         // Значение узла
    int priority;    // Приоритет для декартового дерева
    Node* left;     // Указатель на левое поддерево
    Node* right;    // Указатель на правое поддерево

    Node(int k, int p) : key(k), priority(p), left(nullptr), right(nullptr) {}
};

class CartesianTree {
private:
    Node* root;

    void clear(Node* node);
    void print(Node* node) const;
    Node* buildTree(std::vector<std::pair<int, int>>& data, int start, int end);
    std::pair<Node*, Node*> split(Node* node, int key); //основной метод
    Node* merge(Node* left, Node* right); //основной метод

public:
    CartesianTree();
    CartesianTree(std::vector<std::pair<int, int>> data);
    ~CartesianTree();

    void insert(int key, int priority);
    void remove(int key);
    bool contains(int key) const;
    void print() const;
};

#endif 