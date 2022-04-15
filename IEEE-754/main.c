#include <stdio.h>
#include "IEEE754func.h"

int main()
{
    unsigned int IEEE_num = 0x416c0000; /*  0xfeff0028; /* 8 is the exponent */ 
    int exp = fp_exp(IEEE_num);
    printf("%d is the exponent of 0x%x\n", exp, IEEE_num); 

    int frac = fp_frac(IEEE_num);
    printf("0x%x is the fraction in two's complement of 0x%x\n", frac, IEEE_num);

    /* answer = fp_enc(fp_frac(IEEE_num), fp_exp(IEEE_num)); */
    int enc = fp_enc(0xF9DFFFFF, 0);
    printf("0x%x is the IEEE-754 of the number encoded\n", enc);

    return 0;
}
