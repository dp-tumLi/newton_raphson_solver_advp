#ifndef REEFCN_H
#define REEFCN_H
#include "../include/Equation.h"

// passed by two different Equation instances
class Product : public Equation {
 public:
  Product(Equation* left, Equation* right);

  double Evaluate(double x) const override;

  Equation* Differentiate() const override;

 private:
  Equation* left_;
  Equation* right_;
};

// passed by two different Equation instances
class Sum : public Equation {
 public:
  // Constructor that takes two pointers to Equation objects as input
  Sum(Equation* left, Equation* right);

  // Evaluate the value of the sum at a given point x
  double Evaluate(double x) const override;

  // Calculate the derivative of the sum
  Equation* Differentiate() const override;

 private:
  Equation* left_;  // Pointer to the left operand of the sum
  Equation* right_;  // Pointer to the right operand of the sum
};


// passed by one reel double value
class Constant : public Equation {
 public:
  Constant(double value);

  double Evaluate(double x) const;

  Equation* Differentiate() const;

 private:
  double value_;
};

// passed by {1,1,1} liked double array into vector container
class polynomial: public Equation{
  private:
    std::vector<double>coeff_;
  public:
    polynomial(std::vector<double> coeff);
    
    double Evaluate(double x) const override;

    Equation* Differentiate() const override; 

};

// passed by 1 Equation instance
class Sinus : public Equation {
 public:
  Sinus(Equation* equation);

  double Evaluate(double x) const override ;

  Equation* Differentiate() const override ;

  ~Sinus();

 private:
  Equation* equation_;
};


// passed by 1 Equation instance
class Cosinus: public Equation{
  public: 
    Cosinus(Equation* equation) ;

    double Evaluate(double x) const override;

    Equation* Differentiate() const override ;
    
  private:
    Equation* equation_;
};

// passed by 1 Equation instance
class Tangent: public Equation{
  public:
    Tangent(Equation* equation);

    double Evaluate(double x) const override;

    Equation* Differentiate() const override;

  private:
    Equation* equation_;
};

// passed by 1 Equation instance
class Secant: public Equation{
  public:
    Secant(Equation* equation);

    double Evaluate(double x) const override;

    Equation* Differentiate() const override;

  private:
    Equation* equation_;
};

// passed by 1 Equation instance
class Cosecant: public Equation{
  public:
    Cosecant(Equation* equation);

    double Evaluate(double x) const override;

    Equation* Differentiate() const override;

  private:
    Equation* equation_;
};

// passed by 1 Equation instance
class Cotangent: public Equation{
  public:
    Cotangent(Equation* equation);

    double Evaluate(double x) const override;

    Equation* Differentiate() const override;

  private:
    Equation* equation_;
};


// passed by n: the exponent, Equation instance as base function
class Power : public Equation {
 public:
  Power(double n, Equation* base) ;

  double Evaluate(double x) const override;

  Equation* Differentiate() const override;

  ~Power() {
    delete base_;
  }

 private:
  double n_;
  Equation* base_;
};

// not used
class c_polynomial : public Equation {
 public:
  c_polynomial(std::vector<double> coeff, std::function<double(double)> func);

  double Evaluate(double x) const override;

  Equation* Differentiate() const override;

 private:
  std::vector<double> coeff_;
  std::function<double(double)> func_;
};

// passed by 1 Equation instance

class e_exp : public Equation{
  public:
    e_exp(Equation* exp_fun);

    double Evaluate(double x) const override;

    Equation* Differentiate() const override;

  private:
    Equation* exp_fun_;
};

// passed by 1 Equation instance

class Log : public Equation{
  public:
    Log(double base_num, Equation* func);
    
    double Evaluate(double x) const override;

    Equation* Differentiate() const override;

  private:
    double base_num_;
    Equation* func_;
};
// passed by only reel value x
class X : public Equation{
  public:
    X();
    
    double Evaluate(double x) const override;

    Equation* Differentiate() const override;
};
#endif  