#ifndef IEEE754func_H_INCLUDED
#define IEEE754func_H_INCLUDED

/* takes int/hex IEEE-754 and returns exponent */
int fp_exp(unsigned int IEEE_num);

/* takes int/hex IEEE-754 and returns fraction as signed including hidden bit */
unsigned int fp_frac(unsigned int IEEE_num);

/* CountOfLeadingZeros subroutine, counts the leading 0's from MSB in the fraction, used in fp_enc */
unsigned int clz(int fraction);

/* takes in fraction (in 2's complement) and exponent (in 2's complement) and returns IEEE-754 number */
unsigned int fp_enc(int fraction, int exponent);

#endif