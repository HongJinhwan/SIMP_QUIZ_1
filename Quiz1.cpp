#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double random_range(double min, double max);
bool circle(double x, double y);





void main() {
	srand((unsigned int)time(NULL));
	double num_point = 5000;

	FILE *fp = fopen("output.txt", "w");


	for (int i = 1; i <= num_point; i++) {
		double ran_x = random_range(0, 1);
		double ran_y = random_range(0, 1);
		if (circle(ran_x, ran_y)) {
			fprintf(fp, "%f,%f\n", ran_x, ran_y);
		}
	}

	fclose(fp);
}





double random_range(double min, double max) {
	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min)*temp;
	return temp;
}












bool circle(double x, double y) {
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;
	double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;

	if (f > 0)
		return false;
	else
		return true;
}

