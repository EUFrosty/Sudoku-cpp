#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool isSafe(Sudoku &sudoku, int nodeIndex, int color){
    // Check that no branch connects two nodes of the same color
    for (const Branch &branch: sudoku.sudoku_graph.branches){
        if (branch.idx_1 == nodeIndex){
            if (sudoku.sudoku_graph.nodes[branch.idx_2].value == color)
                return false;
        }else if (branch.idx_2 == nodeIndex){
            if (sudoku.sudoku_graph.nodes[branch.idx_1].value == color)
                return false;
        }
    }
    return true;
}

bool nine_colorability_solve(Sudoku &sudoku, int nodeIndex = 0){
    // If all nodes are colored, the sudoku is solved
    if (nodeIndex == 81) return true;

    Node &node = sudoku.sudoku_graph.nodes[nodeIndex];
    // If the node is already colored, skip it
    if (node.value != 0){
        return nine_colorability_solve(sudoku, nodeIndex + 1);
    }

    // Otherwise we try every safe color
    for (int color = 1; color <= 9; ++color){
        if (isSafe(sudoku, nodeIndex, color)) {
            node.value = color;
            if (nine_colorability_solve(sudoku, nodeIndex + 1))
                return true;
            node.value = 0;
        }
    }
    return false;
}