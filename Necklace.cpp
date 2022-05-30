#include <iostream>
#include <list>
#include <tuple>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

//As we can have two beads with the same color, we need to also use an int as id
// So all in all a bead is stored as a tuple t of size 3 such that t[0] = id, t[1] is the shared color of all the beads of the list and t[2] the other color
typedef tuple<int, int, int> Bead;

class Graph{

private:
  int nb_vrtx, next_id;
  //As an adjacency list, we will use a vector adj_list such that adj_list[i] is a vector of all the beads with the color i in it
  vector<vector<Bead>> adj_list;

  //Same concept but with just the elements sorted by ID, just in case
  vector<tuple<int, int, int>> id_list;
  bool isCycle;

  //The cycle
  vector<Bead> cycle;


public:
  Graph(){
    cout << "CAUTION : Graph not really initialized" << endl;
  }

  Graph(int _nb_vrtx){
    nb_vrtx = _nb_vrtx;
    next_id = 0;
    isCycle = false;
    adj_list = vector<vector<Bead>>(50); //We know that there are max 50 colors.
  }

  void addVrtx(int _c1, int _c2){
    adj_list[_c1].push_back(make_tuple(next_id, _c1, _c2));
    adj_list[_c2].push_back(make_tuple(next_id, _c2, _c1));
    id_list.push_back(make_tuple(next_id, _c1, _c2));
    next_id += 1;
  }

  void show_adj_list(){
    cout << "adj_list : " << endl;
    for(vector<Bead> v : adj_list){
      cout << "Sublist : " << endl;
      for(Bead t : v){
        cout<< "Id: " << get<0>(t) << " c1: " << get<1>(t) << " c2: " << get<2>(t) << endl;
      }
    }
    cout << " " << endl;
  }

  void show_id_list(){
    cout << "id_list : " << endl;
    for(Bead t : id_list){
      cout<< "Id: " << get<0>(t) << " c1: " << get<1>(t) << " c2: " << get<2>(t) << endl;
    }
    cout << " " << endl;
  }

  // ----------------------- Now for the really interesting part : finding a cycle --------------------------------------- //
  // Code adapted from : https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

  // This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212
  bool isCyclicUtil(Bead _bead, bool visited[], bool *recStack)
  {
    int _id = get<0>(_bead);
      if(visited[_id] == false)
      {
          // Mark the current node as visited and part of recursion stack
          visited[_id] = true;
          recStack[_id] = true;

          // Recur for all the vertices adjacent to this vertex
          for(Bead _adjBead : adj_list[get<2>(_bead)])
          {
              int _adjId = get<0>(_adjBead);
              if(_adjId == _id)
                continue; // The bead is in the list of all elements with the same color, so we need to skip it
              if ( !visited[_adjId] && isCyclicUtil(_adjBead, visited, recStack) ) {
                cycle.push_back(_adjBead);
                return true;
              }
              else if (recStack[_adjId]){
                cycle.push_back(_adjBead);
                return true;
              }
          }

      }
      recStack[_id] = false;  // remove the vertex from recursion stack
      cycle.pop_back();
      return false;
  }

  // Returns true if the graph contains a cycle, else false.
  // This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
  bool isCyclic()
  {
      // Mark all the vertices as not visited and not part of recursion
      // stack
      bool *visited = new bool[nb_vrtx];
      bool *recStack = new bool[nb_vrtx];
      for(int i = 0; i < nb_vrtx; i++)
      {
          visited[i] = false;
          recStack[i] = false;
      }

      // Call the recursive helper function to detect cycle in different
      // DFS trees
      for(int i = 0; i < nb_vrtx; i++)
          if ( !visited[i] && isCyclicUtil(id_list[i], visited, recStack)){
            isCycle = true;
            return true;
          }

      return false;
  }

  void printCycle(){
    //We just need to make sure that  For 1 ≤ i ≤ N 1, the second integer on
    //line i must be the same as the first integer on line i + 1
    //In order to do that we are first going to "sort / swap" the beads in the vect cycle

    //"Sorting / swapping"
    //We assume that the first one is ik and swap everything around it
    int size_cycle = cycle.size();
    for(int i = 0; i < size_cycle - 1; i++){
      Bead n = cycle[i];
      Bead m = cycle[i+1];
      if(get<2>(n) != get<1>(m)){
        cycle[i+1] = make_tuple(get<0>(m), get<2>(m), get<1>(m));
      }
    }
    //Then, if the first one wasn't ok we swap it too
    if(get<2>(cycle[size_cycle - 1]) != get<1>(cycle[0])){
      cycle[0] = make_tuple(get<0>(cycle[0]), get<2>(cycle[0]), get<1>(cycle[0]));
    }

    //Printing
    for(Bead _b : cycle){
      printf("%i %i \n", get<1>(_b), get<2>(_b));
    }
  }

  // --------------------------------------------------------------------------------------------------------------------- //

};

int main() {

  int nb_cases, nb_beads, c1, c2;

  scanf("%i", &nb_cases);
  //cout << "Nb cases : " << nb_cases << endl;

  for(int iter = 0; iter < nb_cases; iter ++){
    printf("Case #%i \n", iter + 1);
    scanf("%i", &nb_beads);
    Graph* my_graph = new Graph(nb_beads);

    for(int iter2 = 0; iter2 < nb_beads; iter2 ++){
      scanf("%i%i", &c1, &c2);
      my_graph->addVrtx(c1, c2);
    }
    //my_graph->show_adj_list();
    //my_graph->show_id_list();
    if(my_graph->isCyclic()){
      my_graph->printCycle();
    }
    else{
      printf("some beads may be lost \n");
    }
    delete my_graph;
    printf("\n");
  }

   return 0;
}
