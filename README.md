# adv_newton_raphson_solver

## HOW TO START THE SOLVER:
- 1. This solver contains a main.cpp and test_unit.cpp which respectively contributes as newton solver and basic function unit test
- 2. To start the solver with polynomial function: 
      Find the instruction after excuting the main.exe or run main.cpp on display
      You need actually define you own functions as instances, we provide a widely defined complex function library, which contains
      x^n, sin(x), cos(x), tan(x), sec(x), cosec(x), cot(x), e^x, loga(x), product, sum, power
      All above these function where x stands can be passed by other function, which means complex functions
      also some basic functions: 
      x, polynomial, constant, which could only be passed by x value itself, they are not complex.

      Very pity is that we couldnt provide you a program that you can give an arbitrary string as functions and do the job as well,
      we have tried somethings but havent successed, maybe some 3rd party library could help...like intelligent sparse, regular expression
      etc..

      If you treat our library as a lib file, that would be very powerful like matlab also does, you could create your own c++ script like you do it in matlab m.file.

- 3. To test function: 
      We provide several cases for unit test to verify that our basic function works!

## Sprint 1
Implement a program for solving single variable polynomial equations. Define a function for differentiating the polynomial equation.
- The project contains a comprehensive README.md file explaining how to use it, including an example.
- The program can solve a single variable polynomial equation.
- The program will take guess solution, tolerance and maximum number of iterations from user.
- The solver prints or returns the root of the equation.
- The project contains at least one unit test which compares one case with its analytic solution for correctness.

## Sprint 2
Implement class equation to define original and differentiated equations. The program can handle complex polynomial, trigonometric, exponential and logarithmic functions. Use class hierarchies to define the different kinds of functions.
- The solver can handle complex functions of the form x^n*f(x), where n is any real number and f(x) is sin(x), cos(x), tan(x), sec(x), cosec(x), cot(x) e^x or log(x).
- The README.md file shall explain how to add new functionality to the program.
- The project contains unit tests for polynomial, trigonometric, exponential, and logarithmic functions.

## Sprint 3
In this sprint, the code performance will be evaluated and improved. Potential performance bottlenecks will be found (e.g. using a profiler such as gprof) and optimization options for the code will be implemented. This investigation will be based on topics covered in the lecture.
- A file performance.md presents observations from the performance analysis.
- The same file presents different optimization techniques applied, with the performance effects observed.
- The final code includes the most optimized version of our code.


```
cd existing_repo
git remote add origin https://gitlab.lrz.de/advprog2022/18/adv_newton_raphson_solver.git
git branch -M main
git push -uf origin main
```
