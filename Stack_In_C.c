#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack{
    int top;  //Stores the "index" of the variable at the top.
    int size; //Stores the max size of the stack
    int *arr; //Points to the first element of the array that we will declare
};

int isFull(struct stack *our_stack){ //Returns 1 if stack is full else returns 0
    if(our_stack->top >= our_stack->size - 1){
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *our_stack){ //Returns 1 if stack is empty else returns 0
    if(our_stack->top <= -1){
        return 1;
    }
    return 0;
}

void push(int data,struct stack *our_stack){
    if(isFull(our_stack)){
        printf("Nahi Jagah Hai");
        return;
    }
    our_stack->top++;                   //Incrementing top as to move the "top pointer"
    our_stack->arr[our_stack->top]=data;//Editing the array during runtime as we are using call by reference
}

void show(struct stack* our_stack){
    int temp=our_stack->top;
    while(temp>=0){
        printf(" %d ",our_stack->arr[temp]);
        temp--;
    }
}

int main(){
    struct stack* s1=(struct stack*)malloc(sizeof(struct stack)); //Creating the instance of the stack
    s1->top=-1; //Since no element is present the value is -1
    s1->size=5; //We give any size we want it to reserve in Stack Memory
    s1->arr=(int*)malloc(s1->size * sizeof(int)); //Creating the dynamic array using malloc
    
    push(100,s1);
    push(101,s1);
    push(102,s1);
    push(103,s1);
    push(104,s1);

    show(s1);

    return 0;
}
