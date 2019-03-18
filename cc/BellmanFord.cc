#include <vector>
#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

/**
 * Dynamic programming:
 * Let f(i, k) be the distance from `start` to `i` if the edges used is less than or equal to k
 * base case: f(i, 0) = i == start ? 0 : Inf
 * recursion: f(i, k) = min(f(i, k-1), f(j, k-1) + d(j, i)) for all j's that are connected to i.
 *
 * Application:
 * 1. find negative cycle in the graph
 *
 * pitfalls: 
 * 1. when comparing f(j, k-1) + d(j, i) with f(i, k-1) be cautious that f(j, k-1) may be Inf.
 * 2. 
 */
class BellmanFord {
public :

    // complexity O(V*E)
    vector<string> shortestPath(string start, string target, vector<string> vertices,
				vector<tuple<string, string, int>> edges){
	unordered_map<string, int> distances;
	unordered_map<string, string> comeFrom;

	for(auto s : vertices)
	    distances[s] = s == start ? 0 : INT_MAX;

	string from, to;
	int cost;
	for(int i = 0; i < vertices.size() - 1; i++){
	    for(auto t : edges){
		tie(from, to, cost) = t;
		if(distances[from] < distances[to] - cost){
		    distances[to] = distances[from] + cost;
		    comeFrom[to] = from;
		}
		swap(from, to); // assume undirected graph
		// we use distances[to] - cost because distances[from/to] could be INT_MAX
		if(distances[from] < distances[to] - cost){
		    distances[to] = distances[from] + cost;
		    comeFrom[to] = from;
		}
	    }
	}
	
	for(auto t : edges){
	    tie(from, to, cost) = t;
	    if(distances[from] < distances[to] - cost)
		return {};
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

int main(){
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
    BellmanFord bf;
    auto path = bf.shortestPath("2", "7", vertices, edges);
    for(auto &s : path)
	cout << s << ' ';
    cout << endl;

    return 0;
}
