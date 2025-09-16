#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear==SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (front==-1) front=0;
        rear++;
        queue[rear]=value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
    if (front==-1 || front>rear) {
        printf("Queue is empty\n");
    } else {
        printf("Dequeued: %d\n",queue[front]);
        front++;
    }
}

void peek() {
    if (front=+-1 || front>rear) {
        printf("Queue is empty\n");
    } else {
        printf("Front item: %d\n",queue[front]);
    }
}

void display() {
    if (front==-1 || front>rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contents: ");
        for (int i=front;i<=rear;i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void isEmpty() {
    if (front==-1||front>rear)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}

void isFull() {
    if (rear==SIZE-1)
        printf("Queue is full\n");
    else
        printf("Queue is not full\n");
}

int main() {
    int choice,value;

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Empty\n");
        printf("6. Check if Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d",&value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            isEmpty();
            break;
        case 6:
            isFull();
            break;
        case 7:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice!=7);

    return 0;
}
/*--- Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Exit
Enter your choice: 1
Enter value to enqueue: 34
Enqueued: 34

--- Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Exit
Enter your choice:*/