/*
src/examples.cpp
(c) 2020 Nathan Isaac
Project: An implementation of PRA in C++
This code is licensed under the 3-clause BSD license (see LICENSE for details)
*/
#include "examples.h"
#include "examples_eq.h"
#include "arithmetic.h"
#include "primitive.h"
#include "utility.h"
#include<cln/integer.h>
void testfunc(){
    cln::cl_I c = 5;
    cln::cl_I d = 3;
    cln::cl_I a = 1;
    cln::cl_I e = 9;
    cln::cl_I f = 10;
    cln::cl_I g = 81;
    pr(expr1()(d,e,d));
    pr(chi<expr1>()(f,e,d));
    std::cout<<"\n";
    pr(argmin<1,2,u<1,1>,chi<expr1>>()(e,d));
    pr(argmin<1,2,u<1,1>,chi<expr1>>()(f,c));
    pr(argmin<1,2,u<1,1>,chi<expr1>>()(g,e));
    pr(argmin<1,2,u<1,1>,chi<expr1>>()(e,g));
    pr(S<1,2,u<1,1>,expr1>()(g,e));
    pr(T<1,1,u<1,1>,leq>()(g,e));
    pr(T<1,1,u<1,1>,leq>()(e,g));
    pr(T<1,1,u<1,1>,greq>()(g,e));
    pr(T<1,1,u<1,1>,greq>()(e,g));
    pr(expr1()(e,g,e));
    pr(argmin<1,2,u<1,1>,chi<expr1>>()(e,g));
    pr(chi<expr1>()(f,e,d));
    pr(h<3,s,u<2,1>>()(4,6,5));
    pr(fact()(3));
}
