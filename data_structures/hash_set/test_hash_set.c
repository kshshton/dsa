#include "hash_set.h"

int main() {
    HashSet *set = createSet(5);
    add(set, 2);
    add(set, 4);
    add(set, 4);
    add(set, 5);
    add(set, 6);
    add(set, 6);
    
    display(set);
    
    contains(set, 3) ? puts("Yes") : puts("No");
    contains(set, 4) ? puts("Yes") : puts("No");

    return 0;
}
