#include "functions.h"

std::vector<std::vector<bool>> empty_visited_matrix (int num_rows, int num_cols) {
    return std::vector<std::vector<bool>> (num_rows, std::vector<bool>(num_cols, false));
}





void add_edge(std::vector<int> adj_list[], int vertex_1, int vertex_2) {
    adj_list[vertex_1].push_back(vertex_2); 
    adj_list[vertex_2].push_back(vertex_1); 
}





std::vector<int> find_adjacent_vertices(int current_row, int current_col, int num_rows, int num_cols,  int pos_value) {
    std::vector<int> dir_row = {-1, 0, 0, 1};
    std::vector<int> dir_col = {0,-1, 1, 0};

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




bool BFS(std::vector<int> adj_list[], int src, int num_vertices, std::vector<int> & previous_vertex, std::vector<int> & distance_src) { 
    
    int dest = num_vertices - 1;
    std::queue<int> queue; 
    std::vector<bool> visited(num_vertices, false);
 
    visited[src] = true; 
    distance_src[src] = 0; 
    queue.push(src); 
  
    while (!queue.empty()) { 

        int u = queue.front(); 
        queue.pop(); 

        for (int i = 0; i < adj_list[u].size(); i++) { 

            if (visited[adj_list[u][i]] == false) { 

                visited[adj_list[u][i]] = true; 
                distance_src[adj_list[u][i]] = distance_src[u] + 1; 
                previous_vertex[adj_list[u][i]] = u; 
                queue.push(adj_list[u][i]); 
  
                if (adj_list[u][i] == dest) 
                    return true; 
            } 
        } 
    } 
    return false; 
}





void printShortestDistance(std::vector<int> adj[], int s, int dest, int v) { 
    // predecessor[i] array stores predecessor of 
    // i and distance array stores distance of i 
    // from s 
    std::vector<int> pred(v,-1);
    std::vector<int> dist(v,-1);

  
    if (BFS(adj, s, v, pred, dist) == false) { 
        std::cout << "Given source and destination"
             << " are not connected"; 
        return; 
    } 
  
    // vector path stores the shortest path 
    std::vector<int> path; 
    int crawl = dest; 
    path.push_back(crawl); 
    while (pred[crawl] != -1) { 
        path.push_back(pred[crawl]); 
        crawl = pred[crawl]; 
    } 
  
    // distance from source is in distance array 
    std::cout << "Shortest path length is : "
         << dist[dest]; 
  
    // printing path from source to destination 
    std::cout << "\nPath is::\n"; 
    for (int i = path.size() - 1; i >= 0; i--) 
        std::cout << path[i] << " "; 
} 