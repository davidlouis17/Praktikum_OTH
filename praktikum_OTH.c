#include <stdio.h>
#include <stdlib.h>

// Define the Stone structure
struct Stone {
  char* alphabet;
  struct Stone* link;
};

int main() {
  // Initialize Stone nodes
  struct Stone l1, l2, l3, l4, l5, l6, l7, l8, l9;

  l1.link = NULL;
  l1.alphabet = "F";

  l2.link = NULL;
  l2.alphabet = "M";

  // ... (similar initialization for other nodes)

  // Connect nodes to form a circular linked list
  l3.link = &l6; // A->T
  l6.link = &l9; // T->R
  // ... (similar connections for other nodes, as done previously)

  // Current node to iterate through the list
  struct Stone* current = &l1;

  // Loop to iterate and print characters
  do {
    printf("%s -> ", current->alphabet);
    current = current->link;
  } while (current != &l1); // Loop until we reach the starting node again

  printf("NULL\n"); // Print NULL at the end to indicate the circular nature

  return 0;
}
