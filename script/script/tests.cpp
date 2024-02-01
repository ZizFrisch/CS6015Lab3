//
//  tests.cpp
//  HW1
//
//  Created by Elisabeth Frischknecht on 1/23/24.
//

#include <stdio.h>
#include "catch.h"
#include "expr.hpp"



TEST_CASE("Test Num Expression"){
    SECTION("TEST EQUALS"){
        //check positive numbers
        CHECK( (new Num(5))->equals(new Num(5))==true);
        CHECK( (new Num(5))->equals(new Num(4))==false);
        
        //check negative numbers
        CHECK( (new Num(-5))->equals(new Num(-5))==true);
        CHECK( (new Num(-5))->equals(new Num(5))==false);
        CHECK( (new Num(5))->equals(new Num(-5))==false);
        
        //check zero
        CHECK( (new Num(0))->equals(new Num(0))==true);
        CHECK( (new Num(0))->equals(new Num(5))==false);
        CHECK( (new Num(5))->equals(new Num(0))==false);
        CHECK( (new Num(0))->equals(new Num(-5))==false);
        CHECK( (new Num(-5))->equals(new Num(0))==false);
        
        //check int max and int min

        CHECK( (new Num(2147483647))->equals(new Num(2147483647))==true);
        CHECK( (new Num(-2147483648))->equals(new Num(2147483647))==false);
        CHECK( (new Num(2147483647))->equals(new Num(-2147483648))==false);
        CHECK( (new Num(-2147483648))->equals(new Num(-2147483648))==true);
        

        //check for the wrong class
        CHECK( (new Num(5))->equals(new Add(new Num(2),new Num(3)) )==false);
        CHECK( (new Num(6))->equals(new Mult(new Num(2), new Num(3) ) )==false);
        CHECK((new Num (5)) ->equals(new Var("x")) == false);
    }
    
    SECTION("test subt"){
        CHECK( (new Num(7))->subst("x", new Var("y"))->equals(new Num(7)) );
        CHECK( (new Num(0))->subst("x", new Var("y"))->equals(new Num(0)) );
        CHECK( (new Num(-1))->subst("x", new Var("y"))->equals(new Num(-1)) );
        CHECK( (new Num(2147483647))->subst("x", new Var("y"))->equals(new Num(2147483647)) );
        CHECK( (new Num(-2147483648))->subst("x", new Var("y"))->equals(new Num(-2147483648)) );
        
    }
    
    SECTION("Num test has variable"){
        CHECK( (new Num(7))->subst("x", new Var("y"))->has_variable() == false );
        CHECK( (new Num(0))->subst("x", new Var("y"))->has_variable() == false );
        CHECK( (new Num(-1))->subst("x", new Var("y"))->has_variable() == false );
        CHECK( (new Num(2147483647))->subst("x", new Var("y"))->has_variable() == false );
        CHECK( (new Num(-2147483648))->subst("x", new Var("y"))->has_variable() == false );
    }
    
    SECTION("Num test interp"){
        CHECK( (new Num(7))->subst("x", new Var("y"))->interp() == 7 );
        CHECK( (new Num(0))->subst("x", new Var("y"))->interp() == 0 );
        CHECK( (new Num(-1))->subst("x", new Var("y"))->interp() == -1 );
        CHECK( (new Num(2147483647))->subst("x", new Var("y"))->interp() == 2147483647 );
        CHECK( (new Num(-2147483648))->subst("x", new Var("y"))->interp() == -2147483648);
    }

}

