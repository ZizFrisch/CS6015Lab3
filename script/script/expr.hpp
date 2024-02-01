//
//  expr.hpp
//  HW1
//
//  Created by Elisabeth Frischknecht on 1/18/24.
//

#pragma once
#include "catch.h"
#ifndef expr_hpp
#define expr_hpp

#include <stdio.h>

class Expr {
public:
    // = 0 means each subclass must override
    virtual bool equals(Expr *e) = 0;
    virtual int interp() = 0;
    virtual bool has_variable() = 0;
    virtual Expr* subst(std::string variable, Expr* e) = 0;
};

class Num : public Expr{
private:
    int val;
    
public:
    //constructor
    Num(int val);
    
    virtual bool equals(Expr *e);
    virtual int interp();
    virtual bool has_variable();
    virtual Expr* subst(std::string variable, Expr* e);

};

class Add: public Expr {
private:
    Expr *lhs;
    Expr *rhs;
    
    
public:
    //constructor
    Add(Expr *lhs, Expr *rhs);
    
    virtual bool equals(Expr *e);
    virtual int interp();
    virtual bool has_variable();
    virtual Expr* subst(std::string variable, Expr* e);
};

class Mult : public Expr {
private:
    Expr *lhs;
    Expr *rhs;
    
public:
    //constructor
    Mult(Expr *lhs, Expr *rhs);
    
    virtual bool equals(Expr *e);
    virtual int interp();
    virtual bool has_variable();
    virtual Expr* subst(std::string variable, Expr* e);
};


class Var : public Expr {
private:
    std::string val;
    
public:
    //constructor
    Var(std::string val);
    
    virtual bool equals(Expr *e);
    virtual int interp();
    virtual bool has_variable();
    virtual Expr* subst(std::string variable, Expr* e);
    
};

#endif /* expr_hpp */
