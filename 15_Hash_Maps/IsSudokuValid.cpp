    #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;

    bool isValidSudoku(vector<vector<string>>& board) {
        unordered_map<string, vector<pair<int, int>>> mp;
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                if(board[i][j] != ".")
                    mp[board[i][j]].push_back({i,j});
        
        
        for(auto i=mp.begin(); i!= mp.end(); i++){
            //cout<<i->first;
            vector<pair<int,int>> v = i->second;
            for(auto j=v.begin(); j!=v.end(); j++){
                //cout<<"("<<j->first<<","<<j->second<<")"<<", ";
                for(auto k=j+1; k!=v.end(); k++)
                    if(j->first==k->first || j->second==k->second || (j->first/3==k->first/3 && j->second/3==k->second/3))
                       return false;
            }
            //cout<<endl;
        }
        return true;
    }

    int main(){
        vector<vector<string>> board;
        board = {{"7","3",".",".","7",".",".",".","."}
                ,{"6",".",".","1","9","5",".",".","."}
                ,{".","9","8",".",".",".",".","6","."}
                ,{"8",".",".",".","6",".",".",".","3"}
                ,{"4",".",".","8",".","3",".",".","1"}
                ,{"7",".",".",".","2",".",".",".","6"}
                ,{".","6",".",".",".",".","2","8","."}
                ,{".",".",".","4","1","9",".",".","5"}
                ,{".",".",".",".","8",".",".","7","9"}};
        cout<<isValidSudoku(board);
        return 0;
    }