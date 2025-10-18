#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> get_next_variation(vector<int> variation){
    int n = variation.size();
    if (accumulate(variation.begin(), variation.end(), 0) < 9){
        vector<int> next_variation(n,1);
        return next_variation;
    }

    vector<int> next_variation = variation;
    for (int i = n-1; i >= 0; i--){
        if (next_variation[i] == 9){
            next_variation[i] = 0;
        }else{
            next_variation[i]++;
            break;
        }
    }
    return next_variation;
}

Sudoku fill_sudoku(Sudoku &sudoku, vector<int> &variation){
    int counter = 0;
    for (auto& node : sudoku.sudoku_graph.nodes){
        if (node.value == 0){
            node.value = variation[counter];
            counter++;
        }
    }
    return sudoku;
}

int get_num_of_zeros(Sudoku &sudoku){
    int counter = 0;
    for (auto& node: sudoku.sudoku_graph.nodes){
        if (node.value == 0){
            counter++;
        }
    }
    return counter;
}

Sudoku brute_force_solve(Sudoku sudoku){
    Sudoku potential_result = sudoku;
    int n = get_num_of_zeros(sudoku);
    vector<int> next_variation(n, 0);
    while (!potential_result.isSolved()){
        next_variation = get_next_variation(next_variation);
        Sudoku potential_result = fill_sudoku(sudoku, next_variation);
    }
    return potential_result;
}



