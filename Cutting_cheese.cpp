#include <iostream>
#include <list>
#include <cmath>
using namespace std;

//The chees has density of 1 so across the whole code colume and mass actually represent the same thing

struct hole {
  int r, z; //As we suppose that the holes don't overlap or are partially outside of the cheese, we only need z

  //We need to define comparators in order to later on sort the list of holes by z position
  bool operator>(const hole& h) { return z > h.z; }
	bool operator>=(const hole& h) { return z >= h.z;}
  bool operator<(const hole& h) { return z < h.z; }
  bool operator<=(const hole& h) { return z <= h.z; }
};

int main() {

  // ----------------------- Initialisation of the data structure ---------------------------//
  int n, s, _r, _x, _y, _z;
  float pi = 3.14159265;
  while(scanf("%i%i", &n, &s) != EOF) {

    list<hole> hole_list; //Format : [..., [r,x,y,z], ...]
    //hole list, whole list, get it ? haha
    float slices[s];

    float total_vol = 1000000; // 100 * 100 * 100

    for(int i = 0; i < n; i ++) {
      scanf("%i%i%i%i", &_r, &_x, &_y, &_z);

      //Creating the hole struct corresponding
      hole _hole;
      _hole.r = _r / 1000;
      _hole.z = _z / 1000;
      hole_list.push_back(_hole);

      //Updating the real volume of the cheese
      total_vol -= (4/3) * pi * _hole.r * _hole.r * _hole.r;
      cout << "Vol updated : "<< _hole.r << " " << total_vol << endl; 


    }

    cout << "Total_vol : "<< total_vol << endl;

    float equalSlice_vol = total_vol / s; //The volume of one ideal slice
    hole_list.sort(); //IMPORTANT : we sort the list according to z coord of the holes (cf struct)

    // ----------------------- Slicing that cheese ---------------------------//
    //The idea is :
    // 1- Making a slice as if there where no holes
    // 2- Check the holes in the slice and calculate its actual total_mass
    // 3- Adjust the size of the slice to make it have the real mass (still considering that there are no other holes in the cheese)
    // 4- Repeat 2, 3 and 4 until convergence (for the slice)

    //Repeat the whole process for each slice until everything is done

    float _slice_begin = 0;
    float _slice_end = 0;

    for(int i = 0; i < s - 1; i ++){ //Iteration for each slice (no need to do the last slice as the end will just be the end of the cheese)
      float _slice_vol = 0;

      while(equalSlice_vol - _slice_vol > 0.000001){

        //Changing the border as if there were no holes
        _slice_end += (equalSlice_vol - _slice_vol) / 10000; // /(100*100)
        _slice_vol = (_slice_end - _slice_begin) * 10000; // *100 *100
        //_slice_vol = equalSlice_vol;
        //NOTE : at this point, _slice_vol should be equal to equalSlice_vol

        //Small safety
        if(_slice_end > 100){
          printf("Error : not enough cheese to make a slice that end at : %f", _slice_end);
          break;
        }

        //Calculating the actual mass
        for(hole _h : hole_list){
          //Sorry for whomever will read the code this is going to be messy
          //The problem is that there are many cases possible when the bubble is across the border of the slices
          //So I'm going to calculate a bunch of things for this bunch of possibilities
          //Trust me

          float vol_bubble         = (4/3) * pi * _h.r * _h.r * _h.r;
          float r_cap_begin        = abs(_h.r - abs(_slice_begin - _h.z));
          float vol_smol_cap_begin = (1/3) * pi * r_cap_begin * r_cap_begin * (3*_h.r - r_cap_begin);
          float vol_big_cap_begin  = vol_bubble - vol_smol_cap_begin;
          float r_cap_end          = abs(_slice_end - _h.z);
          float vol_smol_cap_end   = (1/3) * pi * r_cap_end * r_cap_end * (3*_h.r - r_cap_end);
          float vol_big_cap_end    = vol_bubble - vol_smol_cap_end;

          if(_h.z < _slice_begin - _h.r){
            //Nothing to do, the bubble is completely before the slice. I just put this for clarity
          }
          else if(_slice_begin - _h.r <= _h.z < _slice_begin){
            //The bubble is mostly before the slice
            _slice_vol -= vol_smol_cap_begin;
          }
          else if(_slice_begin <= _h.z < _slice_begin + _h.r){
            //The bubble is mostly inside the slice
            _slice_vol -= vol_big_cap_begin;
          }
          else if( _slice_begin + _h.r <= _h.z < _slice_end - _h.r){
            //The bubble is completely inside the slice
            _slice_vol -= vol_bubble;
          }
          else if( _slice_end - _h.r <= _h.z < _slice_end ){
            //The bubble is mostly inside the slice
            _slice_vol -= vol_big_cap_end;
          }
          else if( _slice_end <= _h.z < _slice_end + _h.r){
            //The bubble is mostly after the slice
            _slice_vol -= vol_smol_cap_end;
          }
          else if( _slice_end + _h.r < _h.z){
            //The bubble is completely after the slice
            break; //As the list of holes os sorted by z position of holes, we no longer need to check other holes
          }

        }

      }

      slices[i] = _slice_end - _slice_begin;
      _slice_begin = _slice_end;
    }

    slices[s-1] = 100 - _slice_end; // The last slice (that we don't need to calculate)

    // Print out the list
    for (float i: slices) {
        printf("%d ", i);
    }

  }

  return 0;
}
