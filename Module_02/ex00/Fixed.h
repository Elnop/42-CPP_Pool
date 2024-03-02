#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string.h>


class Fixed
{
private:
    int _fixed_point;
    static const int _nFractBits = 8;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed&  operator=  (const Fixed& other);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};


#endif