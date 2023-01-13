clc
clear all
close all
syms x
x0 = 5;
tol = 1e-7;
iter = 100;
min_val = newtonmethod(x0,tol,iter);

function[root]=newtonmethod(xo,tol,n)
xn=xo;
% fun=@(x) (-15+x)^3+x^5;
% fp = @(x) 3*(-15+x)^2+5*x^4;

fun=@(x) (-15+x)^3+exp(-15+x);
fp = @(x) 3*(-15+x)^2+exp(-15+x);
for k=1:n
    xn1=xn-fun(xn)/fp(xn);
    dx=abs(xn1-xn);
    xn=xn1;
    if dx<tol
        disp("newton method has converged")
        root=xn;
        return 
    else
        root = 0;
    end

end
disp("no convergence after n interactions")
end

