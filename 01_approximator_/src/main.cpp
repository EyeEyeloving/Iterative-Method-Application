#include <iostream>
#include <math.h>

#define ppi 3.1415926535354

// Newton - Raphson method
class NewtonRaphson
{
	
private:
	const double tol = 1e-6;// int is wrong

public:
	double findApprox(double x_n) {
		/*一开始要确定x_n的初始搜索点*/
		/*定义函数F(x)*/
		double F_xn = x_n * std::cos(x_n) - std::sin(x_n);
		/*定义函数一阶导F1_xn*/
		double F1_xn = -x_n * std::sin(x_n);

		double x_next = x_n - F_xn / F1_xn;
		if (std::abs(x_next - x_n) < tol) {
			return x_next;
		}
		else {
			return findApprox(x_next);
		}
	}
};


void main() {
	NewtonRaphson* setNewtonRaphson = new NewtonRaphson();
	double init_x = 5 * ppi / 2;
	double target_x = setNewtonRaphson->findApprox(init_x);
	std::cout << target_x << std::endl;
	std::cout << target_x * std::cos(target_x) - std::sin(target_x) << std::endl;
}