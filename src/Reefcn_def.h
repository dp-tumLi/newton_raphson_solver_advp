#ifndef REEFCN_D_H
#define REEFCN_D_H
#include "../include/Reefcn.h"




polynomial::polynomial(std::vector<double> coeff) : coeff_(coeff) {}

double polynomial::Evaluate(double x) const {
  double result = 0.0;
  for (size_t i = 0; i < coeff_.size(); i++) {
    result += coeff_[i] * std::pow(x, i);
  }
  // std::cout <<"poly val = "<<result<<std::endl;
  return result;
}

Equation* polynomial::Differentiate() const {
  std::vector<double> new_coefficients(coeff_.size() - 1);
  for (size_t i = 1; i < coeff_.size(); i++) {
    new_coefficients[i - 1] = coeff_[i] * i;
  }
  return new polynomial(new_coefficients);
}


// Variant of polynomial which pass the varible x as functions
c_polynomial:: c_polynomial(std::vector<double> coeff, std::function<double(double)> func) 
    : coeff_(coeff), func_(func) {};

double c_polynomial::Evaluate(double x) const{
    double result = 0.0;
    for (size_t i = 0; i < coeff_.size(); i++) {
      result += coeff_[i] * std::pow(x, i);
    }
    return result * func_(x);
}

// not used at all
Equation* c_polynomial::Differentiate() const{
      std::vector<double> new_coefficients(coeff_.size() - 1);
    for (size_t i = 1; i < coeff_.size(); i++) {
      new_coefficients[i - 1] = coeff_[i] * i;
    }
    return new c_polynomial(new_coefficients, func_);
}




Sinus::Sinus(Equation* equation) : equation_(equation) {};

double Sinus::Evaluate(double x) const {
  return std::sin(equation_->Evaluate(x));
}

Equation* Sinus:: Differentiate() const {
  return new Product(new Cosinus(equation_), equation_->Differentiate());
}

Sinus::~Sinus(){
  delete equation_;
}



Cosinus::Cosinus(Equation* equation) : equation_(equation) {};

double Cosinus::Evaluate(double x) const{
  return std::cos(equation_->Evaluate(x));
}

Equation* Cosinus::Differentiate() const{
  return new Product(new Constant(-1.0), new Product(new Sinus(equation_), equation_->Differentiate()));
}


Tangent::Tangent(Equation* equation) : equation_(equation) {};

double Tangent::Evaluate(double x) const{
  return std::tan(equation_->Evaluate(x));
}

Equation* Tangent::Differentiate() const{
  return new Product(new Secant(equation_), new Product(new Secant(equation_), equation_-> Differentiate()));
}


Secant::Secant(Equation* equation) : equation_(equation) {};

double Secant::Evaluate(double x) const{
  return (1 / std::cos(equation_->Evaluate(x)));
}

Equation* Secant::Differentiate() const{
  return new Product(new Secant(equation_), new Product(new Tangent(equation_), equation_-> Differentiate()));
}


Cosecant::Cosecant(Equation* equation) : equation_(equation) {};

double Cosecant::Evaluate(double x) const{
  return (1 / std::sin(equation_->Evaluate(x)));
}

Equation* Cosecant::Differentiate() const{
  return new Product(new Constant(-1.0), new Product(new Cosecant(equation_), new Product(new Cotangent(equation_), equation_-> Differentiate())));
}
 

Cotangent::Cotangent(Equation* equation): equation_(equation) {};

double Cotangent::Evaluate(double x) const{
  return (std::cos(equation_->Evaluate(x)) / std::sin(equation_->Evaluate(x)));
}

Equation* Cotangent::Differentiate() const{
  return new Product(new Constant(-1.0), new Product(new Cosecant(equation_), new Product(new Cosecant(equation_), equation_-> Differentiate())));
}


Product::Product(Equation* left, Equation* right) : left_(left), right_(right){};

double Product::Evaluate(double x) const{
  // std::cout<<"Product is: "<<left_->Evaluate(x) * right_->Evaluate(x)<<std::endl;
  return left_->Evaluate(x) * right_->Evaluate(x);
}

Equation* Product::Differentiate() const{
  return new Sum (new Product(left_->Differentiate(), right_),
  new Product(left_, right_->Differentiate()));
};


Sum::Sum(Equation* left, Equation* right) : left_(left), right_(right) {};

double Sum::Evaluate(double x)const{
  return left_->Evaluate(x) + right_->Evaluate(x);
}

Equation* Sum::Differentiate() const{
  return new Sum(left_->Differentiate(), right_->Differentiate());
}



Constant::Constant(double xvalue_): value_(xvalue_){};

double Constant::Evaluate(double x) const{
  return value_;
}

Equation* Constant::Differentiate() const{
  return new Constant(0.0);
}



Power::Power(double n, Equation* base): n_(n), base_(base){};

double Power::Evaluate(double x) const{
  return std::pow(base_->Evaluate(x), n_);
}

