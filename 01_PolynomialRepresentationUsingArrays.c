#include <stdio.h>

struct poly{
    int coeff;
    int expo;
};

int main(){
    int n;
    struct poly p[10];
    printf("Enter the no of terms in the polynomial : ");
    scanf("%d",&n);
    for (int i=0;i<n ; i++){
        printf("Enter the Coefficient of polynomial : ");
        scanf("%d",&p[i].coeff);
        printf("Enter the Exponent of polynomial : ");
        scanf("%d",&p[i].expo);
    }

    printf("Displaying the terms in 1st polynomial : ");
    for(int i=0;i<n;i++){
        printf("%d x^%d ",p[i].coeff,p[i].expo);
        if (i<n-1){
             printf("+ ");
        }
    }
}

// Define a structure for the polynomial terms with coefficient and exponent fields

// Main function begins
// Step 1: Prompt the user to enter the number of terms in the polynomial
// Step 2: For each term in the polynomial:
//         - Prompt the user to input the coefficient and store it
//         - Prompt the user to input the exponent and store it

// Step 3: Display the polynomial terms in a readable format:
//         - For each term, print the coefficient, the variable 'x', and the exponent
//         - Add a plus sign between terms, except after the last term

// End of program, ensure a clean display with newline formatting
