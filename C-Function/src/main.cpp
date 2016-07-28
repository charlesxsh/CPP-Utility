//
//  main.cpp
//
//  Created by Shihao Xia on 2/17/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//  

#include <iostream>
#include "function.hpp"

int print(int t)
{
    std::cout << t << std::endl;
    return t;
}

int main(int argc, const char* argv[])
{
    xsh::Function<int(int)> print_obj_1;
    print_obj_1 = print;
    print_obj_1(3); //print 3
    
    xsh::Function<int(int)> print_obj_2 = print;
    print_obj_2(5); //print 5
}
