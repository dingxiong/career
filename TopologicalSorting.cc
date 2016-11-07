#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class TopologicalSorting {
public :
    /// Kahn's algorithm (BFS)
    /// @param edges  stores directioned edges. <A, B> means an edge from A to B
    /// @return the sorted vertices if no cycle detected. Otherwise, empty list.
    vector<string> Kahn(vector<string> vertices, vector<pair<string, string>> edges){
	unordered_map<string, unordered_set<string>> dep;
	unordered_map<string, int> deg;
	
	for(string &s : vertices)
	    deg[s] = 0;
	for(auto &p : edges){
	    if(dep[p.first].count(p.second) == 0){
		dep[p.first].insert(p.second);
		deg[p.second]++;
	    }
	}
	
	queue<string> que;
	for(auto &p : deg)
	    if(p.second == 0)
		que.push(p.first);

	vector<string> path;
	while(!que.empty()){
	    string s = que.front();
	    path.push_back(s);
	    que.pop();
	    for(string nei : dep[s]){
		if(--deg[nei] == 0)
		    que.push(nei);
	    }
	}
	
	return path.size() == vertices.size() ? path : vector<string>();
    }

    vector<string> DFS(vector<string> vertices, vector<pair<string, string>> edges){
	unordered_map<string, unordered_set<string>> dep;
	for(auto &p : edges)
	    dep[p.first].insert(p.second);
	
	unordered_map<string, bool> visited, mark;
	for(string s : vertices){
	    visited[s] = false;
	    mark[s] = false;
	}
	
	vector<string> path;
	for(auto &s : vertices){
	    if(!visited[s]){
		if(!visit(dep, path, visited, mark, s))
		    return {};
	    }
	}
	  
	reverse(path.begin(), path.end());
	return path;
    }

    bool visit(unordered_map<string, unordered_set<string>> &dep, vector<string> &path,
	       unordered_map<string, bool> &visited, unordered_map<string, bool> &mark, string v){
	if(mark[v] == true)
	    return false;
	mark[v] = true;
	for(auto nei : dep[v]){
	    if(!visited[nei]){
		if(!visit(dep, path, visited, mark, nei))
		    return false;
	    }
	}
	mark[v] = false;
	visited[v] = true;
	path.push_back(v);
	return true;
    }

};

int main(){
    vector<string> vertices = {"5", "7", "3", "11", "8", "2", "9", "10"};
    vector<pair<string, string>> edges = {{"5", "11"}, {"7", "11"}, {"7", "8"} , {"3", "8"}, 
					  {"11", "2"}, {"11", "9"}, {"11", "10"},
					  {"3", "10"}, {"8", "9"},
					  {"7", "8"}, {"7", "8"}, {"7", "8"} }; // add some dupilcates
    TopologicalSorting ts;
    auto path = ts.Kahn(vertices, edges);
    for(auto &s : path)
	cout << s << ' ';
    cout << endl;

    path = ts.DFS(vertices, edges);
    for(auto &s : path)
	cout << s << ' ';
    cout << endl;
}
