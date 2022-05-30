#include <iostream>
#include <list>
#include <tuple>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, pair<int, unsigned int>> Sets; //map ro parent & rank

void MakeSet(int x) {
  Sets.insert(make_pair(x, make_pair(x,0)));
}

int Find(int x) {
  if(Sets[x].first == x) return x; // Parent = x ?
  else return Sets[x].first = Find(Sets[x].first); // Get parent
}

void Union(int x, int y) {
  int parentX = Find(x), parentY = Find(y);
  int rankX = Sets[parentX].second, rankY = Sets[parentY].second;
  if(parentX == parentY) return;
  else if(rankX < rankY)
    Sets[parentX].first = parentY;
  else
    Sets[parentY].first = parentX;
  if(rankX == rankY)
    Sets[parentX].second++;
}

int main(){

  int nb_roads, nb_intersec;

   while(scanf("%d %d",&nb_roads,&nb_intersec) != EOF){

     for(int i = 0; i < nb_roads; i++) {
       MakeSet(i);
     }

     int r1, r2;
     for(int i = 0; i < nb_intersec; i ++){
       scanf("%i %i", &r1, &r2);
       Union(r1, r2);
     }

     bool possible = true;

     for(int i = 0; i < nb_roads; i++){

     }

     if(!possible) printf("Not Possible \n");
     else printf("Possible \n");

   }

   return 0;
}
