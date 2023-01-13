#include "Reefcn_def.h"

int main() {

	std::cout<<"THIS IS A TUTORIAL AND DECLARATION TO OUR NEWTON SOLVER:"<<std::endl;
	std::cout<<"due to our capability, we dont provide an user given string"<<std::endl;
	std::cout<<"GUI where you can give your desired functions"<<std::endl;
	std::cout<<"We provide this script that you need to create the function in c++ code!"<<std::endl;
	std::cout<<"IF: you havent learnt any C++ syntax, its ok, please follow the paradigm!"<<std::endl;
	std::cout<<"#########################################################################"<<std::endl;
	std::cout<<"# Equation* pure_x = new X();                                           #"<<std::endl;
	std::cout<<"# Equation* x_sqr = new Power (2, pure_x);                              #"<<std::endl;
	std::cout<<"# Equation* e_function = new e_exp(pure_x);                             #"<<std::endl;
	std::cout<<"# Equation* sum_fun = new Sum(x_sqr, e_function);                       #"<<std::endl;
	std::cout<<"# Now you have successfuly defined a function f(x)=x^2+e^x              #"<<std::endl;
	std::cout<<"# you can throw this sum_fun passed as argument into our Newton Solver  #"<<std::endl;
	std::cout<<"#########################################################################"<<std::endl;

	// Equation* pure_x = new polynomial({-15,1});
	Equation* pure_x = new Sum(new Constant(-15),new X());
	Equation* x_sqr = new Power(3, pure_x); 
	Equation* e_function = new e_exp(pure_x);  
	Equation* sum_fun = new Sum(x_sqr, e_function); 


	
	double x0;
	std::cout<<"give the initial guess of x0: "<<std::endl;
	std::cin>>x0;
	double max_iter = 200;
	std::cout<<"give max iteration number: "<<std::endl;
	std::cin>>max_iter;
	double toler = 1e-8;
	std::cout<<"give tolerance: "<<std::endl;
	std::cin>>toler;
	
	double minval = newton_solver(sum_fun,x0,toler,max_iter);
	std::cout<<"founded value of x: "<<minval<<std::endl;


}



