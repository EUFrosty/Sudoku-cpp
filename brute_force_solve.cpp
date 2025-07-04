#include <iostream>
#include <vector>

using namespace std;

Sudoku brute_force_solve(Sudoku sudoku){
    Sudoku result = sudoku;
    while (!result.isSolved()){
        result = next_variation(result);
    }

    return result;
}

vector<int> next_variation(vector<int> variation){

    vector<int> next_variation = variation;

    return next_variation;
}

Sudoku fill_sudoku(Sudoku sudoku, vector<int> variation){
    int counter = 0;
    for (auto& node : sudoku.sudoku_graph.nodes){
        if (node.value == 0){
            node.value = variation[counter];
            counter++;
        }
    }
    return sudoku;
}