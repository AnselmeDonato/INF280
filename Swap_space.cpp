#include <iostream>
#include <list>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

struct drive {
  unsigned long long comp;
  int a, b;

  bool operator>(const drive& d) {
    if(comp == d.comp) {return(b < d.b);}
    return comp > d.comp;
  }
  bool operator>=(const drive& d) {
    if(comp == d.comp) {return(b <= d.b);}
    return comp >= d.comp;
  }
  bool operator<(const drive& d) {
    if(comp == d.comp) {return(b > d.b);}
    return comp < d.comp;
  }
  bool operator<=(const drive& d) {
    if(comp == d.comp) {return(b >= d.b);}
    return comp <= d.comp;
  }
};

int main() {
  int n;
  list<drive> list_drives;
  while(scanf("%i", &n) != EOF){
    list_drives.clear();
    unsigned long long _a,_b;
    for(int i = 0; i < n; i ++){
      scanf("%i%i", &_a, &_b);
      drive _drive;
      if(_b > _a){
        _drive.comp = _a;
        _drive.a = _a;
        _drive.b = _b;
      }
      else {
        _drive.comp = ULLONG_MAX - _b; //In that case the drive will consume more free space than it wil give : we must trat it at the very end
        _drive.a = _a;
        _drive.b = _b;
      }
      list_drives.push_back(_drive);
    }

    list_drives.sort();

    /*
    for(drive d : list_drives){
      printf("%llu, %i, %i \n", d.comp, d.a, d.b);
    } */

    unsigned long long need = 0;
    unsigned long long free = 0;

    for(drive _d : list_drives) {
      if(free < _d.a){
        need += _d.a - free;
        free = _d.b;
      }
      else{
        free += _d.b - _d.a;
      }
      //printf("Needed : %llu Free : %llu \n", need, free);
    }
    printf("%llu\n", need);
  }
  return 0;
}
