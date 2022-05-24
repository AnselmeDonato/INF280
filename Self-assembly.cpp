#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


struct molecule {
  int side1, side2, side3, side4;

};

int main() {
  int nb_mol;
  vector<molecule> list_mol;

  while(scanf("%i", &nb_mol) != EOF) {
    for(int i = 0; i < nb_mol; i ++) {
      // Make the molecules
      //
    }

    //Build the graph
    //

    bool Visited[nb_mol], OnStack[nb_mol];

    for(int i = 0; i < nb_mol; i++){
      Visited[i] = false;
      OnStack[i] = false;
    }

    //DFS to find cycles
    Visited[0] = true;
    OnStack[0] = true;
    vector<int> adj = list_mol[0].getAdjList();
    for(int i = 0; i < adj.size(); i ++){
      int _adj_mol = adj[i]
      if(OnStack[_adj_mol]){
        //Cycle found
        return 1;
      }
    }
  }
  return 0;
}
