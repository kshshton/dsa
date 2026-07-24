#include "stack.h"

int main() {
    push(10);                  // [10]
    push(20);                  // [10, 20]
    push(30);                  // [10, 20, 30]
    display();
    pop();                     // [10, 20]
    printf("%d\n", peek());    // 20
    display();
    pop();                     // [10]
    pop();                     // []
    pop();                     // Stack underflow!

    return 0;
}
