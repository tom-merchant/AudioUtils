//
// Created by tmerchant on 30/03/2020.
//

#include "AudioUtils.h"

#include <stdio.h>
#include <assert.h>

int main()
{
    int i;
    double abscissae[5] = {1,    2,   4,   8,   15 };
    double ordinates[5] = {-0.5, 0.4, 0.9, 1.5, 1.9};
    double coefficients[5];

    calculate_newton_polynomial (4, ordinates, abscissae, coefficients);

    assert(newton_horner_eval (4, coefficients, abscissae, 0) - (-2.189625) <= 0.0001);
}