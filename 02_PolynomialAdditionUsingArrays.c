#include <stdio.h>

struct poly{
    int coeff;
    int expo;
};

int insertPoly(struct poly p[10]){
    int n;
    printf("Enter the no of terms in the polynomial : ");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Enter the coeff : ");
        scanf("%d",&p[i].coeff);
        printf("Enter the expo : ");
        scanf("%d",&p[i].expo);
    }
    return n;
}

void displayPoly(struct poly p[10],int terms){
    for (int i=0;i<terms;i++){
        printf("%d x^%d ",p[i].coeff,p[i].expo);
        if (i<terms-1){
             printf("+ ");
        }
    }
}


int addPoly(struct poly p1[10],struct poly p2[10],struct poly p3[10],int terms1,int terms2){
    int i = 0,j =0,k = 0;
    while(i<terms1&&j<terms2){
        if (p1[i].expo > p2[i].expo){
           p3[k].coeff = p1[i].coeff;
           p3[k].expo = p1[i].expo;
           i++;k++;
        }else if(p2[j].expo > p1[i].expo){
            p3[k].coeff= p2[j].coeff;
            p3[k].expo= p2[j].expo;
            j++;k++;
        }else{
            if (p1[i].coeff+p2[j].coeff==0){
                i++;j++;
                continue;
            }
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].expo=p1[i].expo;
            i++;j++;k++;
        }
    }
    while (i<terms1){
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;k++;
    }
    while (j<terms2){
        p3[k].coeff= p2[j].coeff;
        p3[k].expo= p2[j].expo;
        j++;k++;
    }
    return k;
}

int main(){
    struct poly p1[10];
    struct poly p2[10];
    struct poly p3[10];
    int n1 = insertPoly(p1);
    int n2 = insertPoly(p2);
    displayPoly(p1,n1);
    printf("\n");
    displayPoly(p2,n2);
    int n3 = addPoly(p1,p2,p3,n1,n2);
    printf("\n");
    displayPoly(p3,n3);
}

// Include standard input-output library for console operations

// Define a structure 'poly' to represent polynomial terms, with coefficient and exponent fields

// Function to insert polynomial terms
// Step 1: Prompt the user for the number of terms in the polynomial
// Step 2: For each term, input the coefficient and exponent from the user
// Step 3: Return the total number of terms

// Function to display polynomial terms
// Step 1: Loop through each term in the polynomial
// Step 2: Print each term's coefficient, variable, and exponent in the format "coeff x^expo"
// Step 3: Print a plus sign between terms except for the last term

// Function to add two polynomials
// Step 1: Initialize three indices: i, j for traversing the input polynomials and k for the result polynomial
// Step 2: Loop through both polynomials as long as terms remain in each
//         - Compare the exponents of the current terms in both polynomials
//         - If p1's exponent is greater, add p1's term to the result and increment i and k
//         - If p2's exponent is greater, add p2's term to the result and increment j and k
//         - If exponents are equal, add the coefficients and, if non-zero, store in the result polynomial
//           then increment i, j, and k
// Step 3: If terms remain in p1 or p2, add remaining terms to the result polynomial
// Step 4: Return the total number of terms in the resulting polynomial

// Main function
// Step 1: Declare polynomial arrays for two input polynomials and one result polynomial
// Step 2: Use 'insertPoly' to input terms for the first and second polynomials
// Step 3: Display the input polynomials using 'displayPoly'
// Step 4: Add the polynomials using 'addPoly' and store the result
// Step 5: Display the resulting polynomial
