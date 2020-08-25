#include "functions.h"


void testing_shit(std::vector<int> & my_vec) {
    my_vec[3] = 99;
}

int main() {   
    int num_rows, num_cols, num_players, num_vertices;

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
    
    num_vertices = num_rows * num_cols;

    std::vector<int> adj[num_vertices];

    
    
    create_adj_list(matrix, adj, num_rows, num_cols);

    play_game(matrix,adj,players, num_vertices);

    /*
    for (int i = 0; i < 12; i++) {
        std::cout << i << " -> ";

        for (int j = 0; j < adj[i].size(); j++) {
            std::cout << adj[i][j] << " ";
        }
        std::cout << std::endl;
    }  
    printShortestDistance(adj,6,12);
    */


    /*
    printShortestDistance(adj,2,9);

    std::vector<int> spath = get_shortest_path(adj,2,9);

    for (int i = 0; i < spath.size(); i++){
        std::cout << spath[i] << " ";
    }
    std::cout << std::endl;

    std::cout << spath.size() << std::endl;
    */
   

   

   























    // std::vector<std::vector<int>> gg(5, std::vector<int>(5, -1));


    
    
    /*
    std::vector<int> banana;
    banana.push_back(5);
    banana.push_back(6);
    std::cout << banana[0] << " " << banana[1] << std::endl;

    std::vector<int> morango = find_adjacent_vertices(0,0,4,6,6);

    for (int i = 0; i < morango.size(); i++) {
        std::cout << morango[i] << std::endl;
    }
    /*

    /*
    std::vector<std::vector<int>> matrix = { {0,1,2,3},
                                           {4,5,6,7}, 
                                           {8,9,10,11} };
    testing_shit(matrix);
    std::cout << matrix[0][1] << std::endl;


    int num_collumns, num_rows;
    int start_row, start_collumn;

    find_adjacent_vertices(0,0,4,4,2);

    std::vector<std::vector<bool>> bonitinho = empty_visited_matrix(6,4); 
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << bonitinho [i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    return 0;
}
