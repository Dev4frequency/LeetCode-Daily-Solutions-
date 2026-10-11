class NeighborSum {
    int n, m;
    vector<vector<int>> c_grid;
    map<int, pair<int, int>> data;
    
public:
    NeighborSum(vector<vector<int>>& grid) : n(grid.size()), m(grid[0].size()) {
        c_grid = grid;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                data[grid[i][j]] = make_pair(i, j);
            }
        }
    }
    
    int adjacentSum(int value) {
        int i = data[value].first;
        int j = data[value].second;
        int sum = 0;

        if(i > 0) sum += c_grid[i-1][j];
        if(j < m-1) sum += c_grid[i][j+1]; 
        if(j > 0) sum += c_grid[i][j-1];             
        if(i < n-1) sum += c_grid[i+1][j];           
        
        return sum;
    }
    
    int diagonalSum(int value) {
        int i = data[value].first;
        int j = data[value].second;
        int sum = 0;

        if(i > 0 && j > 0) sum += c_grid[i-1][j-1];   
        if(i > 0 && j < m-1) sum += c_grid[i-1][j+1];  
        if(i < n-1 && j > 0) sum += c_grid[i+1][j-1];   
        if(i < n-1 && j < m-1) sum += c_grid[i+1][j+1]; 
        
        return sum;
    }
};
