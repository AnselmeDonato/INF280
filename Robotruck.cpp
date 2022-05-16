#include <iostream>
#include <list>
#include <cmath>
using namespace std;

int main() {
  int nb_cases, max_load, nb_packages, _w, _x, _y, _load, _last_x, _last_y, _nb_moves;

  scanf("%i", &nb_cases);
  //printf("Nb cases : %i \n", nb_cases);

  for(int i = 0; i < nb_cases; i ++){
    scanf("%i%i", &max_load, &nb_packages);
    _load = 0;
    _nb_moves = 0;
    _last_x = 0;
    _last_y = 0;

    for(int j = 0; j < nb_packages; j ++){
      scanf("%i%i%i", &_x, &_y, &_w);
      //printf("%i %i %i \n", _x, _y, _w);

      //If the package can be loaded in the robot, it will be delivered after the last one
      if(_load + _w < max_load){ //The robot is still loading
        //Two cases are possible : delivering now, even if we still have space or keep on filling the robot
        //The choice is up to whether it's faster to come back to base or delivering the new package  
        _load += _w;
        _nb_moves += abs(_last_x - _x) + abs(_last_y - _y);
        _last_x = _x;
        _last_y = _y;
        printf("Still delivering. Nb moves so far : %i \n", _nb_moves);
      }

      //If the robot is full, it needs to go back to the start
      else{
        printf("Full : load %i \n", _load);
        _nb_moves += _last_x + _last_y; //Returning to the base
        printf("Full, returning to base. Nb moves so far : %i \n", _nb_moves);
        _load = _w; //Loading the new package
        _nb_moves += _x + _y; //Delivering it
        _last_x = _x; //Back on track
        _last_y = _y;
        printf("Still delivering. Nb moves so far : %i \n", _nb_moves);
      }
    }
    _nb_moves += _last_x + _last_y; //Last return to base after the last trip
    printf("%i \n \n", _nb_moves);
  }

  return 0;
}
