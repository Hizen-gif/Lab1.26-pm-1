#include <stdio.h>
#include <math.h>

double func1(float x, float y) {
	double a, b;
	a = ((exp(2) * pow(cos(y), 3)) / log(fabs(x / y)));
	b = sin(pow(pow(x, 5) / (y + 1), 0.25) - (1 / pow(x, 1 / 3)));
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	double x, y, U, Usumm = 0;
	printf("x             y              U \n");
	for (x = 1.0; x <= 3.0; x += 1.3)
	{
		for (y = 2.0; y <= 4.0; y += 1.5)
		{
			U = func1(x, y);
			printf("x=%f    y=%f     U=%f\n", x, y, U);
			Usumm += U;
		}
	}
	printf("общая сумма U: %f \n", Usumm);
	return 0;
}