Equation* Power::Differentiate() const{
  return new Product(new Product(new Constant(n_), new Power(n_ -1, base_)), base_->Differentiate());
}

X::X(){};
double X::Evaluate(double x) const{
  return x;
}

Equation* X::Differentiate() const{
  return new Constant(1.0);
}

e_exp::e_exp(Equation* exp_fun): exp_fun_(exp_fun){};

double e_exp::Evaluate(double x) const{
  // std::cout<<" Eval: "<<std::exp(exp_fun_->Evaluate(x))<<std::endl;
  return std::exp(exp_fun_->Evaluate(x));
}

Equation* e_exp::Differentiate() const{
  return new Product(new e_exp(exp_fun_), exp_fun_->Differentiate());
}



Log::Log(double base_num, Equation* func): base_num_(base_num), func_(func){};

double Log::Evaluate(double x) const{
  return std::log(func_->Evaluate(x))/std::log(base_num_);
}

Equation* Log::Differentiate() const{
  return new Product (new Product(new Power(-1, func_),new Constant(1.0/std::log(base_num_))), func_->Differentiate());
}



// Newton-Raphson solver for equations of the form f(x) = 0
double NewtonsMethod(Equation* f, double x0, double epsilon, int max_iter) {
  double x = x0;
  int curr_iter = 0;
  while (true) {
    double fx = f->Evaluate(x);
    if (std::abs(fx) < epsilon && curr_iter <max_iter) {
      // Solution found
      return x;
    }
    Equation* df = f->Differentiate();
    double dfx = df->Evaluate(x);
    x = x - fx / dfx;
    curr_iter ++;
    delete df;
  }
}

double newton_solver(Equation* f, double x0, double epsilon, int max_iter){
	double x_n = x0;
	double x_n_1 ;
	bool solution_found = false;
	int curr_count = 1;
	while(!solution_found){
		auto f_val = f->Evaluate(x_n);
		auto jac = f->Differentiate()->Evaluate(x_n);
		x_n_1 = x_n - f_val/jac;

		std::cout<<"curr_iteration: "<<curr_count<<" x: "<<x_n_1<<" f(x): "<<f_val<<std::endl;

		if (abs(x_n_1-x_n) < epsilon){
			solution_found = true;
      std::cout<<"Solution has converged!"<<std::endl;
		}
		if (curr_count>max_iter){
			solution_found = true;
      std::cout<<"Solution can not converge!"<<std::endl;
		}
		x_n = x_n_1;
		curr_count ++;
	}
  
	return x_n_1;

}


std::vector<std::string> tokenize(const std::string& input) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}


Equation* parse_string(const std::string& input) {
    std::vector<std::string> tokens = tokenize(input);
    std::stack<Equation*> stack;
    for (const auto& token : tokens) {
        if (token == "x") {
            stack.push(new X());
        } else if (token == "sin") {
            stack.push(new Sinus(stack.top()));
            stack.pop();
        } else if (token == "cos") {
            stack.push(new Cosinus(stack.top()));
            stack.pop();
        } else if (token == "+") {
            Equation* right = stack.top();
            stack.pop();
            Equation* left = stack.top();
            stack.pop();
            stack.push(new Sum(left, right));
        } else if (token == "*") {
            Equation* right = stack.top();
            stack.pop();
            Equation* left = stack.top();
            stack.pop();
            stack.push(new Product(left, right));
        } 
        // else if (token == "^") {
        //     Equation* exponent = stack.top();
        //     stack.pop();
        //     Equation* base = stack.top();
        //     stack.pop();
        //     stack.push(new Power(exponent, base));
        // } 
        else if (token == "e_exp") {
            stack.push(new e_exp(stack.top()));
            stack.pop();
        }
        // } else if (token == "log") {
        //     stack.push(new Log(stack.top()));
        //     stack.pop();
        // } 
        else {
            // check if the token is a number 
            double value = std::stod(token);
            stack.push(new Constant(value));
        }
    }
    return stack.top();
}

#endif


// Equation* get_user_fun(){

//   size_t func_num;
//   std::cin>>func_num;
//   std::vector<double> coeff;
//   int a_n;
//   Equation* func;
//   Equation* func1;
//   switch (func_num)
//   {
//   case 1:
//     func = new X();
//     break;

//   case 2:
//     while (std::cin>>a_n){
//       if (!std::cin){
//         if(std::cin.fail()){
//           std::cout<<"error"<<std::endl;
//         }
//         else if (std::cin.eof()){
//           break;
//         }
//       }
//       else{
//         coeff.push_back(a_n);
//       }
//     }

//     func = new polynomial(coeff);
//     break;

//   default:
//     func = new X();
//     break;
//   }
//   return func;

//   std::vector<size_t> base_func_num;
//   for (const auto& num: base_func_num){
    
//     switch (num:)
//     {
//     case /* constant-expression */:
//       /* code */
//       break;
    
//     default:
//       break;
//     }
//   }

  
// }





