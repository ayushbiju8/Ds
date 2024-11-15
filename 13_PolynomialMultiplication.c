    #include <stdio.h>
    #include <stdlib.h>

    struct node{
        int coeff;
        int exp;
        struct node * next;
    };

    struct node * poly1=NULL;
    struct node * poly2=NULL;
    struct node * result=NULL;

    struct node * createNode(int coeff,int exp){
        struct node * newNode = (struct node *)malloc(sizeof(struct node));
        newNode->coeff=coeff;
        newNode->exp=exp;
        newNode->next=NULL;
        return newNode;
    }

    struct node * insertNode(struct node * poly,int coeff,int exp){
        struct node * newNode = createNode(coeff,exp);
        struct node * temp = poly;
        struct node * prev = NULL;
        while (temp!=NULL&&temp->exp>exp){
            prev=temp;
            temp=temp->next;
        }
        if (temp != NULL && temp->exp == exp){
            temp->coeff = temp->coeff+coeff;
        }else{
            if (prev==NULL){
                newNode->next = temp;
                poly = newNode;
            }else{
                newNode->next= temp;
                prev->next = newNode;
            }
        }
        return poly;
    }

    struct node * multiplication(){
        for (struct node *ptr1=poly1;ptr1!=NULL;ptr1=ptr1->next){
            for(struct node *ptr2=poly2;ptr2!=NULL;ptr2=ptr2->next){
                int coeff = ptr1->coeff * ptr2->coeff;
                int exp = ptr1->exp + ptr2->exp;
                result = insertNode(result,coeff,exp);
            }
        }
        return result;
    }

    void display(struct node * root){
        struct node * temp = root;
        while ( temp!= NULL){
            printf(" %dx^%d + ",temp->coeff,temp->exp);
            temp = temp->next;
        }
    }

    int main(){
        poly1=insertNode(poly1,2,3);
        poly1=insertNode(poly1,21,31);
        poly1=insertNode(poly1,21,1);
        display(poly1);
        poly2=insertNode(poly2,2,3);
        poly2=insertNode(poly2,21,31);
        poly2=insertNode(poly2,21,1);
        display(poly2);
        result = multiplication();
        display(result);
    }