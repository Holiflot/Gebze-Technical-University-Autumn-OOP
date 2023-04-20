#include "AbstractTetris.hpp"

AbstractTetris :: AbstractTetris(int h,int w): heigth(h), width(w){}//constructers
AbstractTetris :: AbstractTetris(int h): heigth(h),width(0){}
AbstractTetris :: AbstractTetris(): heigth(0), width(0){}