#include "functions.h"

std::vector<std::vector<bool>> empty_visited_matrix (int num_rows, int num_cols) {
    return std::vector<std::vector<bool>> (num_rows, std::vector<bool>(num_cols, false));
}





void add_edge(std::vector<int> adj_list[], int vertex_1, int vertex_2) {
    adj_list[vertex_1].push_back(vertex_2); 
    adj_list[vertex_2].push_back(vertex_1); 
}





std::vector<int> find_adjacent_vertices(int current_row, int current_col, int num_rows, int num_cols,  int pos_value) {
    std::vector<int> dir_row = {0, 0, 1, -1};
    std::vector<int> dir_col = {1,-1, 0, 0};

    int next_row, next_col;
    std::vector<int> neighbours;

    for (int i = 0; i < 4; i++) {
        next_row = current_row + dir_row[i] * pos_value;
        next_col = current_col + dir_col[i] * pos_value;

        if (next_row < 0 || next_row >= num_rows || next_col < 0 || next_col >= num_cols) {
            continue;

        } else if (pos_value != 0) {
            neighbours.push_back(next_row * num_cols + next_col);
        } 
    }  
    return neighbours;
}






void create_adj_list(std::vector<std::vector<int>> input_matrix, std::vector<int> adj_list[], int num_cols, int num_rows) {

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {

            int id = i * num_cols + j;
            int pos_value = input_matrix[i][j];

            std::vector<int> neighbours = find_adjacent_vertices(i,j,num_rows, num_cols, pos_value);

            for (int k = 0; k < neighbours.size(); k++) {
                adj_list[id].push_back(neighbours[k]);
            }
        }
    }
}