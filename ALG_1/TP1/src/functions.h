#include <string>
#include <iostream>
#include <vector>
#include <queue>

std::vector<int> find_adjacent_vertices(int current_row, int current_col, int num_rows, int num_col,  int pos_value);

void create_adj_list(std::vector<std::vector<int>> input_matrix, std::vector<int> adj_list[], int num_rows, int num_cols);

bool BFS(std::vector<int> adj_list[], int src, int num_vertices, int previous_vertex[], int distance_src[]);

std::vector<int> get_shortest_path(std::vector<int> adj_list[], int src, int num_vertices);

void play_game(std::vector<std::vector<int>> input_matrix, std::vector<int> adj_list[], std::vector<int> src ,int num_vertices);

int get_jump(std::vector<std::vector<int>> input_matrix, int src);