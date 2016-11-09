#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

class Dijkstra {
public :

    struct MyHash {
	size_t operator()(pair<string, int> x) const {
	    hash<string> h;
	    return h(x.first + to_string(x.second));
	}
    };

    // the implimentation is for undirected graph. but it can be easily modified for directed graph.
    // pitfalls :
    // 1) since you need to update the value inside a priority queue, so use set instead
    // 2) when updating (i.e. remove + insert) a set element. remove first, and the update distance value.
    // 3) be careful about points unreachable.
    vector<string> shortestPath(string start, string target, vector<string> vertices,
				vector<tuple<string, string, int>> edges){
	unordered_map<string, unordered_set<pair<string, int>, MyHash>> dep;
	unordered_map<string, int> distances;
	unordered_map<string, string> comeFrom;
	auto comp = [&distances](const string &a, const string &b){ 
	    if(distances[a] != distances[b])
		return distances[a] < distances[b];
	    return a < b;
	};
	set<string, decltype(comp)> open(comp);
	
	for(auto &p : edges){
	    string from, to;
	    int cost;
	    tie(from, to, cost) = p;
	    dep[from].emplace(to, cost);
	    dep[to].emplace(from, cost);
	}
      
	for(auto s : vertices){
	    distances[s] = s == start ? 0 : INT_MAX;
	    open.insert(s);
	}
	
	while(!open.empty()){
	    string s = *open.begin();
	    open.erase(open.begin());
	    int dist = distances[s];
	    if(dist == INT_MAX) // points cannot be reached from starting point
		continue;

	    for(auto &p : dep[s]){		
		string nei = p.first;
		int newDist = dist + p.second; 
		if(newDist < distances[nei]){
		    open.erase(nei); // first erase nei, then update distance, otherwise comp() fail to find the element
		    distances[nei] = newDist;
		    open.insert(nei);
		    comeFrom[nei] = s;
		}
	    }
	}

	return retrievePath(comeFrom, start, target);
    }
    
    vector<string> retrievePath(unordered_map<string, string> &comeFrom, string start, string target){
	vector<string> path;
	while(comeFrom.count(target)){
	    path.push_back(target);
	    target = comeFrom[target];
	}
	path.push_back(start);
	reverse(path.begin(), path.end());
	return path;
    }
   
};


int main() {
    vector<string> vertices = {"0", "1", "2", "3", "4", "5", "6", "7", "8"};
    vector<tuple<string, string, int>> edges = {
	make_tuple("0", "1", 4),
	make_tuple("0", "7", 8),
	make_tuple("1", "7", 11),
	make_tuple("1", "2", 8),
	make_tuple("7", "6", 1),
	make_tuple("7", "8", 7),
	make_tuple("2", "8", 2),
	make_tuple("8", "6", 6),
	make_tuple("2", "3", 7),
	make_tuple("2", "5", 4),
	make_tuple("6", "5", 2),
	make_tuple("3", "5", 14),
	make_tuple("3", "4", 9),
	make_tuple("5", "4", 10)
    };
    Dijkstra dijk;
    auto path = dijk.shortestPath("2", "7", vertices, edges);
    for(auto &s : path)
	cout << s << ' ';
    cout << endl;


}
