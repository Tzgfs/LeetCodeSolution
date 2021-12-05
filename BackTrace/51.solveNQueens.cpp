class Solution {
public:
    vector<vector<string>> ret;
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {0, 1, -1, 1, -1, 0, 1, -1};

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> attack(n, vector<int>(n, 0));
        vector<vector<char>> queen(n, vector<char>(n, '.'));

        backtrack(0, n, queen, attack);

        return ret;
    }

    void backtrack(int k, int n, vector<vector<char>>& queen, vector<vector<int>>& attack)
    {
        if(k == n){
            vector<string> solution;
            for(int i=0; i<n; i++){
                string str(queen[i].begin(), queen[i].end());
                solution.push_back(str);
            }
            ret.push_back(solution);
            return;
        }

        for(int i=0; i<n; i++){
            if(attack[k][i] == 0){
                vector<vector<int>> temp(n, vector<int>(n, 0));

                for(int k=0; k<n; k++){
                    for(int v=0; v<n; v++){
                        temp[k][v] = attack[k][v];
                    }
                }

                queen[k][i] = 'Q';
                checkAttack(k, i, attack);
                
                backtrack(k+1, n, queen, attack);
                attack = temp;
                queen[k][i] = '.';

            }
        }

    }

    void checkAttack(int x, int y, vector<vector<int>>& attack){
        attack[x][y] = 1;
        for(int j=0; j<8; j++){
            for(int i=0; i<attack[0].size(); i++){
                int newX = x + i*dx[j];
                int newY = y + i*dy[j];
                if(newX >=0 && newX < attack.size() && newY >= 0 && newY < attack.size()){
                    attack[newX][newY] = 1;
                }
            }
        }
    }
};