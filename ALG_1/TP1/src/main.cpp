#include "functions.h"


void testing_shit(std::vector< std::vector<int> >& my_vec) {
    my_vec[0][1] = 99;
}

int main() {   
   
    std::vector<int> adj[9];
  
    
    std::vector<std::vector<int>> matrix = {{2,1,0},
                                            {0,1,1}, 
                                            {2,2,0} };
    
    create_adj_list(matrix,adj,3,3);

    for (int i = 0; i < 9; i++) {
        std::cout << i << " -> ";

        for (int j = 0; j < adj[i].size(); j++) {
            std::cout << adj[i][j] << " ";
        }
        std::cout << std::endl;
    }  
    
 
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
