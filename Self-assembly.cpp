#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {

  private:

    int mol;
    vector<vector<int>> *AdjList;
    vector<bool> Visited;

    //InPath stores the visited nodes in the traversal path before backtracking
    //for finding a cycle in a directed graph
    vector<bool> InPath;

    bool cyclePresent;

  public:

    Graph(){

    }

    // The whole problem is how to make the graph...
    //
    //

    ~Graph(){
      delete [] AdjList;
    }

    void detectCycle(int _src) {
      Visited[_src] = true;

      for(auto& adj_mol : AdjList[src]){

        if(InPath[adj_mol]){
          cyclePresent = true;
          return;
        } else if (!Visited[adj_mol]) {
          detectCycle(adj_mol);
        }
      }
      // Before we backtrack unset the flag for the src vertex as it will
      // not be in the next traversal path
      InPath[src] = false;
    }

    bool getCyclePresent(){
      return cyclePresent;
    }


}


int main() {
  int nb_mol;

  while(scanf("%i", &nb_mol) != EOF) {
    for(int i = 0; i < nb_mol; i ++) {
      // Make the molecules
      //
    }

    //Build the graph
    //


  }
  return 0;
}
