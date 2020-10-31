/*
include/arithmetic.h
(c) 2020 Nathan Isaac
Project: An implementation of PRA in C++
This code is licensed under the 3-clause BSD license (see LICENSE for details)
*/
#ifndef ARITHMETIC_H
#define ARITHMETIC_H
#include "primitive.h"
#include<cln/integer.h>
using add=R<2,u<1,1>,K<1,3,s,u<3,1>>>;
using mult=R<2,z,K<2,3,add,u<3,3>,u<3,1>>>;
using fact=R<1,K<1,1,s,z>,K<2,2,mult,K<1,2,s,u<2,2>>,u<2,1>>>;
template<unsigned int m,typename N>
using C=R<m,N,u<m+1,1>>;
template<unsigned int n>
struct cwrp {
    template<typename X>
    cln::cl_I operator()(X&& x);
};
//usage C<n,cwrp<m>>
using sg=R<1,z,C<2,K<1,1,s,z>>>;
using nsg=R<1,K<1,1,s,z>,C<2,z>>;
using mu=R<1,z,u<2,2>>;
using sub=R<2,u<1,1>,K<1,3,mu,u<3,1>>>; //(a,b)->b-a
using greq=K<1,2,sg,sub>; //(a,b)->a>=b
using leq=K<2,2,greq,u<2,2>,u<2,1>>; //(a,b)->a>=b
using band=K<1,2,sg,K<2,2,add,u<2,1>,u<2,2>>>; //(a,b)->a&&b
using eq=K<2,2,band,sub,K<2,2,sub,u<2,2>,u<2,1>>>; ///(a,b)->a==b
//send (x_1,...,x_n)->F(s(x_2),x_3,x_4,...,x_n))
template<class n, class i>
using return_u=u<n::value,i::value>;
template<class m, class n,class F,class... G>
using return_K=K<m::value,n::value,F,G...>;
template<std::size_t m,class FN, class RHO, typename ints =std::make_index_sequence<m+1>>
struct h{
    template<typename... X>
    cln::cl_I operator()(X... x);
};
template<class RHO>
struct chi{
    template<typename... NZ>
    cln::cl_I operator()(NZ... nz);
};
template<unsigned int absx,unsigned int absz,class PHI,class CHI>
struct argmin{
    template<typename... XZ>
    cln::cl_I operator()(XZ&&... xz);
};
template<unsigned int absx,unsigned int absz,class ARGMIN,class REL>
struct psi{
    template<typename... XZ>
    cln::cl_I operator()(XZ&&... xz);
};
template<unsigned int absx,unsigned int absz,class PHI,class REL>
struct S{
    template<typename... XZ>
    cln::cl_I operator()(XZ&&... xz);
};
template<unsigned int absx,unsigned int absz,class PHI,class REL>
struct T{
    template<typename... XZ>
    cln::cl_I operator()(XZ&&... xz);
};
#include "arithmetic.tpp"
#endif
