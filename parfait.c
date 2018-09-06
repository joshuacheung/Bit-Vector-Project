#include "bv.h"
#include "sieve.h"
#include <stdio.h>

int main(void){

  uint32_t length = 1000;  //how many numbers are being checked
  bitV *vect = newVec(length);
  oneVec(vect);
  sieve(vect); //determing whether prime or composite

  uint32_t perfectFactors[1000];
  uint32_t j = 0;
  uint32_t count;
  uint32_t sum;
  uint32_t divisor;
  
  for(uint32_t i = 2; i < lenVec(vect)+1; i++){
    if(valBit(vect, i) == 1){ //if the bitVector is prime
      printf("%d P: \n", i );
    }else{
      divisor = 2;
      if(valBit(vect,i) == 0){ //if the bitVector is composite
        j = i;
        printf("%d C: ", i);

        while(j > 1){  //code adapted from DDEL 4/20/17
            if(j%divisor == 0){
            j /= divisor;
            printf("%d ", divisor);
          }else{
            divisor = divisor + 1;
          }
        }
        //checking for perfect numbers
        count = 0;
        sum = 0;
        for(uint32_t factor = 1; factor < i; factor++){
          if(i%factor==0){
            perfectFactors[count] = factor;  //adding factors to array
            count++;
            sum+=factor;
          }
        }
        if(sum == i){
          printf("\n%d E: ", i);
          for(uint32_t m = 0; m < count; m++){ //printing array of perfect factors
            printf("%d ", perfectFactors[m]);
          }
        }
      }
      printf("\n");
    }
  }
}
