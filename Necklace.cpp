#include <iostream>
#include <list>
#include <tuple>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Graph{

private:
  int nb_vrtx, next_id;
  //As an adjacency list, we will use a vector adj_list such that adj_list[i] is a vector of all the beads with the color i in it
  //As we can have two beads with the same color, we need to also use an int as id
  // So all in all a bead is stored as a tuple t of size 3 such that t[0] = id, t[1] is the shared color of all the beads of the list and t[2] the other color
  vector<vector<tuple<int, int, int>>> adj_list;


public:
  Graph(){
    cout << "CAUTION : Graph not really initialized" << endl;
  }

  Graph(int _nb_vrtx){
    nb_vrtx = _nb_vrtx;
    next_id = 0;
    adj_list = vector<vector<tuple<int, int, int>>>(50); //We know that there are max 50 colors.
  }

  void addVrtx(int _c1, int _c2){
    adj_list[_c1].push_back(make_tuple(next_id, _c1, _c2));
    adj_list[_c2].push_back(make_tuple(next_id, _c2, _c1));
    next_id += 1;
  }

  void showGraph(){
    cout << "Graph : " << endl;
    for(auto v : adj_list){
      for(auto t : v){
        cout<< "Id: " << get<0>(t) << " c1: " << get<1>(t) << " c2: " << get<2>(t) << endl;
      }
    }
    cout << " " << endl; 
  }

};

int main() {

  int nb_cases, nb_beads, c1, c2;

  scanf("%i", &nb_cases);
  cout << "Nb cases : " << nb_cases << endl;

  for(int iter = 0; iter < nb_cases; iter ++){
    cout << "Case nb : " << iter << endl;
    scanf("%i", &nb_beads);
    Graph my_graph(nb_beads);

    for(int iter2 = 0; iter2 < nb_beads; iter2 ++){
      scanf("%i%i", &c1, &c2);
      my_graph.addVrtx(c1, c2);
    }

    my_graph.showGraph();
  }

   return 0;
}
