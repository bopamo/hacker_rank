/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    
    int count = 0;
    
    Node *ptr = head;
    
    while( ptr->next ) {
        ptr = ptr->next;
        count++;
    }
    
    // to get the actual location, subtract positionFromTail from "count"
    int position = count - positionFromTail;
    
    // reset ptr to head of list
    ptr = head;
    
    // reset "count"
    count = 0;
    
    while( (ptr->next) && (count < position) ) {
        ptr = ptr->next;
        count++;
    }
    
    return ptr->data;
}
