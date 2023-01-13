#include "Reefcn_def.h"
#include <assert.h>

int main(){
    // This is the example you may used:
    std::cout<<"Here is the test unit for polynomial functions:"<<std::endl;
    std::cout<<"reference function f(x) = x^2 + x^3, f(x=2) = 12, f'(x=2) = 16"<<std::endl;
    double ref_poly_val = 12;
    double ref_poly_diff = 16;
    Equation* f_poly = new polynomial({0,0,1,1});
    auto f_poly_val = f_poly->Evaluate(2);
    auto f_poly_diff = f_poly->Differentiate()->Evaluate(2);
    try
    {
        if (abs(f_poly_val-ref_poly_val)>1e-5){
            throw "test failed for polynomial!";
        }
        else{
            std::cout<<"test passed for polynomial!"<<std::endl;
        }
    }
    catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
    }


    std::cout<<"Here is the test unit for exponent functions:"<<std::endl;
    std::cout<<"reference function f(x) = e^(x^2 + x), f(x=2) = 403.428793, f'(x=2) = 2017.143967"<<std::endl; 
    double ref_e_val = 403.428793;
    double ref_e_diff = 2017.143967;
    Equation* f_x_e = new polynomial({0,1,1});
    Equation* f_e = new e_exp(f_x_e);
    auto f_e_val = f_e->Evaluate(2);
    auto f_e_diff = f_e->Differentiate()->Evaluate(2);
    try
    {
        if (abs(f_e_val-ref_e_val)>1e-5){
            throw "test failed for exponent function!";
        }
        else{
            std::cout<<"test passed for exponent function!"<<std::endl;
        }
    }
    catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
    }


    std::cout<<"Here is the test unit for log functions:"<<std::endl;
    std::cout<<"reference function f(x) = log3(x^2 + x), f(x=2) = 1.630930, f'(x=2) = 0.915510"<<std::endl; 
    double ref_log_val = 1.630930;
    double ref_log_diff = 0.915510;
    Equation* f_x_log = new polynomial({0,1,1});
    Equation* f_log = new Log(3,f_x_log);
    auto f_log_val = f_log->Evaluate(2);
    auto f_log_diff = f_log->Differentiate()->Evaluate(2);
    try
    {
        if (abs(f_log_val-ref_log_val)>1e-5){
            throw "test failed for log function!";
        }
        else{
            std::cout<<"test passed for log function!"<<std::endl;
        }
    }
    catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
    }


    std::cout<<"Here is the test unit for sinus functions:"<<std::endl;
    std::cout<<"reference function f(x) = sin(x^2 + x), f(x=2) = -0.279415, f'(x=2) = 4.800852"<<std::endl; // All trigonometric functions are in radians
    double ref_sin_val = -0.279415;
    double ref_sin_diff = 4.800852;
    Equation* f_x_sin = new polynomial({0,1,1});
    Equation* f_sin = new Sinus(f_x_sin);
    auto f_sin_val = f_sin->Evaluate(2);
    auto f_sin_diff = f_sin->Differentiate()->Evaluate(2);
    try
    {
        if (abs(f_sin_val-ref_sin_val)>1e-5){
            throw "test failed for sinus function!";
        }
        else{
            std::cout<<"test passed for sinus function!"<<std::endl;
        }
    }
    catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
    }



    std::cout<<"Here is the test unit for Cosinus functions:"<<std::endl;
    std::cout<<"reference function f(x) = cos(x^2 + x), f(x=2) = 0.960170, f'(x=2) = 1.397077"<<std::endl; // All trigonometric functions are in radians
    double ref_cos_val = 0.960170;
    double ref_cos_diff = 1.397077;
    Equation* f_x_cos = new polynomial({0,1,1});
    Equation* f_cos = new Cosinus(f_x_cos);
    auto f_cos_val = f_cos->Evaluate(2);
    auto f_cos_diff = f_cos->Differentiate()->Evaluate(2);
    try
    {
        if (abs(f_cos_val-ref_cos_val)>1e-5){
            throw "test failed for cosinus function!";
        }
        else{
            std::cout<<"test passed for cosinus function!"<<std::endl;
        }
    }
    catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
    }


    std::cout<<"Here is the test unit for Tangent functions:"<<std::endl;
    std::cout<<"reference function f(x) = tan(x^2 + x), f(x=2) = -0.291006, f'(x=2) = 5.423423"<<std::endl; // All trigonometric functions are in radians
    double ref_tan_val = -0.291006;
    double ref_tan_diff = 5.423423;
    Equation* f_x_tan = new polynomial({0,1,1});
    Equation* f_tan = new Tangent(f_x_tan);
    auto f_tan_val = f_tan->Evaluate(2);
    auto f_tan_diff = f_tan->Differentiate()->Evaluate(2);
    try
    {
        if (abs(f_tan_val-ref_tan_val)>1e-5){
            throw "test failed for tangent function!";
        }
        else{
            std::cout<<"test passed for tangent function!"<<std::endl;
        }
    }
    catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
    }


    std::cout<<"Here is the test unit for Secant functions:"<<std::endl;
    std::cout<<"reference function f(x) = sec(x^2 + x), f(x=2) = 1.041482, f'(x=2) = -1.515388"<<std::endl; // All trigonometric functions are in radians
    double ref_sec_val = 1.041482;
    double ref_sec_diff = -1.515388;
    Equation* f_x_sec = new polynomial({0,1,1});
    Equation* f_sec = new Secant(f_x_sec);
    auto f_sec_val = f_sec->Evaluate(2);
    auto f_sec_diff = f_sec->Differentiate()->Evaluate(2);
    try
    {
        if (abs(f_sec_val-ref_sec_val)>1e-5){
            throw "test failed for secant function!";
        }
        else{
            std::cout<<"test passed for secant function!"<<std::endl;
        }
    }
    catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
    }


    std::cout<<"Here is the test unit for Cosecant functions:"<<std::endl;
    std::cout<<"reference function f(x) = cosec(x^2 + x), f(x=2) = -3.578901, f'(x=2) = -61.491856"<<std::endl; // All trigonometric functions are in radians
    double ref_cosec_val = -3.578901;
    double ref_cosec_diff = -61.491856;
    Equation* f_x_cosec = new polynomial({0,1,1});
    Equation* f_cosec = new Cosecant(f_x_cosec);
    auto f_cosec_val = f_cosec->Evaluate(2);
    auto f_cosec_diff = f_cosec->Differentiate()->Evaluate(2);
    try
    {
        if (abs(f_cosec_val-ref_cosec_val)>1e-5){
            throw "test failed for cosecant function!";
        }
        else{
            std::cout<<"test passed for cosecant function!"<<std::endl;
        }
    }
    catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
    }


    std::cout<<"Here is the test unit for Cotangent functions:"<<std::endl;
    std::cout<<"reference function f(x) = cot(x^2 + x), f(x=2) = -3.436354, f'(x=2) = -64.042655"<<std::endl; // All trigonometric functions are in radians
    double ref_cot_val = -3.436354;
    double ref_cot_diff = -64.042655;
    Equation* f_x_cot = new polynomial({0,1,1});
    Equation* f_cot = new Cotangent(f_x_cot);
    auto f_cot_val = f_cot->Evaluate(2);
    auto f_cot_diff = f_cot->Differentiate()->Evaluate(2);
    try
    {
        if (abs(f_cot_val-ref_cot_val)>1e-5){
            throw "test failed for cotangent function!";
        }
        else{
            std::cout<<"test passed for cotangent function!"<<std::endl;
        }
    }
    catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
    }