TEST_CASE("TEST ADD EXPRESSION"){
    SECTION("TEST EQUALS"){
        //test positive numbers
        CHECK( (new Add(new Num(2),new Num(3)))->equals(new Add(new Num(2),new Num(3)))==true );
        CHECK( (new Add(new Num(2),new Num(3)))->equals(new Add(new Num(3),new Num(2)))==false );
        
        
        //test negative numbers
        CHECK( (new Add(new Num(-2),new Num(-3)))->equals(new Add(new Num(-3),new Num(-2)))==false );
        CHECK( (new Add(new Num(-2),new Num(-3)))->equals(new Add(new Num(-2),new Num(-3)))==true );
        CHECK( (new Add(new Num(2),new Num(3)))->equals(new Add(new Num(-2),new Num(3)))==false );
        CHECK( (new Add(new Num(2),new Num(3)))->equals(new Add(new Num(2),new Num(-3)))==false );
        CHECK( (new Add(new Num(2),new Num(3)))->equals(new Add(new Num(-2),new Num(-3)))==false );
        
        //test zero
        CHECK( (new Add(new Num(0),new Num(3)))->equals(new Add(new Num(0),new Num(3)))==true );
        CHECK( (new Add(new Num(2),new Num(3)))->equals(new Add(new Num(0),new Num(3)))==false );
        CHECK( (new Add(new Num(0),new Num(0)))->equals(new Add(new Num(0),new Num(0)))==true );
        CHECK( (new Add(new Num(2),new Num(3)))->equals(new Add(new Num(2),new Num(0)))==false );
        CHECK( (new Add(new Num(2),new Num(0)))->equals(new Add(new Num(2),new Num(3)))==false );
        CHECK( (new Add(new Num(0),new Num(3)))->equals(new Add(new Num(2),new Num(3)))==false );
        
        
        //check int max and int min
        CHECK( (new Add(new Num(2147483647),new Num(2147483647)))->equals(new Add(new Num(2147483647),new Num(2147483647)))==true );
        CHECK( (new Add(new Num(-2147483648),new Num(-2147483648)))->equals(new Add(new Num(-2147483648),new Num(-2147483648)))==true );
        CHECK( (new Add(new Num(2147483647),new Num(2147483647)))->equals(new Add(new Num(-2147483648),new Num(2147483647)))==false );
        CHECK( (new Add(new Num(2147483647),new Num(2147483647)))->equals(new Add(new Num(2147483647),new Num(-2147483648)))==false );
        
        //check for wrong classes
        CHECK( (new Add(new Num(0),new Num(3)))->equals(new Num(0))==false );
        CHECK( (new Add(new Num(2),new Num(3)))->equals(new Mult(new Num(2),new Num(3)))==false );
        CHECK( (new Add(new Num(0),new Num(3)))->equals(new Var("x"))==false );
        
        //check for nested expressions
        CHECK( (new Add(new Add(new Num (0), new Num(3)),new Num(3)))->equals(new Num (6))==false );
        CHECK( (new Num (6))->equals(new Add(new Add(new Num (0), new Num(3)),new Num(3)))==false );
        CHECK( (new Add(new Add(new Num (0), new Num(3)),new Num(3)))->equals(new Add(new Add(new Num (0), new Num(3)),new Num(3)))==true );
    }
    
    SECTION("TEST INTERP"){
        CHECK( (new Add(new Add(new Num(10), new Num(15)),new Add(new Num(20),new Num(20))))
                ->interp()==65);
        
        //test positive numbers
        CHECK( (new Add(new Num(2),new Num(3)))->interp() == 5 );
        CHECK( (new Add(new Num(3),new Num(2)))->interp() == 5 );
        
        
        //test negative numbers
        CHECK( (new Add(new Num(-2),new Num(-3)))->interp()== -5 );
        CHECK( (new Add(new Num(-3),new Num(-2)))->interp()== -5 );
        CHECK( (new Add(new Num(-2),new Num(3)))->interp()== 1 );
        CHECK( (new Add(new Num(2),new Num(-3)))->interp()== -1 );
        
        //test zero
        CHECK( (new Add(new Num(0),new Num(3)))->interp()== 3 );
        CHECK( (new Add(new Num(2),new Num(0)))->interp() == 2);
        CHECK( (new Add(new Num(0),new Num(0)))->interp()== 0 );
        CHECK( (new Add(new Num(0),new Num(-3)))->interp()== -3 );
        CHECK( (new Add(new Num(-2),new Num(0)))->interp() == -2);
        
        //check for nested expressions
        CHECK( (new Add(new Add(new Num (0), new Num(3)),new Num(3)))->interp() == 6 );
        CHECK( (new Add(new Mult(new Num(5),new Num(2)), new Num(4) ))->interp() == 14 );
        CHECK( (new Add(new Add(new Num (1), new Num(3)),new Num(3)))->interp() == 7 );
    }
    
    SECTION("test has_variable"){
        //check basic
        CHECK( (new Add(new Var("x"), new Num(1)))->has_variable() == true );
        CHECK( (new Add(new Num(1), new Var("y")))->has_variable() == true );
        
        //add false
        CHECK( (new Add(new Num(5), new Num(1)))->has_variable() == false );
        
        //add nested
        CHECK( (new Add(new Num(5), new Mult(new Num(6), new Var("x")) ))->has_variable() == true );
        CHECK( (new Add(new Num(5), new Add(new Num(6), new Var("y")) ))->has_variable() == true );
    }
    
    SECTION("TEST SUBST"){
        
        //no substitution
        CHECK( (new Add(new Num(5), new Num(7)) )->subst("x", new Var("y"))->equals(new Add(new Num(5), new Num(7))) );
        
        //basic substitution
        CHECK( (new Add(new Var("x"), new Num(7)))->subst("x", new Var("y"))->equals(new Add(new Var("y"), new Num(7))) );
        CHECK( (new Add(new Num(7), new Var("x")))->subst("x", new Var("y"))->equals(new Add(new Num(7),new Var("y"))) );
        CHECK( (new Add(new Var("x"), new Num(7)))->subst("x", new Num(0))->equals(new Add(new Num(0), new Num(7))) );
        CHECK( (new Add(new Num(7), new Var("x")))->subst("x", new Num(0))->equals(new Add(new Num(7),new Num(0))) );
        
        //check nested
        CHECK( (new Add(new Var("x"), new Num(7)))->subst("x", new Add(new Num(5), new Var("y")) )->equals(new Add(new Add(new Num(5), new Var("y")), new Num(7))) );
    }
    
}

