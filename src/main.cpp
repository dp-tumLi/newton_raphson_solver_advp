#include <iostream>
#include <math.h>

double coeff[100];

double eqn(int degree, double x){
// TODO: single variable of polynomial

	int count = degree;
	double fval = 0;
	while(count + 1){
		fval += coeff[count]*pow(x,count);
		count --;
	}
	return fval;
}

double jacobian(int degree, double x){
// TODO: single variable of poly jacobian eqn
	int count = degree;
	double f_jac = 0;
	while(count){
		f_jac += count * coeff[count]*pow(x,count-1);
		count --;
	}
	return f_jac;
}

double newton(double degree, int max_iter, auto x0, double toler){
	double x_n = x0;
	double x_n1 ;
	bool flag = true;
	int curr_count = 1;
	while(flag){
		auto f = eqn(degree, x_n);
		auto jac = jacobian(degree, x_n);
		x_n1 = x_n - f/jac;

		std::cout<<"curr_iteration: "<<curr_count<<" x: "<<x_n1<<" f(x): "<<f<<std::endl;

		if (abs(x_n1-x_n) < toler){
			flag = false;
		}
		if (curr_count>max_iter){
			flag = false;
		}
		x_n = x_n1;
		curr_count ++;
	}

	return x_n1;
}

double testfcn(double x0, int max_iter, double toler){


	double x_n = x0;
	double x_n1 ;
	bool flag = true;
	int curr_count = 1;
	while(flag){
		double fval = 1 + x_n + x_n*x_n+ x_n*x_n*x_n;
		double jac = 1 + 2*x_n + 3*x_n*x_n;
		x_n1 = x_n - fval/jac;
		std::cout<<"curr_iteration: "<<curr_count<<" x: "<<x_n1<<" f(x): "<<fval<<std::endl;

		if (abs(x_n1-x_n) < toler ){
			flag = false;
		}
		if (curr_count>max_iter){
			flag = false;
		}
		x_n = x_n1;
		curr_count ++;
	}
	return x_n1;
}

int main(int argc, char *argv[])
{
	std::cout<<"give degree of poly: "<<std::endl;
	int degree;
	std::cin>>degree;
	for(int i = 0; i<degree+1 ;i++){
		std::cout<<"a"<<i<<":"<<std::endl;
		std::cin>>coeff[i];
	}
	// double f = eqn(degree, 5);
	// double jac = jacobian(degree,5);
	// std::cout<<"eqn: "<<f<<std::endl;
	// std::cout<<"jac: "<<jac<<std::endl;

	double x0;
	std::cout<<"give the initial guess of x0: "<<std::endl;
	std::cin>>x0;
	double max_iter = 200;
	std::cout<<"give max iteration number: "<<std::endl;
	std::cin>>max_iter;
	double toler = 1e-8;
	std::cout<<"give tolerance: "<<std::endl;
	std::cin>>toler;

	double minval = newton(degree,max_iter,x0,toler);
	std::cout<<"founded value of x: "<<minval<<std::endl;

	double test_val = testfcn(x0,max_iter,toler);
	std::cout<<"founded value of x from test: "<<test_val<<std::endl;

}