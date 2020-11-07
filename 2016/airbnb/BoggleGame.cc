#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BoggleGame {
public:
    struct Node {
        bool hasWord = false;
        Node *next[26];
        Node() {}
    };

    struct Trie {
        Node *root;
        Trie(){
            root = new Node();
        }
        
        void buildTree(vector<string> &words){
            for(string &s : words){
                int n = s.size();
                Node *node = root;
                for(char c : s){
                    int k = c - 'a';
                    if(node->next[k] == NULL)
                        node->next[k] = new Node();
                    node = node->next[k];
                }
                node->hasWord = true;
            }
        }
    };
    
    vector<string> maxNumofWords(vector<vector<char>> board, vector<string> dict){
	Trie trie;
	trie.buildTree(dict);

	int rows = board.size(), cols = board[0].size();
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	vector<string> finalResult, curtResult;
	dfs2(board, finalResult, curtResult, visited, 0, 0, trie); 
	
	return 	finalResult;
    }

    void dfs2(vector<vector<char>> &board, vector<string> &finalResult, vector<string> &curtResult, vector<vector<bool>> &visited, int x, int y, Trie &trie){
	int rows = board.size(), cols = board[0].size();
	if(x == rows && y == 0){
	    if(curtResult.size() > finalResult.size())
		finalResult = curtResult;
	    return;
	}

	vector<string> result;
	vector<vector<int>> paths;
	string curtWord;
	vector<int> curtPath; 
	dfs(board, visited, result, curtWord, paths, curtPath, trie.root, x, y); 
	
	int newx = y == cols -1 ? x + 1 : x;
	int newy = y == cols -1 ? 0: y+1;
	dfs2(board, finalResult, curtResult, visited, newx, newy, trie); // discard current found
	for(int i = 0; i < result.size(); i++){
	    curtResult.push_back(result[i]);
	    for(int loc : paths[i])
		visited[loc/cols][loc%cols] = true;
	    dfs2(board, finalResult, curtResult, visited, newx, newy, trie); // use each found
	    for(int loc : paths[i])
		visited[loc/cols][loc%cols] = false;
	    curtResult.pop_back();
	}
    }

    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, 
	     vector<string> &result, string &curtWord,
	     vector<vector<int>> &paths, vector<int> &curtPath, Node *node, int x, int y){
	int rows = board.size(), cols = board[0].size();
	if(x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y] || node->next[board[x][y]-'a'] == NULL)
	    return;
	node = node->next[board[x][y] - 'a'];
	
	curtPath.push_back(x * cols + y);
	curtWord.push_back(board[x][y]);
	if( node->hasWord){
	    paths.push_back(curtPath);
	    result.push_back(curtWord);
	}
	visited[x][y] = true;
	for(int i = 0; i < 4; i++){
	    int newx = x + dxy[i][0], newy = y + dxy[i][1];
	    dfs(board, visited, result, curtWord, paths, curtPath, node, newx, newy);
	}
	visited[x][y] = false;
	curtPath.pop_back();
	curtWord.pop_back();	
    }

    
private:
    int dxy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

};

int main(){
    vector<vector<char>> board = {
	{'o','a','a','n'},
	{'e','t','a','e'},
	{'i','h','k','r'},
	{'i','f','l','v'}
    };
    vector<string> dict = {"oath","pea","eat","rain", "ihk"};
    BoggleGame bg;
    auto result = bg.maxNumofWords(board, dict);
    
    for(string s : result)
	cout << s << endl;

    return 0;
}
