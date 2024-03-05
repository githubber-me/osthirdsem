#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 10, x = 0;

// Function to produce an item and add it to the buffer
void producer() 
{
    --mutex;
    ++full;
    --empty;
    x++; // Item produced
    printf("\nProducer produces item %d", x);
    ++mutex; // Increase mutex value by 1
}

// Function to consume an item and remove it from buffer
void consumer() 
{
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item %d", x);
    x--;
    ++mutex; // Increase mutex value by 1
}

int main() {
    int n, i;
    printf("\n1.For Producer\n2.For Consumer\n3.For Exit");

    for (i = 1; i > 0; i++) 
    {
        printf("\nEnter your choice:");
        scanf("%d", &n);

        // Switch Cases
        switch (n) 
        {
            case 1:
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("Buffer is full!");
                }
                break;
            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("Buffer is empty!");
                }
                break;
            case 3:
                exit(0);
                break;
        }
    }
}
