#include <iostream>
#include <vector>

using namespace std;

class Branch {
public:
    int idx_1;
    int idx_2;

    Branch(int one, int two) : idx_1(one), idx_2(two) {}
};

class Node {
public:
    int value;
    int index;

    Node(int val, int idx) : value(val), index(idx) {}
};

class Graph {
public:
    vector<Node> nodes;
    vector<Branch> branches;

    bool sameRow(int idx1, int idx2) {
        return (idx1 / 9) == (idx2 / 9);
    }

    bool sameColumn(int idx1, int idx2) {
        return (idx1 % 9) == (idx2 % 9);
    }

    bool sameBox(int idx1, int idx2) {
        int boxRow1 = (idx1 / 9) / 3;
        int boxCol1 = (idx1 % 9) / 3;
        int boxRow2 = (idx2 / 9) / 3;
        int boxCol2 = (idx2 % 9) / 3;
        return (boxRow1 == boxRow2) && (boxCol1 == boxCol2);
    }

    void generate_graph() {
        for (int i = 0; i < 81; i++) {
            nodes.push_back(Node(0, i));
        }

        for (int i = 0; i < 81; i++) {
            for (int j = i + 1; j < 81; j++) {
                if (sameRow(i, j) || sameColumn(i, j) || sameBox(i, j)) {
                    branches.push_back(Branch(i, j));
                }
            }
        }
    }

    void fill_graph(const std::vector<int>& values) {
        if (values.size() != 81) {
            throw std::invalid_argument("Input vector must have exactly 81 elements.");
        }
        for (int i = 0; i < 81; ++i) {
            nodes[i].value = values[i];
        }
    }
};

class Sudoku {
public:
    Graph sudoku_graph;
    Sudoku(Graph g) : sudoku_graph(g) {}

    bool isSolved(){
        for (auto& branch : sudoku_graph.branches){
            if (sudoku_graph.nodes[branch.idx_1].value == sudoku_graph.nodes[branch.idx_2].value || sudoku_graph.nodes[branch.idx_1].value == 0){
                return false;
            }
        }
        return true;
    }

    void display() {
        int counter = 0;
        for (auto& node : sudoku_graph.nodes) {
            if (counter % 27 == 0) {
                cout << " ----------------------------------------------  " << endl;
            }
            if(counter % 3 == 0){
                cout << " | ";
            }
            counter++;
            if (node.value != 0) {
                cout << "  " << node.value << " ";
            } else {
                cout << "  . ";
            }

            if (counter %  9 == 0) {
                cout << " | " << endl;
            }
            
        }
        cout << " ----------------------------------------------  " << endl;
    }
};

// int main() {
//     std::vector<int> puzzle = {
//         5,3,0, 0,7,0, 0,0,0,
//         6,0,0, 1,9,5, 0,0,0,
//         0,9,8, 0,0,0, 0,6,0,
//         8,0,0, 0,6,0, 0,0,3,
//         4,0,0, 8,0,3, 0,0,1,
//         7,0,0, 0,2,0, 0,0,6,
//         0,6,0, 0,0,0, 2,8,0,
//         0,0,0, 4,1,9, 0,0,5,
//         0,0,0, 0,8,0, 0,7,9
//     };

//     Graph g;
//     g.generate_graph();
//     g.fill_graph(puzzle);

//     Sudoku sudoku(g);
//     sudoku.display();

//     cout << "Total nodes: " << g.nodes.size() << endl;
//     cout << "Total branches (edges): " << g.branches.size() << endl;

//     return 0;
// }
