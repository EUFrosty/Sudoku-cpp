#include <iostream>
#include "./classes.cpp"
#include "./sudoku_arrays.cpp"
#include "./brute_force_solve.cpp"
#include "./9_color_solve.cpp"

using namespace std;


int main() {
    Graph g;
    g.generate_graph();
    g.fill_graph(sudoku_easy_2);

    Sudoku sudoku(g);
    sudoku.display();

    // Sudoku solved = brute_force_solve(sudoku);
    // solved.display();

    nine_colorability_solve(sudoku);

    if (sudoku.isSolved()){
        sudoku.display();
    }else{
        cout << "This sudoku is not solvable." << endl;
    }
    
    return 0;
}