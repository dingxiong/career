#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

/// @brief Minimum Spanning Tree (MST) algorithm
/// See "Introduction to Algorithm 3rd Eidtion" Chapter 23.
/// The basic idea is to find the safe edge greedily at each step.
///
/// Two major algorithms : Kruskal, Prim
/// Kruskal's algorithm uses a Union-Find data structure to grow the forest.
/// Prim's algorithm uses a heap to store all remaining vertices and grow a single tree.
/// 
/// Complexity : O(E*logV)
class MST {
public:
    MST(int n, vector<tuple<int, int, double>> w) : nV(n), weights(w) {}
    
    vector<tuple<int, int, double>> Prim(){

	// initialization
	vector<Vertex> Vs(nV);
	for(int i = 0; i < nV; i++){
	    Vs[i].id =  i;
	}
	Vs[0].w = 0;

	int i, j;
	double w;
	for(auto &t : weights){	    
	    tie(i, j, w) = t;
	    Vs[i].nei.emplace_back(j, w);
	    Vs[j].nei.emplace_back(i, w);
	}
	
	auto comp = [&Vs](const int &a, const int &b){return Vs[a].w < Vs[b].w; };
	set<int, decltype(comp)> pq(comp);
	for(int i = 0; i < nV; i++)
	    pq.insert(i);
	
	// Prim's algorithm 
	vector<tuple<int, int, double>> result;
	while(!pq.empty()){
	    int u = *pq.begin();
	    pq.erase(pq.begin());
	    Vs[u].visited = true;
	    result.emplace_back(Vs[u].p, u, Vs[u].w);
	    for(auto &p : Vs[u].nei){
		if(!Vs[p.first].visited && p.second < Vs[p.first].w){
		    Vs[p.first].w = p.second;
		    Vs[p.first].p = u;
		    pq.erase(p.first);
		    pq.insert(p.first);
		}
	    }
	}
	
	return result;
    }
    
private :
    int nV; // number of vertices. Index from 0 to nv - 1.
    
    // <i, j, w> : edge weight w = weight[i][j], i, j \in [0, nV- 1]
    vector<tuple<int, int, double>> weights; 

    struct Vertex {
	int id; 
	int p = -1; // parent
	double w = numeric_limits<double>::infinity(); // min weight used as key
	bool visited = false;
	vector<pair<int, double>> nei; // neighbors <id, weight>
	Vertex() {}
    };
};


int main(){
    // see mst_example.png (Figure 23.5 of "introduction to algorithm 3rd edition")
    int nV = 9;
    vector<tuple<int, int, double>> weights = {
	make_tuple(0, 1, 4),
	make_tuple(0, 7, 8),
	make_tuple(1, 7, 11),
	make_tuple(1, 2, 8),
	make_tuple(7, 8, 7),
	make_tuple(8, 6, 6),
	make_tuple(8, 2, 2),
	make_tuple(7, 6, 1),
	make_tuple(2, 5, 4),
	make_tuple(2, 3, 7),
	make_tuple(5, 6, 2),
	make_tuple(3, 5, 14),
	make_tuple(3, 4, 9),
	make_tuple(4, 5, 10)
    };

    MST mst(nV, weights);
    
    auto result = mst.Prim();
    
    int i, j;
    double w, sum = 0;
    for(auto &t : result){
	tie(i, j, w) = t;
	cout << i << ' ' << j << ':' << w << endl;
	sum += w;
    }
    cout << "cost : " <<  sum << endl;
    return 0;
}
