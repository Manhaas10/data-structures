struct Node* middle(Node* start, Node* last)
{
    if (start == NULL)
        return NULL;

    struct Node* slow = start;
    struct Node* fast = start->next;

    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

// Function for implementing the Binary
// Search on linked list
struct Node* binarySearch(Node* head, int value)
{
    struct Node* start = head;
    struct Node* last = NULL;

    do {
        // Find middle
        Node* mid = middle(start, last);

        // If middle is empty
        if (mid == NULL)
            return NULL;

        // If value is present at middle
        if (mid->data == value)
            return mid;

        // If value is more than mid
        else if (mid->data < value)
            start = mid->next;

        // If the value is less than mid.
        else
            last = mid;

    } while (last == NULL || last != start);

    // value not present
    return NULL;
}