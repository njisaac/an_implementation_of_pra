/*
include/arithmetic.tpp
(c) 2020 Nathan Isaac
Project: An implementation of PRA in C++
This code is licensed under the 3-clause BSD license (see LICENSE for details)
*/
#ifndef ARITHMETIC_TPP
#define ARITHMETIC_TPP
#include<boost/mp11.hpp>
#include<cln/integer.h>
#include<utility>
namespace mp11=boost::mp11;
template<unsigned int n>
template<typename X>
cln::cl_I cwrp<n>::operator()(X&& x){
    return cln::cl_I(n);
}
template<std::size_t m,class FN, class RHO, typename ints>
template<typename... X>
cln::cl_I h<m,FN,RHO,ints>::operator()(X... x){
    static_assert(m==sizeof...(x));
    using L1=mp11::mp_list<std::integral_constant<unsigned int,sizeof...(x)>>;
    //using L1=mp_repeat_c<L0,sizeof...(x)>;
    using L2=mp11::mp_from_sequence<ints>;
    using L3=mp11::mp_pop_front<mp11::mp_pop_front<mp11::mp_pop_front
                <mp11::mp_product<return_u,L1,L2>>>>;
    using KARGS=mp11::mp_push_front<L3,std::integral_constant<unsigned int,sizeof...(x)-1>,
        std::integral_constant<unsigned int,sizeof...(x)>,RHO,
        K<1,sizeof...(x),FN,u<sizeof...(x),2>>>;
    using KFUN=mp11::mp_apply<return_K,KARGS>;
    return std::apply(KFUN(),std::forward_as_tuple(x...));
}
template<class RHO>
template<typename... NZ>
cln::cl_I chi<RHO>::operator()(NZ... nz){
    using A1=K<1,sizeof...(nz)+1,nsg,
            K<1,sizeof...(nz)+1,nsg,h<sizeof...(nz)+1,z,RHO>>>;
    using A2=K<1,sizeof...(nz)+1,nsg,h<sizeof...(nz)+1,s,RHO>>;
    using A12=K<2,sizeof...(nz)+1,mult,A1,A2>;
    using A3=K<1,sizeof...(nz)+1,nsg,u<sizeof...(nz)+1,1>>;
    using A=K<2,sizeof...(nz)+1,mult,A12,A3>;
    using CHI1=K<2,sizeof...(nz)+1,mult,
            K<1,sizeof...(nz)+1,s,u<sizeof...(nz)+1,2>>,A>;
    using CHI2=K<2,sizeof...(nz)+1,mult,
            u<sizeof...(nz)+1,1>,K<1,sizeof...(nz)+1,nsg,A>>;
    using CHI=K<2,sizeof...(nz)+1,add,CHI1,CHI2>;
    return R<sizeof...(nz),K<1,sizeof...(nz)-1,z,
            u<sizeof...(nz)-1,1>>,CHI>()(nz...);
}
template<unsigned int absx,unsigned int absz,class PHI,class CHI>
template<typename... XZ>
cln::cl_I argmin<absx,absz,PHI,CHI>::operator()(XZ&&... xz){
    //static_assert(sizeof...(xz)==(absx+absz));
    std::array<cln::cl_I,sizeof...(xz)> vals;
    vals={std::forward<XZ>(xz)...};
    std::array<cln::cl_I,absx> xvals;
    std::array<cln::cl_I,absz> zvals;
    for(unsigned int i=0;i<absx;i++){
        xvals[i]=vals[i];
    }
    for(unsigned int i=0;i<absz;i++){
        zvals[i]=vals[i+(sizeof...(xz)-absz)];
    }
    auto chiargs = std::tuple_cat(std::forward_as_tuple(
                        std::apply(PHI(),xvals)),zvals);
    return std::apply(CHI(),chiargs);
}
template<unsigned int absx,unsigned int absz,class ARGMIN,class REL>
template<typename... XZ>
cln::cl_I psi<absx,absz,ARGMIN,REL>::operator()(XZ&&... xz){
    //static_assert(sizeof...(xz)==(absx+absz));
    std::array<cln::cl_I,sizeof...(xz)> vals;
    vals={std::forward<XZ>(xz)...};
    std::array<cln::cl_I,absz> zvals;
    for(unsigned int i=0;i<absz;i++){
        zvals[i]=vals[i+(sizeof...(xz)-absz)];
    }
    auto rargs = std::tuple_cat(std::forward_as_tuple(
                        std::apply(ARGMIN(),vals)),zvals);
    return std::apply(REL(),rargs);
}
template<unsigned int absx,unsigned int absz,class PHI,class REL>
template<typename... XZ>
cln::cl_I S<absx,absz,PHI,REL>::operator()(XZ&&... xz){
    return psi<absx,absz,argmin
            <absx,absz,PHI,chi<REL>>,REL>()(xz...);
}
template<unsigned int absx,unsigned int absz,class PHI,class REL>
template<typename... XZ>
cln::cl_I T<absx,absz,PHI,REL>::operator()(XZ&&... xz){
    return K<1,sizeof...(xz),nsg,psi<absx,absz,argmin<
            absx,absz,PHI,chi<K<1,absz+1,nsg,REL>>>,
            K<1,absz+1,nsg,REL>>>()(xz...);
}
#endif
