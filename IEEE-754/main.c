#include <stdio.h>
#include "IEEE754func.h"

int main()
{
    unsigned int IEEE_num = 0xfeff0028; /* 8 is the exponent */
    int answer = fp_exp(IEEE_num);
    printf("%d is the exponent of 0x%x\n", answer, IEEE_num, sizeof(int)); 

    answer = fp_frac(IEEE_num);
    printf("%x is the fraction in two's complement of 0x%x\n", answer, IEEE_num);

    answer = fp_enc(fp_frac(IEEE_num), fp_exp(IEEE_num));
    printf("%x is the IEEE-754 of the number\n", answer);

    return 0;
}