TEST_CASE("TEST MULT EXPRESSION"){
    SECTION("test equals"){
        //test positive numbers
        CHECK( (new Mult(new Num(2),new Num(3)))->equals(new Mult(new Num(2),new Num(3)))==true );
        CHECK( (new Mult(new Num(2),new Num(3)))->equals(new Mult(new Num(3),new Num(2)))==false );
        
        
        //test negative numbers
        CHECK( (new Mult(new Num(-2),new Num(-3)))->equals(new Mult(new Num(-3),new Num(-2)))==false );
        CHECK( (new Mult(new Num(-2),new Num(-3)))->equals(new Mult(new Num(-2),new Num(-3)))==true );
        CHECK( (new Mult(new Num(2),new Num(3)))->equals(new Mult(new Num(-2),new Num(3)))==false );
        CHECK( (new Mult(new Num(2),new Num(3)))->equals(new Mult(new Num(2),new Num(-3)))==false );
        CHECK( (new Mult(new Num(2),new Num(3)))->equals(new Mult(new Num(-2),new Num(-3)))==false );
        
        //test zero
        CHECK( (new Mult(new Num(0),new Num(3)))->equals(new Mult(new Num(0),new Num(3)))==true );
        CHECK( (new Mult(new Num(2),new Num(3)))->equals(new Mult(new Num(0),new Num(3)))==false );
        CHECK( (new Mult(new Num(0),new Num(0)))->equals(new Mult(new Num(0),new Num(0)))==true );
        CHECK( (new Mult(new Num(2),new Num(3)))->equals(new Mult(new Num(2),new Num(0)))==false );
        CHECK( (new Mult(new Num(2),new Num(0)))->equals(new Mult(new Num(2),new Num(3)))==false );
        CHECK( (new Mult(new Num(0),new Num(3)))->equals(new Mult(new Num(2),new Num(3)))==false );
        
        
        //check int max and int min
        CHECK( (new Mult(new Num(2147483647),new Num(2147483647)))->equals(new Mult(new Num(2147483647),new Num(2147483647)))==true );
        CHECK( (new Mult(new Num(-2147483648),new Num(-2147483648)))->equals(new Mult(new Num(-2147483648),new Num(-2147483648)))==true );
        CHECK( (new Mult(new Num(2147483647),new Num(2147483647)))->equals(new Mult(new Num(-2147483648),new Num(2147483647)))==false );
        CHECK( (new Mult(new Num(2147483647),new Num(2147483647)))->equals(new Mult(new Num(2147483647),new Num(-2147483648)))==false );
        
        //check for wrong classes
        CHECK( (new Mult(new Num(0),new Num(3)))->equals(new Num(0))==false );
        CHECK( (new Mult(new Num(2),new Num(3)))->equals(new Add(new Num(2),new Num(3)))==false );
        CHECK( (new Mult(new Num(0),new Num(3)))->equals(new Var("x"))==false );
        
        //check for nested expressions
        CHECK( (new Mult(new Add(new Num (0), new Num(3)),new Num(3)))->equals(new Mult (new Add(new Num (0), new Num(3)),new Num(4)))==false );
        CHECK( (new Num (6))->equals(new Mult(new Add(new Num (0), new Num(3)),new Num(3)))==false );
        CHECK( (new Mult(new Add(new Num (0), new Num(3)),new Num(3)))->equals(new Mult(new Add(new Num (0), new Num(3)),new Num(3)))==true );
    }
    
    SECTION("TEST INTERP"){
        CHECK( (new Mult(new Num(3), new Num(2)))->interp()==6 );
        
        CHECK( (new Mult(new Add(new Num(10), new Num(15)),new Add(new Num(20),new Num(20))))
                ->interp()==1000);
        
        //test positive numbers - reciprocal
        CHECK( (new Mult(new Num(2),new Num(3)))->interp() == 6 );
        CHECK( (new Mult(new Num(3),new Num(2)))->interp() == 6 );
        
        
        //test negative numbers
        CHECK( (new Mult(new Num(-2),new Num(-3)))->interp()== 6 );
        CHECK( (new Mult(new Num(-3),new Num(-2)))->interp()== 6 );
        CHECK( (new Mult(new Num(-2),new Num(3)))->interp()== -6 );
        CHECK( (new Mult(new Num(2),new Num(-3)))->interp()== -6 );
        
        //test zero
        CHECK( (new Mult(new Num(0),new Num(3)))->interp()== 0 );
        CHECK( (new Mult(new Num(2),new Num(0)))->interp() == 0);
        CHECK( (new Mult(new Num(0),new Num(0)))->interp()== 0 );
        CHECK( (new Mult(new Num(0),new Num(-3)))->interp()== -0 );
        CHECK( (new Mult(new Num(-2),new Num(0)))->interp() == -0);
        
        //check for nested expressions
        CHECK( (new Mult(new Add(new Num (0), new Num(3)),new Num(3)))->interp() == 9 );
        CHECK( (new Mult(new Mult(new Num(5),new Num(2)), new Num(4) ))->interp() == 40 );
        CHECK( (new Mult(new Add(new Num (1), new Num(3)),new Num(3)))->interp() == 12 );
    }
    
    
    SECTION("TEST has_variable"){
        CHECK( (new Mult(new Num(2), new Num(1)))->has_variable() == false );
        CHECK( (new Mult(new Var("x"), new Num(1)))->has_variable() == true );
        CHECK( (new Mult(new Num(1), new Var("x")))->has_variable() == true );
        
        //nested
        CHECK ( (new Mult(new Mult(new Num(7),new Var("x")),new Num(6)))->has_variable() == true );
        CHECK ( (new Mult(new Mult(new Num(7),new Num(6)),new Num(6)))->has_variable() == false );
    }
    
    SECTION("Test subst"){
        CHECK( (new Mult(new Num(5), new Num(7)) )->subst("x", new Var("y"))->equals(new Mult(new Num(5), new Num(7))) );
        CHECK( (new Mult(new Var("x"), new Num(7)))->subst("x", new Var("y"))->equals(new Mult(new Var("y"), new Num(7))) );
        CHECK( (new Mult(new Var("x"), new Num(7)))->subst("x", new Num(5))->equals(new Mult(new Num(5), new Num(7))) );
        CHECK( (new Mult(new Num(7), new Var("x")))->subst("x", new Var("y"))->equals(new Mult(new Num(7),new Var("y"))) );
        CHECK( (new Mult(new Num(7), new Var("x")))->subst("x", new Num(5))->equals(new Mult(new Num(7),new Num(5))) );

    }
}

