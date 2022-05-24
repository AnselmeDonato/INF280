#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


struct molecule {
  int side1, side2, side3, side4;

};

void DFS(int u, int _adj[], bool _visited[]){
  if(_visited[u])
    return;
  Visited[u] = true;
  for (auto v : _adj[u])
    DFS(v);
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

    bool Visited[nb_mol] = {};

    //DFS to find cycles
    if(Visited[u])
      continue;
    Visited[u]
  }
  return 0;
}
