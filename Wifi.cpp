#include <iostream>
#include <list>
#include <cmath>
using namespace std;

int main() {
  int nb_cases, n, m;
  std::list<int> houses;


  scanf("%i", &nb_cases);

  for(int i = 0; i < nb_cases; i++){
      houses.clear();
      scanf("%i%i", &n, &m);


      //------------ General idea -------------//
      /*
      If there are more access points than houses, the problem is trivial

      If not, we are going to do a dichotomy over the possible min distance (starting with min distance = size of the whole stree).
      For each distance d, we will then try to place the access points such that no house is farer that d from any points.
      To do that we will proceed as follow (gluton) :
      - Start at the first house
      - Go down the street
      - If you go beyond d from the first house, place an access point
      - Go to the next house
      - Repeat until the end of the stret or going out of access points
      */
      //------------------------------------//

      if(n >= m){ //Trivial, but we still need to scan the houses in order to go to the next case
        int _nb;
        for(int j = 0; j < m; j ++){
          scanf("%i", &_nb);
        }
        printf("0.0\n");
      }

      else {
        //First, let's get the information about all the houses
        int _nb;
        for(int j = 0; j < m; j ++){
          scanf("%i", &_nb);
          houses.push_back(_nb);
        }

        houses.sort(); // VERY IMPORTANT we need to sort the list if we want our dichotomy to work

        float _min = 0;
        float _max = houses.back();

        float point_pos; //Position of the access point
        int left_house, right_house; //Position of the houses most to the left and to the right of the forementioned point

        while(abs(_max - _min) > 0.0311){ //Dichotomy
          float _mean = (_min + _max) / 2;
          //printf("Dichotomy : min = %g max = %g mean = %g \n", _min, _max, _mean);
          int points_left = n; //Number of access points yet to place
          bool duable = true;

          left_house = houses.front();
          point_pos = left_house + _mean; //We put the access point as far as possible : gluton
          points_left -= 1; //We have just placed our first point
          //printf("Point pos : %g \n", point_pos);
          for(int h : houses){
            if(h > point_pos + _mean){ //Ig a house is too far away from the last point
              //printf("House %i too far from last point : placing a new point \n", h);
              left_house = h;
              point_pos = left_house + _mean; //We put a new access point
              //printf("Point pos : %g \n", point_pos);
              points_left -= 1;
              //printf("Points left : %i", points_left);
              if(points_left == -1){ //Then we have run out of access points : the covering distance is not possible with that many points
                duable = false;
                //printf("Breaking : left house %i mean = %g mean pos = %g \n", left_house, _mean, point_pos);
                break;
              }
            }
          }
          if(duable){
            _max = _mean;
          }
          else {
            _min = _mean;
          }

          //printf("\n\n");
        }

        int rounded = round(_min * 10);
        std::string rounded_str = std::to_string(rounded);
        rounded_str.insert(rounded_str.size() - 1, ".");
        printf("%s\n", rounded_str.c_str()); //Or printf("%g", max); as they are the same at 0.1 près
      }


  }

  return 0;
}
