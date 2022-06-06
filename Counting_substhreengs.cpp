#include <iostream>
#include <string>
#include <exception>

using namespace std;

/*
DAC(a, i, j)
{
    if(small(a, i, j))
      return(Solution(a, i, j))
    else
      m = divide(a, i, j)               // f1(n)
      b = DAC(a, i, mid)                 // T(n/2)
      c = DAC(a, mid+1, j)            // T(n/2)
      d = combine(b, c)                 // f2(n)
   return(d)
}
*/

int DCA(string _strNumber, int* _count){
  if(_strNumber.size() == 1){
    int n = stoi(_strNumber);
    cout << "minimal length : "<< stoi(_strNumber) << endl;
    if(n % 3 == 0){
      cout << " +1" << endl;
      _count += 1;
    }
    return stoi(_strNumber);
  }
  else {
    int mid = (int) _strNumber.size()/2;
    cout << "mid : "<< mid << endl;
    string half1(_strNumber.begin(), _strNumber.begin() + mid);
    string half2(_strNumber.begin() + mid, _strNumber.end());
    cout << "Half1 : " << half1 << " Half 2: "<< half2 << endl;
    int a1 = DCA(half1, _count);
    int a2 = DCA(half2, _count);
    int d = a1 + a2;
    cout << "d: "<< d << endl;
    if(d % 3 == 0){
      _count += 1;
      cout << " comb +1 : " << _count << endl;
    }
    return d;
  }
}

int main() {
  char c;
  string numberString = "";
  bool startNumber = false;
  int nb_sub = 0;

  while(scanf("%c", &c) != EOF) {
    if(48 <= c && c <= 57) {
      numberString.push_back(c);
      startNumber = true;
    }

    else{
      if(startNumber){
        cout << "Number string : "<< numberString << endl;
        DCA(numberString, &nb_sub);
      }

      if(c == 10){
        printf("%i\n", nb_sub);
        nb_sub = 0;
      }

      startNumber = false;
      numberString.clear();

    }

  }

  return 0;
}
