#include "functions.h"


int main() {   
    int num_rows, num_cols, num_players, num_vertices;

    //Input of game data
    std::cin >> num_rows >> num_cols;
    std::cin >> num_players;

    std::vector<std::vector<int>> matrix(num_rows, std::vector<int>(num_cols));
    std::vector<int> players(num_players);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < num_players; i++) {
        int row, col;
        std::cin >> row >> col;
        players[i] = row * num_cols + col;
    }

    //Calculates the number of vertices
    num_vertices = num_rows * num_cols;

    std::vector<int> adj[num_vertices];

    //Creates the adjacency list
    create_adj_list(matrix, adj, num_rows, num_cols);

    play_game(matrix,adj,players, num_vertices);

    return 0;
}
