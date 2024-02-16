#include <stdio.h>

// Function to take input for coefficients of a polynomial
void inputPolynomial(int poly[], int degree) {
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

// Function to compute the sum of polynomials
void addPolynomials(int poly1[], int poly2[], int n1, int n2, int result[]) {
    int maxDegree = (n1 > n2) ? n1 : n2;

    // Initialize the result array
    for (int i = 0; i <= maxDegree; i++) {
        result[i] = 0;
    }

    // Add the coefficients of the polynomials
    for (int i = 0; i <= n1; i++) {
        result[i] += poly1[i];
    }

    for (int i = 0; i <= n2; i++) {
        result[i] += poly2[i];
    }
}

// Function to compute the product of polynomials
void multiplyPolynomials(int poly1[], int poly2[], int n1, int n2, int result[]) {
    int maxDegree = n1 + n2;

    // Initialize the result array
    for (int i = 0; i <= maxDegree; i++) {
        result[i] = 0;
    }

    // Multiply the coefficients of the polynomials
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
}

// Function to display a polynomial
void displayPolynomial(int poly[], int degree) {
    for (int i = 0; i <= degree; i++) {
        printf("%dx^%d", poly[i], i);

        if (i < degree) {
            printf(" + ");
        }
    }
}

int main() {
    int maxDegree1, maxDegree2;

    printf("Enter the maximum degree of the first polynomial: ");
    scanf("%d", &maxDegree1);

    printf("Enter the maximum degree of the second polynomial: ");
    scanf("%d", &maxDegree2);

    int poly1[maxDegree1 + 1];
    int poly2[maxDegree2 + 1];
    int sumResult[(maxDegree1 > maxDegree2 ? maxDegree1 : maxDegree2) + 1];
    int productResult[maxDegree1 + maxDegree2 + 1];

    // Input coefficients for the first polynomial
    printf("Enter coefficients for the first polynomial:\n");
    inputPolynomial(poly1, maxDegree1);

    // Input coefficients for the second polynomial
    printf("Enter coefficients for the second polynomial:\n");
    inputPolynomial(poly2, maxDegree2);

    // Compute the sum of polynomials
    addPolynomials(poly1, poly2, maxDegree1, maxDegree2, sumResult);

    // Display the sum
    printf("\nSum of the polynomials: ");
    displayPolynomial(sumResult, (maxDegree1 > maxDegree2 ? maxDegree1 : maxDegree2));
    printf("\n");

    // Compute the product of polynomials
    multiplyPolynomials(poly1, poly2, maxDegree1, maxDegree2, productResult);

    // Display the product
    printf("\nProduct of the polynomials: ");
    displayPolynomial(productResult, maxDegree1 + maxDegree2);
    printf("\n");

    return 0;
}
