#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool is_win(string config) {

	bool rows =
		(config[0] != '.' && config[0] == config[1] && config[1] == config[2]) ||
		(config[3] != '.' && config[3] == config[4] && config[4] == config[5]) ||
		(config[6] != '.' && config[6] == config[7] && config[7] == config[8]);

	bool columns =
		(config[0] != '.' && config[0] == config[3] && config[3] == config[6]) ||
		(config[1] != '.' && config[1] == config[4] && config[4] == config[7]) ||
		(config[2] != '.' && config[2] == config[5] && config[5] == config[8]);

	bool diagonals =
		(config[0] != '.' && config[0] == config[4] && config[4] == config[8]) ||
		(config[2] != '.' && config[2] == config[4] && config[4] == config[6]);
    bool full = true;
    for(int i=0; i<9; i++){
        if(config[i] == '.'){
            full = false;
            break;
        }
    }

	return rows || columns || diagonals || full;
}

void pre_calc(set<string> &valid){
    string init_board = ".........", moves = "XO";
    valid.insert(init_board);
    queue<string> q;
    queue<int> p;
    q.push(init_board);
    p.push(0);
    while(!(q.empty())){

        string cur_board = q.front();
        int play_turn = p.front();

        q.pop();
        p.pop();

        if(is_win(cur_board))
            continue;

        for(int i = 0; i < 9; i++){
            if(cur_board[i] == '.'){
                cur_board[i] = moves[play_turn];
                valid.insert(cur_board);
                q.push(cur_board);
                p.push(1-play_turn);
                cur_board[i] = '.';
            }

        }
    }
    return;
}


int main(){
    set<string> valid;
    pre_calc(valid);
    string s;
    while(cin >> s){
        if(s == "end")
            break;
        if(valid.find(s) != valid.end() && is_win(s))
            cout << "valid" << endl;
        else
            cout << "invalid" << endl;
    }
	return 0;
}

