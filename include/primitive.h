/*
include/primitive.h
(c) 2020 Nathan Isaac
Project: An implementation of PRA in C++
This code is licensed under the 3-clause BSD license (see LICENSE for details)
*/
#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include<functional>
#include<cln/integer.h>
struct s{
    template<typename X>
    cln::cl_I operator()(X&& x);
};
struct z{
    template<typename X>
    cln::cl_I operator()(X&& x);
};
template<unsigned int n, unsigned int i>
struct u{
    template<typename ...X>
    cln::cl_I operator()(X&&... x);
};
template<unsigned int m, unsigned int n,class F,class... G>
struct K{
    template<typename... X>
    cln::cl_I operator()(X&&... x);
};
template<class R_,unsigned int m,class F,class G>
struct R_base{
    template<typename N,typename... X>
    cln::cl_I operator()(N n,X... x);
};
template<unsigned int m,class F,class G>
struct R_iter : R_base<R_iter<m,F,G>,m,F,G>{
    template<class PSI,class MU,typename... X>
    cln::cl_I phi(cln::cl_I n,X... x);
    template<class PSI,class MU>
    cln::cl_I phi(cln::cl_I n);
};
template<unsigned int m,class F,class G>
struct R_rec : R_base<R_rec<m,F,G>,m,F,G>{
    template<class PSI,class MU,typename... X>
    cln::cl_I phi(cln::cl_I n,X... x);
    template<class PSI,class MU>
    cln::cl_I phi(cln::cl_I n);
};
#ifndef RECURSIVE
template<unsigned int m,class F,class G>
//using R=R_iterative<m,F,G>;
using R=R_iter<m,F,G>;
#else
template<unsigned int m,class F,class G>
//using R=R_recursive<m,F,G>;
using R=R_rec<m,F,G>;
#endif
#include "primitive.tpp"
#endif
