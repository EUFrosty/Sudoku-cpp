#include <iostream>
#include "./classes.cpp"
#include "./sudoku_arrays.cpp"
#include "./brute_force_solve.cpp"

using namespace std;

int main() {
    Graph g;
    g.generate_graph();
    g.fill_graph(sudoku_easy_1);

    Sudoku sudoku(g);
    sudoku.display();

    Sudoku solved = brute_force_solve(sudoku);
    solved.display();

    cout << "Total nodes: " << g.nodes.size() << endl;
    cout << "Total branches (edges): " << g.branches.size() << endl;
    if (solved.isSolved()){
        cout << "Solvable" << endl;
    }else{
        cout << "Not" << endl;
    }
    
    return 0;
}