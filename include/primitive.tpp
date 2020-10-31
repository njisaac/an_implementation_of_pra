/*
include/primitive.tpp
(c) 2020 Nathan Isaac
Project: An implementation of PRA in C++
This code is licensed under the 3-clause BSD license (see LICENSE for details)
*/
#ifndef PRIMITIVE_TPP
#define PRIMITIVE_TPP
#include "primitive.h"
#include<tuple>
#include<cln/integer.h>
#include<utility>
template<typename X>
cln::cl_I s::operator()(X&& x){
    return cln::plus1(x);
}
template<typename X>
cln::cl_I z::operator()(X&& x){
    return cln::cl_I(0);
}
template<unsigned int n, unsigned int i>
template<typename ...X>
cln::cl_I u<n,i>::operator()(X&&... x){
    static_assert(sizeof...(x)==n,"Parameter mismatch in U");
    static_assert(i<=n,"Not a valid projection function n<i");
    return std::get<i-1>(std::forward_as_tuple(x...));
}
template<unsigned int m, unsigned int n,class F,class... G>
template<typename... X>
cln::cl_I K<m,n,F,G...>::operator()(X&&... x){
    static_assert(sizeof...(G)==m,"Parameter mismatch: number of functions in K");
    static_assert(sizeof...(X)==n,"Parameter mismatch: number of parameters in K");
    return F()(std::apply(G(),std::forward_as_tuple(x...))...);   
}
template<class R_,unsigned int m,class F,class G>
template<typename N,typename... X>
cln::cl_I R_base<R_,m,F,G>::operator()(N n,X... x){
    static_assert(sizeof...(x)==(m-1),"Paramater mismatch in R");
    return static_cast<R_*>(this)->template phi<F,G>(n,x...);
}
template<unsigned int m,class F,class G>
template<class PSI,class MU,typename... X>
cln::cl_I R_iter<m,F,G>::phi(cln::cl_I n,X... x){
    cln::cl_I result=0;
    cln::cl_I k=0;
    result= PSI()(x...);
    while(k!=n){
        result=MU()(result,k,x...);
        k=cln::plus1(k);
    }
    return result;
}
template<unsigned int m,class F,class G>
template<class PSI,class MU>
cln::cl_I R_iter<m,F,G>::phi(cln::cl_I n){
    cln::cl_I result=0;
    cln::cl_I k=0;
    result= PSI()(k);
    while(k!=n){
        result=MU()(result,k);
        k=cln::plus1(k);
    }
    return result;
}
template<unsigned int m,class F,class G>
template<class PSI,class MU,typename... X>
cln::cl_I R_rec<m,F,G>::phi(cln::cl_I n,X... x){
    if(n==0){
        return PSI()(x...);
    }
    cln::cl_I n_=n-1;//Not able to forward n-1
    return MU()(phi_recursive<PSI,MU>(n_,x...),n_,x...);
}
template<unsigned int m,class F,class G>
template<class PSI,class MU>
cln::cl_I R_rec<m,F,G>::phi(cln::cl_I n){
    if(n==0){
        return PSI()(n);
    }
    cln::cl_I n_=n-1;
    return MU()(phi_recursive<PSI,MU>(n_),n_);
}
#endif
