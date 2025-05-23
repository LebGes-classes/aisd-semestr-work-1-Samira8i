#include "Cartesian_tree.h"
#include <iostream>

int main() {
    std::vector<std::pair<int, int>> data = {{3, 5}, {1, 9}, {4, 2}, {5, 7}, {2, 6}};
    
    CartesianTree tree(data);
    std::cout << "дерево в начале: ";
    tree.print();

    tree.insert(6, 4);
    std::cout << "После вставки 6: ";
    tree.print();

    tree.remove(3);
    std::cout << "После удаления 3: ";
    tree.print();

    std::cout << "Содержит 3? " << (tree.contains(4) ? "Да" : "Нет") << std::endl;
    std::cout << "Содержит 6? " << (tree.contains(7) ? "Да" : "Нет") << std::endl;

    return 0;
}