
// equation.h
#ifndef EQUATION_H
#define EQUATION_H
#include <vector>
#include <cstddef>
#include <math.h>
#include <iostream>
#include <functional>
#include <bits/stdc++.h>

class Equation {
 public:
  virtual double Evaluate(double x) const = 0;
  virtual Equation* Differentiate() const = 0;
  virtual ~Equation() {}
};


#endif  // EQUATION_H
