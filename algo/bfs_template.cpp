class Solution {
public:
    vector<vector<char>> maze;
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
    bool isOut(int i,int j){
        return i >= maze.size() || i < 0 || j >= maze[0].size() || j < 0;
    }
    bool isBorder(int i,int j){
        return i == maze.size() - 1 || i == 0 || j == 0 || j == maze[0].size() - 1;
    }
    struct State{
        int i,j,count;
        State(int I,int J,int C) : i(I),j(J),count(C){} 
    };
    int bfs(int a,int b){
        queue<State> q;
        q.push(State(a,b,0));
        unordered_set<string> visited;
        bool perhaps = false;
        while(!q.empty()){
            auto x = q.front(); q.pop();
            if(isOut(x.i,x.j)) continue;
            if(maze[x.i][x.j] == '+') continue;
            string key = to_string(x.i) + "," + to_string(x.j); 
            if(visited.count(key)) continue;
            visited.insert(key);
            if(perhaps && maze[x.i][x.j] == '.' && isBorder(x.i,x.j)) return x.count;
            perhaps = true;
            for(auto [i,j] : dirs){
                q.push(State(x.i + i,x.j + j,x.count + 1));
            }
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        this->maze = maze;
        return bfs(entrance[0],entrance[1]);
    }
};
