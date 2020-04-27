#ifndef AUDIOUTILS_AUDIOUTILS_H
#define AUDIOUTILS_AUDIOUTILS_H


void remove_dc_offset            ( double* signal, long num_samples );
void normalise                   ( double* signal, long num_samples );

void calculate_newton_polynomial ( int order, double *points, double *x, double* coefficients_out );
double newton_horner_eval        ( int order, double* coefficients, double* abscissae, double x );

#ifndef MAX
#define MAX(a, b) ( (a) > (b) ? (a) : (b) )
#endif

#endif //AUDIOUTILS_AUDIOUTILS_H