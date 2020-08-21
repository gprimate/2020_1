#include "functions.h"

std::vector<std::vector<bool>> empty_visited_matrix (int num_rows, int num_cols) {
    return std::vector<std::vector<bool>> (num_rows, std::vector<bool>(num_cols, false));
}

void find_adjacent_vertices(int current_row, int current_col, int num_rows, int num_cols,  int pos_value) {
    std::vector<int> dir_row = {0, 0, 1, -1};
    std::vector<int> dir_col = {1,-1, 0, 0};

    int next_row, next_col;

    for (int i = 0; i < 4; i++) {
        next_row = current_row + dir_row[i] * pos_value;
        next_col = current_col + dir_col[i] * pos_value;

        if (next_row < 0 || next_row >= num_rows || next_col < 0 || next_col >= num_cols) {
            continue;
        }

        std::cout << next_row << next_col << std::endl;
    }  
}