//
//  expr.cpp
//  HW1
//
//  Created by Elisabeth Frischknecht on 1/18/24.
// This class holds the expression classes Num, Add, Mult, and Var to be used to represent mathematical expressions

#include "expr.hpp"


//NUM EXPRESSION CLASS
Num::Num(int val) {
    this->val = val;
}

bool Num::equals(Expr *e){
    Num *t = dynamic_cast<Num*>(e);
    if(t==NULL){
        return false;
    }
    else{
        return (this->val == t->val);
    }
}

int Num::interp(){
    return val;
}

bool Num::has_variable(){
    return false;
}

Expr* Num::subst(std::string variable, Expr* e){
    return this;
}


//ADD EXPRESSION CLASS
Add::Add(Expr *lhs, Expr *rhs){
    this -> lhs = lhs;
    this->rhs = rhs;
}

bool Add::equals(Expr *e){
    Add *t = dynamic_cast<Add*>(e);
    if(t == NULL){
        return false;
    }
    else{
        return (this->lhs->equals(t->lhs) && this->rhs->equals(t->rhs));
    }
}

int Add::interp(){
    int result = 0;
    
    result = this->lhs->interp() + this->rhs->interp();
    
    return result;
}

bool Add::has_variable(){
    return ( this->lhs->has_variable() || this->rhs->has_variable() );
}

Expr* Add::subst(std::string variable, Expr* e){
    return new Add(this->lhs->subst(variable, e), this->rhs->subst(variable, e) );
    
}

//MULT EXPRESSION CLASS
Mult::Mult(Expr *lhs, Expr *rhs){
    this->lhs = lhs;
    this->rhs = rhs;
}

bool Mult::equals(Expr *e){
    Mult *t = dynamic_cast<Mult*>(e);
    if(t==NULL){
        return false;
    }
    else{
        return (this->lhs->equals(t->lhs) && this->rhs->equals(t->rhs));
    }
}

int Mult::interp(){
    int result = 0;
    
    result = ( this->lhs->interp() ) * ( this->rhs->interp() );
    
    return result;
}

bool Mult::has_variable(){
    return ( this->lhs->has_variable() || this->rhs->has_variable() );
}

Expr* Mult::subst(std::string variable, Expr* e){
    return new Mult(this->lhs->subst(variable, e), this->rhs->subst(variable, e) );
}

//VARIABLE EXPRESSION CLASS

//constructor
Var::Var(std::string val){
    this->val = val;
}

//equals comparator

bool Var::equals(Expr *e){
    Var *t = dynamic_cast<Var*>(e);
    if(t==NULL){
        return false;
    }
    else{
        //comare returns 0 if the two strings are equal.
        return (this->val.compare(t->val)==0);
    }
}

int Var::interp(){
    throw std::runtime_error("interp call invalid on Var type");
}

bool Var::has_variable(){
    return true;
}

Expr* Var::subst(std::string variable, Expr* e){
    if(variable.compare(this->val)==0){
        return e;
    }
    return this;
}

