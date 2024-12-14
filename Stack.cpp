#include<iostream>
using namespace std;

class Stack{
    private:
        int array[10];
        int top;
    public:
        Stack(){
            top = -1;
        }

        void push(int num){
            if(top < 9){
                array[++top] = num;
            }
            else{
                cout<<"\nStack Overflow\n";
            }
        }

        int pop(){
            if(top > -1){
                return array[top--];
            }
            else{
                cout<<"\nStack Underflow\n";
                return -1;
            }
        }

        void displayStack(){
            for(int i = top ; i >= 0 ; i++){
                cout<<array[i]<<" | ";
            }
        }

};

int top = -1;

void push(int stack[], int size, int num){
    if(top < size - 1 ){
        top++;
        cout<<"\nPushing "<<num<<" To Stack"<<endl;
        stack[top] = num;
    }
    else{
        cout<<"\nError: Stack Overflow!"<<endl;
    }
}

int pop(int stack[], int size){
    if(top > -1){
        cout<<"\nPopping "<<stack[top]<<" From Stack"<<endl;
        return stack[top--];
    }
    else{
        cout<<"\nError: Stack Underflow!"<<endl;
    }
}

void peek(int stack[], int size){
    if(top > -1){
        cout<<"\nThe Top of The Stack Is As : "<<stack[top]<<endl;
    }
    else{
        cout<<"\nThe Stack Is Empty!"<<endl;
    }
}

void displayStack(int stack[], int size){
    if(top > -1){
        cout<<"\nThe Stack Elements Are As : "<<endl;
        for(int i = top ; i > -1 ; i--){
            cout<<stack[i]<<"  ";
        }
        cout<<endl;
    }
    else{
        cout<<"\nNo Items In The Stack To Display"<<endl;
    }
}

int main(){
    int size;
    cout<<"Enter The Size Of Stack : ";
    cin>>size;

    int *Stack = new int[size];

    // Demonstration of stack operations
    push(Stack, size, 10);
    push(Stack, size, 20);
    push(Stack, size, 30);
    displayStack(Stack, size);

    pop(Stack, size);
    displayStack(Stack, size);

    peek(Stack, size);

    // Free the allocated memory
    delete[] Stack;
}