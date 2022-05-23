#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
  int n_cases, n_ppl, c1, c2;
  vector<vector<int>> graph;

  scanf("%i", &n_cases);
  //printf("Nb cases : %i \n", n_cases);

for(int epoch = 0; epoch < n_cases; epoch ++){
  if(epoch != 0){ //The required blank line beteen results
    printf("\n");
  }
    scanf("%i", &n_ppl);
    //printf("Nb people : %i \n", n_ppl);

    // ---------------------------------------------------------------------- //
    // First, let's make the graph of all connected people

    graph.clear(); //DON'T FORGET TO CLEAR THAT D4MN GRAPH
    for(int i = 0; i < n_ppl; i ++){
      int _label, _n_friends, _friend;
      vector<int> _connections;
      scanf("%i%i", &_label, &_n_friends);
      //printf("Label : %i Nb friends : %i (", _label, _n_friends);

      for(int j = 0; j < _n_friends; j++){
        scanf("%i", &_friend);
        //printf(" %i ", _friend);
        _connections.push_back(_friend);
      }
      //printf(" ) \n");
      graph.push_back(_connections);
      _connections.clear();
    }
    /*
    //Checking the graph
    cout << "Size " << graph.size() << endl;
    for_each(graph.begin(), graph.end(), [](const vector<int> _elt) {
      for_each(_elt.begin(), _elt.end(), [](const int n) {
        cout << n << ' ';
      });
      cout << '\n';
    });
    cout << '\n';
    */
    scanf("%i %i", &c1, &c2);
    //printf("C1 : %i C2 : %i \n", c1, c2);


    // ---------------------------------------------------------------------- //

    //We can now work on the algorithm. As we are looking for the shortest path
    //with all edges having the same weight (1), we'll use a BFS

    //There is a trivial case
    if(c1 == c2){
      printf("%i %i %i", c1, c2, 0);
    }
    else {
      queue<int> Q;
      bool Reached[n_ppl], Examined[n_ppl]; // An item is reached if it's queued and examined if we have queued its neighboors
      int Distances[n_ppl]; //Table of distances from c1 to everywhere
      bool searching = true;

      //Quickly setting the tables
      for(int i = 0; i < n_ppl; i++){
          Reached[i] = false;
          Examined[i] = false;
          Distances[i] = 0;
      }

      Q.push(c1); //C1 is our root
      while(!Q.empty() && searching) {
        //printf("Adding 1 to dist \n");
        int _p = Q.front();
        Q.pop();
        //printf("Examining : %i \n", _p);
        if(Examined[_p]) {
          //printf("Already examined \n", _p);
          continue;
        }
        Examined[_p] = true;
        vector<int> adj = graph[_p];
        for(int i = 0; i < adj.size(); i ++){
          int _n = adj[i];

          if(!Examined[_n]){
            if(!Reached[_n]){ //If the item is reached, it's already in the queue (neighbour of a previously examined item)
              Q.push(_n);
              Distances[_n] = Distances[_p] + 1;
              Reached[_n] = true;
              //printf("Adding %i to the queue. Distance : %i \n", _n, Distances[_n]);
            }
          }

          if(_n == c2){
            searching = false;
            //printf("Reached %i \n", c2);
          }
        }

      }
      printf("%i %i %i\n", c1, c2, Distances[c2] - 1); //Don't forget the -1 : we are searching for the nb of ppl and not the actual distance
    }
  }



  return 0;
}
