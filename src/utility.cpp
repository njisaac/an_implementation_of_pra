/*
src/utility.cpp
(c) 2020 Nathan Isaac
Project: An implementation of PRA in C++
This code is licensed under the 3-clause BSD license (see LICENSE for details)
*/
#include "utility.h"
#include<cln/integer_io.h>
#include<sstream>
void pr(cln::cl_I&& val){
    std::stringstream ss;
    cln::fprintdecimal(ss,val);
    std::cout<<ss.str()<<"\n";
}
