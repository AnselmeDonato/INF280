#include <iostream>
using namespace std;

int main() {
  int candles_left, d, r, t, real_r, real_t, age_r, age_t, x;

  while(scanf("%i", &d) != EOF) {
    scanf("%i", &r);
    scanf("%i", &t);

    candles_left = r + t;
    real_t = 0;
    real_r = 0;

    //The idea is to "fill" the age by redistrbuting the candles one by once
    age_r = 4;
    while(candles_left > 0) {
      real_r += age_r; //That's for Rita
      candles_left -= age_r;

      age_t = age_r - d;
      if(age_t > 2){ //Thats for Theo
        real_t += age_t;
        candles_left -= age_t;
      }

      age_r += 1;
    }

    x = (r - real_r);
    printf("%i\n", x);

  }
  return 0; 
}
