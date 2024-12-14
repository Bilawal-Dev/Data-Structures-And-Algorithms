#include<iostream>
using namespace std;

class Queue{
    private:
        int array[5];
        int front;
        int rear;
        int nElements;
    public:
        Queue(){
            front = 0;
            rear = -1;
            nElements = 0;
        }

        void enQueue(int num){
            if(nElements < 5){
                if(rear == 4){
                    rear = -1;
                }

                array[++rear] = num;
                nElements++;
            }
            else{
                cout<<"\nQueue Overflow\n";
            }
        }

        int deQueue(){
            if(nElements > 0){
                if(front == 5){
                    front = 0;
                }

                nElements--;
                return array[front++];
            }
            else{
                cout<<"\nQueue Underflow\n";
                return -1;
            }
        }

        void peek(){
            if(nElements > 0){
                cout<<"\nFirst Element : "<<array[front]<<endl;
                cout<<"\nRear Element : "<<array[rear]<<endl;
            }
            else{
                cout<<"\nQueue Is Empty\n";
            }
        }

        void display(){
            int index = front;

            for(int i = 0 ; i < nElements ; i++){
                if(index == 5){
                    index = 0;
                }
                cout<<array[index++]<<" | ";
            }
        }
};

int front = 0;
int rear = -1;
int nElements = 0;

void enQueue(int queue[], int size, int num){
    if(nElements < size){
        if(rear == size - 1){
            rear = -1;
        }
        nElements++;
        cout<<"\nPushing "<<num<<" To Queue"<<endl;
        queue[++rear] = num;
    }
    else{
        cout<<"\nError! The Queue Is Full"<<endl;
    }
}

int deQueue(int queue[], int size){
    if(nElements > 0){
        if(front == size){
            front = 0;
        }
        nElements--;
        cout<<"\nPopping "<<queue[front]<<" From Queue"<<endl;
        return queue[front++];
    }
    else{
        cout<<"\nError! The Queue Is Empty"<<endl;
        return -1;
    }
}

void peek(int queue[], int size){
    if(nElements > 0){
        cout<<"\nThe Front of The Queue Is As : "<<queue[front]<<endl;
    }
    else{
        cout<<"\nError! Can't Peek, The Queue Is Empty"<<endl;
    }
}

int main(){
    int size;
    cout<<"Enter The Size Of Queue : ";
    cin>>size;

    int *Queue = new int[size];

    enQueue(Queue, size, 10);
    enQueue(Queue, size, 20);
    peek(Queue, size);
    enQueue(Queue, size, 30);
    peek(Queue, size);
    deQueue(Queue, size);
    deQueue(Queue, size);
    peek(Queue, size);
    deQueue(Queue, size);
    deQueue(Queue, size);
    peek(Queue, size);
}