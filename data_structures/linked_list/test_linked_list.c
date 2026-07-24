#include "linked_list.h"

int main() {
    Node *head = NULL;
    
    insert_up(&head, 10);
    insert_up(&head, 11);
    insert_up(&head, 12);
    insert_up(&head, 13);
    insert_up(&head, 14);
    insert_up(&head, 15);

    contains(head, 10) ? puts("Yes") : puts("No");
    contains(head, 9) ? puts("Yes") : puts("No");
    
    insert_back(&head, 16);
    insert_back(&head, 17);

    remove_value(&head, 12);
    remove_value(&head, 15);
    remove_value(&head, 17);

    display(head);

    return 0;
}
