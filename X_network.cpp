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

  while(scanf("%i", &n_cases) != EOF){
    //printf("Nb cases : %i \n", n_cases);
    scanf("%i", &n_ppl);
    //printf("Nb people : %i \n", n_ppl);

    // ---------------------------------------------------------------------- //
    // First, let's make the graph of all connected people

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

    scanf("%i %i", &c1, &c2);
    //printf("C1 : %i C2 : %i \n", c1, c2);

    //Checking the graph
    /*
    for_each(graph.begin(), graph.end(), [](const vector<int> _elt) {
      for_each(_elt.begin(), _elt.end(), [](const int n) {
        cout << n << ' ';
      });
      cout << '\n';
    });
    cout << '\n';
    */

    // ---------------------------------------------------------------------- //

    //We can now work on the algorithm. As we are looking for the shortest path
    //with all edges having the same weight (1), we'll use a BFS

    queue<int>

  }

  return 0;
}
