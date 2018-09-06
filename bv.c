#include "bv.h"
#include <stdlib.h>
#include <math.h>

bitV* newVec(uint32_t val){  //creates a new vector of specified length
   bitV* bvec = calloc(1, sizeof(bitV));
   bvec->l = val;
   bvec->v = calloc(1, ceil(val/8));
   return bvec;
}

void delVec(bitV * vect){  //deletes a vector
  free(vect->v);
}

void oneVec(bitV * vect){  //creates a vector of all 1
  for(int x =0;x<ceil(vect->l/8)+1;x++){
    *(vect->v+x) = *(vect->v+x) | ~*(vect->v+x);
  }
}

void setBit(bitV * vect, uint32_t val){  //sets a specified bit
  (*(vect->v+(val/8))) |= (1<<(7-val%8));

}

void clrBit(bitV * vect, uint32_t val ){ //clears a specified bit
  (*(vect->v+(val/8))) &= ~(1<<(7-val%8));
}

uint8_t valBit(bitV * vect, uint32_t val){  //return the value of the vector
   uint8_t value = (*(vect->v+(val/8))) >> (7-(val%8)) & 1;
   return value;
}

uint32_t lenVec(bitV * vect){
  return vect->l;
}
