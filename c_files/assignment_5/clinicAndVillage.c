#include <stdio.h>
#include <math.h>

int canAllocate(double population[], int n, int k, double maxLoad) {
    int clinics = 0;

    for (int i = 0; i < n; i++) {
        clinics += (int)ceil(population[i] / maxLoad);

        if (clinics > k)
            return 0;
    }

    return 1;
}

double minimumMaximumLoad(double population[], int n, int k) {
    double low = 0.0;
    double high = 0.0;

   
    for (int i = 0; i < n; i++) {
        if (population[i] > high)
            high = population[i];
    }

   
    for (int i = 0; i < 100; i++) {
        double mid = (low + high) / 2.0;

        if (canAllocate(population, n, k, mid))
            high = mid;
        else
            low = mid;
    }

    return high;
}

int main() {
    int n = 3;
    int k = 5;

    double population[] = {200, 20, 50};

    double answer = minimumMaximumLoad(population, n, k);

    printf("%.2f\n", answer);

    return 0;
}
