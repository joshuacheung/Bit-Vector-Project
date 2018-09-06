// bv.h — Bit Vector interface
// Author: Prof. Darrell Long

# ifndef _BVector
# define _BVector
# include <stdint.h>
s
typedef struct bitV {
	uint8_t *v;
	uint32_t l;
} bitV;

bitV *newVec(uint32_t val);

void delVec(bitV * vect);

void oneVec(bitV * vect);

void setBit(bitV * vect, uint32_t val);

void clrBit(bitV * vect, uint32_t val);

uint8_t valBit(bitV * vect, uint32_t val);

uint32_t lenVec(bitV * vect);
# endif