// Test for Power function
  Equation* sin123 = new Sinus(new polynomial({0,1}));
  Equation* x_sqr1 = new polynomial({0,1});
  Equation* pow = new Power(3,x_sqr1);
  auto pow_val = pow->Evaluate(2);
  auto pow_diff = pow->Differentiate()->Evaluate(2);
  std::cout <<"pow_val: "<<pow_val<<" pow_diff: "<<pow_diff<<std::endl;

// Test for X function
  Equation* xxx = new X();
  auto xxx_val = xxx->Evaluate(2);
  auto xxx_diff = xxx->Differentiate()->Evaluate(2);
  std::cout<<xxx_val<<xxx_diff<<std::endl;

  // Test for exp function:
  Equation* e_fun = new e_exp(x_sqr1);
  auto e_fun_val = e_fun->Evaluate(2);
  auto e_fun_diff = e_fun->Differentiate()->Evaluate(2);
  std::cout <<"e_val: "<<e_fun_val<<" e_diff: "<<e_fun_diff<<std::endl;


// Test for log function
  Equation* log_fun = new Log(2,x_sqr1);
  auto log_val = log_fun->Evaluate(2);
  auto log_diff = log_fun->Differentiate()->Evaluate(2);
  std::cout <<"log_val: "<<log_val<<" log_diff: "<<log_diff<<std::endl;


// Test for sin function
  Equation* sin_fun = new Sinus(x_sqr1);
  auto sin_val = sin_fun->Evaluate(2);
  auto sin_diff = sin_fun->Differentiate()->Evaluate(2);
  std::cout <<"sin_val: "<<sin_val<<" sin_diff: "<<sin_diff<<std::endl;


// Test for cos function
  Equation* cos_fun = new Cosinus(x_sqr1);
  auto cos_val = cos_fun->Evaluate(2);  
  auto cos_diff = cos_fun->Differentiate()->Evaluate(2);
  std::cout <<"cos_val: "<<cos_val<<" cos_diff: "<<cos_diff<<std::endl;


// Test for tan function
  Equation* tan_fun = new Tangent(x_sqr1);
  auto tan_val = tan_fun->Evaluate(2);  
  auto tan_diff = tan_fun->Differentiate()->Evaluate(2);
  std::cout <<"tan_val: "<<tan_val<<" tan_diff: "<<tan_diff<<std::endl;


// Test for sec function
  Equation* sec_fun = new Secant(x_sqr1);
  auto sec_val = sec_fun->Evaluate(2);  
  auto sec_diff = sec_fun->Differentiate()->Evaluate(2);
  std::cout <<"sec_val: "<<sec_val<<" sec_diff: "<<sec_diff<<std::endl;


// Test for cosec function
  Equation* cosec_fun = new Cosecant(x_sqr1);
  auto cosec_val = cosec_fun->Evaluate(2);  
  auto cosec_diff = cosec_fun->Differentiate()->Evaluate(2);
  std::cout <<"cosec_val: "<<cosec_val<<" cosec_diff: "<<cosec_diff<<std::endl;


// Test for cot function  
  Equation* cot_fun = new Cotangent(x_sqr1);
  auto cot_val = cot_fun->Evaluate(2);  
  auto cot_diff = cot_fun->Differentiate()->Evaluate(2);
  std::cout <<"cot_val: "<<cot_val<<" cot_diff: "<<cot_diff<<std::endl;
}
