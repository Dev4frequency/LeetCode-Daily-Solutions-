int dist[25][25][55][1 << 10];
int posToId[25][25];
const vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};    
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();
        const int IINF = 1e9;
        int xs, ys, L = 0;
        int id = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') xs = i, ys = j;
                if (classroom[i][j] == 'L') L++, posToId[i][j] = id++;
            }
        if (L == 0) return 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k <= energy; k++) 
                    for (int p = 0; p < (1 << L); p++)
                        dist[i][j][k][p] = IINF;
        dist[xs][ys][energy][0] = 0;
        deque<pair<pair<int,int>,pair<int,int>>> q;
        q.push_front({{xs, ys}, {energy, 0}});
        int level = 0, fmask = (1 << L) - 1;
        while (q.size()) {
            for (int sz = q.size(); sz; sz--) {
                auto p = q.back();
                q.pop_back();
                int i = p.first.first;
                int j = p.first.second;
                int ener = p.second.first;
                int mask = p.second.second;
                if (ener) {
                    for (auto &move : moves) {
                        int I = i + move.first;
                        int J = j + move.second;
                        if (0 <= I && I < n && 0 <= J && J < m && classroom[I][J] != 'X') {
                            if (classroom[I][J] == 'L') {
                                int nmask = mask | (1 << posToId[I][J]);
                                if (dist[I][J][ener - 1][nmask] > dist[i][j][ener][mask] + 1) {
                                    dist[I][J][ener - 1][nmask] = dist[i][j][ener][mask] + 1;
                                    q.push_front({{I, J}, {ener - 1, nmask}});
                                    if (nmask == fmask) {
                                        return level + 1;
                                    }
                                }
                            } else if (classroom[I][J] == 'R')  {
                                if (dist[I][J][energy][mask] > dist[i][j][ener][mask] + 1) {
                                    dist[I][J][energy][mask] = dist[i][j][ener][mask] + 1;
                                    q.push_front({{I, J}, {energy, mask}});
                                }
                            } else {
                                if (dist[I][J][ener - 1][mask] > dist[i][j][ener][mask] + 1) {
                                    dist[I][J][ener - 1][mask] = dist[i][j][ener][mask] + 1;
                                    q.push_front({{I, J}, {ener - 1, mask}});
                                }
                            }
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};