#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {

  int nb_vtx;
  vector<vector<int>> *AdjList;
  vector<vector<int>> Weights;


public:

  Graph(){
  }

  // The whole problem is how to make the graph...
  //
  //

  ~Graph(){
    delete [] AdjList;
  }

  void addEdge(int vtx1, int vtx2){
    AdjList[vtx1].push_back(vtx2);
  }

  void deleteEdge(int vtx1, int vtx2){
    for(int i = 0; i < AdjList[vxt1].size(); i ++){
      if(AdjList[vtx1][i] == vtx2) {
        AdjList[vtx1].erase(i);
        return;
      }
    }
    printf("Couldn't erase edge from %i to %i",  vtx1, vtx2);
    return;
  }


}
