class Solution {
    public int countServers(int[][] grid) {
        int res = 0;
        int m = grid.length, n = grid[0].length;
        boolean[] rows = new boolean[m];
        for (int r = 0; r < m; r++){
            int count = sum(grid[r]);
            if (count > 1){
                res += count;
                rows[r] = true;
            }
        }
        for (int c = 0; c < n; c++){
            int counted = 0, total = 0;
            for (int r = 0; r < m; r++){
                if (grid[r][c] == 1){
                    total++;
                    if (rows[r]) counted++;
                }
            }
            if (total > 1) res += total - counted;
        }
        return res;
    }
    private int sum(int[] nums){
        int total = 0;
        for (int num : nums)    
            total += num;
        return total;
    }
}