#include "IEEE754func.h"
#include <stdio.h>

int fp_exp(unsigned int IEEE_num)
{   
    IEEE_num <<= 1; /* shifts left one to get rid of sign bit */
    IEEE_num >>= 24; /* shifts 24 times right to get rid of fraction part */
    return IEEE_num - 127; /* returs exponent without constant bias */
}
unsigned int fp_frac(unsigned int IEEE_num)
{
    unsigned int signBitMask = 0x80000000; /* bit mask that checks MSB is set */
    _Bool isNeg = 0; /* assume num is positive */
    if (IEEE_num & signBitMask) /* checks MSB of 32 bit and if != then this num is a negative IEEE-754 number */
    {
        isNeg = 1; /* num is negative */
    }
    signBitMask = 0x007FFFFF; /* bit mask that clears everything to the left of the mantisa */
    IEEE_num &= signBitMask; /* cleared to the left of mantisa */
    signBitMask = 0x00800000; /* bit mask that sets the bit to the left of mantia (left of radix point) */
    IEEE_num |= signBitMask; /* IEEE_num is now in the form 0 00000001.fffffffffffffffffffffff where f is the mantisa */
    if (isNeg)
    {
        return -IEEE_num; /* the 2's complement of the number */
    }
    return IEEE_num; /* else return positive IEEE_num */
}
unsigned int clz(int fraction)
{
    unsigned int signBitMask = 0x80000000; /* bit mask that clears the MSB of 32 bit*/
    unsigned char count; /* using char as it is memory efficient */
    for (count = 0; !(fraction & signBitMask); count++) /* keeps shifting left until matching signBit */
    {
        fraction <<= 1;
    }
    return count; /* returns leading zeros from fraction */
}
unsigned int fp_enc(int fraction, int exponent)
{
    int signBitMask = 0x80000000; /* bit mask that clears the MSB of 32 bit */
    _Bool isNeg = 0; /* assume fraction is positive */
    if (fraction & signBitMask) /* checks MSB of 32 bit and if != then this num is a negative IEEE-754 number */
    {
        fraction = -fraction; /* making the fraction part positive for IEEE-754 */
        isNeg = 1;
    }
    unsigned char countOfZeros = clz(fraction); /* count that is memory efficient */
    printf("count of zeros is %d\n", countOfZeros);
    if (countOfZeros < 8)
    {
        countOfZeros = 8 - countOfZeros;
        fraction >>= countOfZeros;
        exponent += countOfZeros;
    }
    else if (countOfZeros > 8)
    {
        countOfZeros -= 8;
        fraction <<= countOfZeros;
        exponent -= countOfZeros;
    }
    signBitMask = 0xFF7FFFFF; /* bit mask to clear hidden bit */
    fraction &= signBitMask;
    exponent += 127; /* added constant bias */
    exponent <<= 23; /* left shift 23 bits to bring to proper position */
    fraction |= exponent; /* putting fraction into proper position */
    if (isNeg)
    {
        signBitMask = 0x80000000; /* created mask to set MSB to 1 since floating point num is negative */
        fraction |= signBitMask;
    }
    /* else not negative no need to set bit 31 to 0 */
    return fraction; /* actually returns the IEE-754 numbers */
}