TEST_CASE("TEST VAR EXPRESSION"){
    SECTION("Test equals"){
        CHECK( (new Var("x"))->equals(new Var("x")) == true );
        CHECK( (new Var("x"))->equals(new Var("y")) == false );
        CHECK( (new Var("1"))->equals(new Num(1)) == false );
        CHECK( (new Var("x"))->equals(new Add(new Num(1), new Num(0))) == false );
        CHECK( (new Var("x"))->equals(new Mult(new Num(1), new Num(0))) == false );
    }
    
    SECTION("Test interp"){
        CHECK_THROWS_WITH( (new Var("x"))->interp(), "interp call invalid on Var type");
        
        //throws when nested
        CHECK_THROWS_WITH( (new Mult(new Var("x"), new Num(1)))->interp(), "interp call invalid on Var type");
        CHECK_THROWS_WITH( (new Mult(new Mult(new Num(7),new Var("x")),new Num(6)))->interp(), "interp call invalid on Var type");
        CHECK_THROWS_WITH( (new Add(new Num(5), new Mult(new Num(6), new Var("x")) ))->interp(), "interp call invalid on Var type");
        
        //try special char
        CHECK_THROWS_WITH( (new Var("\n"))->interp(), "interp call invalid on Var type");
        
        //try capital
        CHECK_THROWS_WITH( (new Var("X"))->interp(), "interp call invalid on Var type");
    }
    
    SECTION("test subt"){
        CHECK( (new Var("x"))->subst("x", new Num(7))->equals(new Num(7)) );
        CHECK( (new Var("x"))->subst("y", new Num(7))->equals(new Var("x")) );
        CHECK( (new Var("x"))->subst("x", new Var("y"))->equals(new Var("y")) );
        CHECK( (new Var("x"))->subst("x", new Add( new Num(7), new Num(5) ))->equals(new Add(new Num(7), new Num(5))) );
        CHECK( (new Var("x"))->subst("x", new Mult( new Var("7"), new Num(5) ))->equals(new Mult(new Var("7"), new Num(5))) );
        
    }
    
    SECTION("has variable"){
        CHECK( (new Var("x"))->has_variable() == true);
        CHECK( (new Var("y"))->has_variable() == true);
        CHECK( (new Var("\n"))->has_variable() == true);
        CHECK( (new Var("try a long string"))->has_variable() == true);
        CHECK( (new Var("Y"))->has_variable() == true);
    }
    
}
