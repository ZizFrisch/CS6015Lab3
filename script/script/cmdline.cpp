//
//  cmdline.cpp
// HW1 CS 6015
//
//  Created by Elisabeth Frischknecht on 1/11/24.
//

#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include "cmdline.hpp"
#include "expr.hpp"
#include <string>
#include <iostream>



void use_arguments(int argc, const char * argv[]){
    
    std::string arguments[] = {"--help", "--test"};
    bool tested = false;
    
    
    //the call to main is the first argument always. we want to check any other arguments.
    
    for(int i = 1; i < argc ; i++){
        //if argument is "--help" then print help text as to what arguments are allowed
        if (std::string(argv[i]) == "--help"){
            std::cout << "Arguments allowed include: " << std::endl;
            for(std::string argument: arguments){
                std::cout << argument + "\t";
            }
            exit(0);
        }
        else if(std::string(argv[i]) == "--test"){
            if(!tested){
                //if this function returns a non-zero value the program should quit with exit(1)
                if(Catch::Session().run(1, argv)!= 0){
                    exit(1);
                }
                //if all tests in the Catch::session were caught, we will print this statement
                std::cout << "Tests passed" << std::endl;
                tested = true;
            }else{
                std::cerr << "Tests should only be called once \n";
                exit(1);
            }
        }
        else{
            std::cerr << "An invalid argument was provided\n";
            exit(1);
        }
    }
    
    
}



