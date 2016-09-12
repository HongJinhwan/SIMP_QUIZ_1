#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double random_range(double min, double max);
bool circle(double x, double y, double x_c, double y_c, double r);





void main() {
	srand((unsigned int)time(NULL));
	double num_point = 5000;

	FILE *fp = fopen("output.txt", "w");


	for (int i = 1; i <= num_point; i++) {
		double ran_x = random_range(0, 1);
		double ran_y = random_range(0, 1);
		if (circle(ran_x, ran_y, 0.5, 0.5, 0.5)) {
			fprintf(fp, "%f,%f\n", ran_x, ran_y);
		}
	}

	for (int i = 1; i <= num_point; i++) {
		double ran_x = random_range(2, 3);
		double ran_y = random_range(0, 1);
		if (circle(ran_x, ran_y, 2.5, 0.5, 0.5)) {
			fprintf(fp, "%f,%f\n", ran_x, ran_y);
		}
	}

	for (int i = 1; i <= num_point; i++) {
		double ran_x = random_range(0.5, 2.5);
		double ran_y = random_range(0.4, 0.6);
		fprintf(fp, "%f,%f\n", ran_x, ran_y);
	}

	fclose(fp);
}





double random_range(double min, double max) {
	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min)*temp;
	return temp;
}












bool circle(double x, double y, double x_c, double y_c, double r) {
	double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;

	if (f > 0)
		return false;
	else
		return true;
}

