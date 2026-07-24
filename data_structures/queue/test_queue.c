#include "queue.h"

int main() {
    enqueue(10);            // [10]         {front: 0;  rear: 0}
    enqueue(20);            // [10, 20]     {front: 0;  rear: 1}
    enqueue(30);            // [10, 20, 30] {front: 0;  rear: 2}
    display();           
    dequeue();              // [20, 30]     {front: 1;  rear: 2}
    dequeue();              // [30]         {front: 2;  rear: 2}
    dequeue();              // []           {front: -1; rear: -1}
    enqueue(10);            // [10]         {front: 0;  rear: 0}
    enqueue(20);            // [10, 20]     {front: 0;  rear: 1}
    enqueue(20);            // [10, 20]     {front: 0;  rear: 2}
    enqueue(20);            // [10, 20]     {front: 0;  rear: 3}
    enqueue(20);            // [10, 20]     {front: 0;  rear: 4}
    enqueue(50);            // [10, 20]     Error: Queue is full!
    enqueue(50);            // [10, 20]     Error: Queue is full!
    display();
    printf("%d\n", peek()); // 10

    return 0;
}
