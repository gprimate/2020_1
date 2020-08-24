#include <string>
#include <iostream>
#include <vector>
#include <queue>

std::vector<int> find_adjacent_vertices(int current_row, int current_col, int num_rows, int num_col,  int pos_value);

void add_edge(std::vector<int> adj_list[], int vertex_1, int vertex_2);

std::vector<std::vector<bool>> empty_visited_matrix (int num_rows, int num_cols);

void create_adj_list(std::vector<std::vector<int>> input_matrix, std::vector<int> adj_list[], int num_cols, int num_rows);