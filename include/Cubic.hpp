#ifndef CUBIC_HPP
#define CUBIC_HPP

#include<math.h>

#define PI  3.14159265358979323846264338327950288419716939937511
inline bool cubic( float a, float b, float c, float d, float &X1, float &X2, float &X3 )
{
    float p = (3.*a*c - b*b) / (9.*a*a) ;
    float q = (b*c)/(6.*a*a) + b*b*b/(-27.*a*a*a) + d/(-2.*a) ;
    float C = b/(-3.*a) ;

    float delta = q*q + p*p*p ;
    if( delta <= 0. )
    {
        // Three real solutions.
        float sp = sqrt(-p) ;
        float teta = acos(q/(sp*sp*sp))/3.;
        float D = 2*sp ;

        X1 = C + D * cos(teta           ) ;
        X2 = C + D * cos(teta + PI*2./3.) ;
        X3 = C + D * cos(teta + PI*4./3.) ;
        return true ;
    }
    else
    {
        // One real solutions.
        delta = sqrt(delta) ;

        float q_p_delta = q + delta ;
        float q_n_delta = q - delta ;
        float A = copysign( pow( fabs(q_p_delta), 1./3. ), q_p_delta ) ;
        float B = copysign( pow( fabs(q_n_delta), 1./3. ), q_n_delta ) ;

        X1 = A + B + C ;
        X2 = NAN       ;
        X3 = NAN       ;
        return false ;
    }
}

#endif // CUBIC_HPP