#include "functions.h"


std::vector<int> find_adjacent_vertices(int current_row, int current_col, int num_rows, int num_cols,  int pos_value) {

    //Possible directions to take in the game
    std::vector<int> dir_row = {-1, 0, 0, 1};
    std::vector<int> dir_col = {0,-1, 1, 0};

    int next_row, next_col;
    std::vector<int> neighbours;

    //Loop that tries to make moves in every direction
    for (int i = 0; i < 4; i++) {
        next_row = current_row + dir_row[i] * pos_value;
        next_col = current_col + dir_col[i] * pos_value;

        if (next_row < 0 || next_row >= num_rows || next_col < 0 || next_col >= num_cols) {
            continue;

        } else if (pos_value != 0) {
            neighbours.push_back(next_row * num_cols + next_col);
        } 
    }  
    //Returns a vector with all the possible moves
    return neighbours;
}





void create_adj_list(std::vector<std::vector<int>> input_matrix, std::vector<int> adj_list[], int num_rows, int num_cols) {

    //Loops through the entire input matrix and transforms it into an adjacency list
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {

            int id = i * num_cols + j;
            int pos_value = input_matrix[i][j];

            //Finds the possible moves
            std::vector<int> neighbours = find_adjacent_vertices(i,j,num_rows, num_cols, pos_value);

            //Adds the newly found moves to the adjacency list
            for (unsigned int k = 0; k < neighbours.size(); k++) {
                adj_list[id].push_back(neighbours[k]);
            }
        }
    }
}





bool BFS(std::vector<int> adj_list[], int src, int num_vertices, std::vector<int> & previous_vertex, std::vector<int> & distance_src) { 
    
    int dest = num_vertices - 1;
    std::queue<int> queue; 
    std::vector<bool> visited(num_vertices, false);
    
    //Initializes values for the source vertex
    visited[src] = true; 
    distance_src[src] = 0; 
    queue.push(src); 
    
    while (!queue.empty()) { 

        int current_vertex = queue.front();
        queue.pop(); 

        for (unsigned int i = 0; i < adj_list[current_vertex].size(); i++) { 
            
            //Checks if vertex was visited
            if (visited[adj_list[current_vertex][i]] == false) { 
                
                //Stores the distance from the source vertex and stores the previous vertex
                visited[adj_list[current_vertex][i]] = true; 
                distance_src[adj_list[current_vertex][i]] = distance_src[current_vertex] + 1; 
                previous_vertex[adj_list[current_vertex][i]] = current_vertex; 
                queue.push(adj_list[current_vertex][i]); 
  
                if (adj_list[current_vertex][i] == dest) 
                    return true; 
            } 
        } 
    } 
    return false; 
}





// Function that return the shortest path given a source vertex
std::vector<int> get_shortest_path(std::vector<int> adj_list[], int src, int num_vertices) { 
    
    int dest = num_vertices - 1;
    std::vector<int> pred(num_vertices,-1);
    std::vector<int> dist(num_vertices,-1);
    std::vector<int> path; 

    if (BFS(adj_list, src, num_vertices, pred, dist) == false) {   
        return path; 
    } 
  
    int crawl = dest; 
    path.push_back(crawl); 

    while (pred[crawl] != -1) { 
        path.push_back(pred[crawl]); 
        crawl = pred[crawl]; 
    } 

    return path;
} 





//Returns the number of jumps that a given vertex allows
int get_jump(std::vector<std::vector<int>> input_matrix, int src) {
    int num_cols = input_matrix[0].size();

    int row = int(src / num_cols);
    int col = src % num_cols;

    return input_matrix[row][col];
}





void play_game(std::vector<std::vector<int>> input_matrix, std::vector<int> adj_list[], std::vector<int> src ,int num_vertices) {

    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned int shortest_path_size = 0;
    int id_winner = -1;
    std::vector<int> path;
    

    for (unsigned int i = 0; i < src.size(); i++) {
        std::vector<int> path_try = get_shortest_path(adj_list, src[i], num_vertices);
        bool update = false;

        //Checks if path exists
        if (path_try.size() != 0) {
            if (shortest_path_size == 0) {
                update = true;

            } else if (path_try.size() < shortest_path_size) {
                update = true;

            //If a path is the same size as the smallest, checks which one of the two should be considered
            } else if (path_try.size() == shortest_path_size && shortest_path_size > 2) {
                int previous_jump = get_jump(input_matrix, path[2]);
                int current_jump = get_jump(input_matrix, path_try[2]);

                if (current_jump < previous_jump) {
                    update = true;
                }
            }

            //Updates variables of the funcion if one of the "if's" is successful
            if (update) {
                path = path_try;
                shortest_path_size = path.size();
                id_winner = i;
            }
        }
    }

    if (shortest_path_size == 0) {
        std::cout << "SEM VENCEDORES";
        
    } else {
        std::cout << letters[id_winner] << std::endl << shortest_path_size -1 << std::endl;
    }
}