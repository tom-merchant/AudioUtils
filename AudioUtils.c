#include "AudioUtils.h"

#include <math.h>
#include <stdlib.h>

void remove_dc_offset(double* signal, long num_samples)
{
    int i;
    double sum;

    for(i = 0; i < num_samples; i++)
    {
        sum += signal[i];
    }

    sum /= num_samples;

    for(i = 0; i < num_samples; i++)
    {
        signal[i] -= sum;
    }
}

void normalise(double* signal, long num_samples)
{
    int i;
    double maxsample = 0;

    for(i = 0; i < num_samples; i++)
    {
        maxsample = MAX( maxsample, fabs ( signal [ i ] ));
    }

    for(i = 0; i < num_samples; i++)
    {
        signal[i] /= maxsample;
    }
}

void calculate_newton_polynomial ( int order, double *points, double* x, double* coefficients_out )
{
    int i, j;
    double** divided_differences;

    divided_differences = malloc ( order * sizeof ( void* ) );

    coefficients_out [ 0 ] = points [ 0 ];

    for ( i = 0; i < order; i++ )
    {
        divided_differences [ i ] = malloc ( ( order - i ) * sizeof ( double ) );

        for ( j = 0; j < ( order - i ); j++ )
        {
            if ( i != 0 )
            {
                divided_differences[ i ][ j ] =
                        ( divided_differences [ i - 1 ] [ j + 1 ] - divided_differences [ i - 1 ] [ j ] )
                        / ( x [ j + i + 1 ] - x [ j ] );
            }
            else
            {
                divided_differences[ i ][ j ] = ( points [ j + 1 ] - points [ j ] ) / ( x [ j + 1 ] - x [ j ] );
            }
        }

        coefficients_out [ i + 1 ] = divided_differences [ i ] [ 0 ];
    }
}

double newton_horner_eval ( int order, double* coefficients, double* abscissae, double x )
{
    int i;
    double result;

    result = coefficients [ order ];

    for ( i = order; i > 0; i-- )
    {
        result *= ( x - abscissae[ i - 1 ] );
        result += coefficients [ i - 1 ];
    }

    return result;
}
