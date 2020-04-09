#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linked_list {

   int element;                                             //Create the struct with elements
   struct linked_list * next;                             //Pointer for llinking the addresses

};
typedef struct linked_list list;                        //Definition

void printList(list * head)                            //Method to print the linked list
{
    list * temp = head;                                    //Make a reference to the head of the linked list

    while (temp != 0) {                                    //Print the list until the address reaches null, that is the end
      printf("%d ", temp -> element);
      temp = temp -> next;
   }
}

void insert(list * head, int k, int e)              //Insert function. Takes the head address, key and value as parameters
  {

    list * temp1;                                           //Create a new node
   temp1 = (list * ) malloc(sizeof(list));

   temp1 -> element = e;                             //Re assign the value and address of the newly created node
   temp1 -> next = 0;

    if (k == 1) {                                           //Check if the position is 1 only;
      temp1 -> next = head;                         //If the position is "1", then the reference need not change
      head = temp1;
      return;
   }

   //When the position is not 1.
   //Check till n-1;
   //We run till n-2 because the head next is one ahead of now

    list * temp2 = head;                                //Reference starting from head
    int f;
    for (f = 0; f < k - 2; f++) {
      temp2 = temp2 -> next;
    }

   //After this, temp2 points to n-1 position
   temp1 -> next = temp2 -> next;
   temp2 -> next = temp1;

   printList(head);
}

void del(list * head, int d)
{

   list * temp1 = head;                                      //Reference pointer to head

   int f = 0;
   for (f = 0; f < d - 2; f++) {                            //Go till the position
      temp1 = temp1 -> next;

   }

   //Initialize it to the next variable
   list * temp2 = temp1 -> next;                        //Use dereferencing
   temp1 -> next = temp2 -> next;                   //(d+1)th node

   free(temp2);                                                //Free the location restored


   printList(head);
}

void rotate(list*head, int x)
{
    list *temp = head;                                              //Initialize with the head pointer
    int c = 1;                                                          //Run a loop till rotating twice
    while(c<2 && temp!=0){                                   //Check for the looping condition and end of transversal
        temp = temp->next;
        c++;
        }

    if(temp ==0){                                                       //This is when, there is one node only
        return;
    }

    //If the above is not true, then it will be pointing to the 2nd node for the first time
    list * temp2 = temp;                                            //Initialize another variable

    //Re-iterate
    while(temp->next != 0){                                     //Check till this is the last elements
        temp = temp->next;
    }

    //Change the final values as well
    temp->next = head;

    //First element now is the first element of the rotated list
    head = temp2->next;

    //Assigning the last value
    temp2->next = 0;

    printList(head);

}

int main()
{

   list * head = 0;                                             //For the head/starting pointer
   list * p, * now;                                              //To create nodes and current ptr
   int n, m;                                                      //Input values
   int k, e, d;                                                   //Key (Insert), element(insert), Key(delete)
   int size = 0;                                                //Number of total elements

   while (1) {

      p = (list * ) malloc(sizeof(list));                   //Create a node using dynamic memory allocation
      printf("Enter a number: ");
      scanf("%d", & (p -> element));                    //Store the element entered in the element part of the struct
      size++;
      p -> next = 0;                                            //Mark this node as the end

      if (head == 0) {                                           //Check if this is the first element of the list
         head = p;
         now = p;
      } else {
         now -> next = p;
         now = p;
      }

      printf("Press 1 to continue or 0 to exit: ");     //To check weather the user wants to input any number
      scanf("%d", & n);
      if (n == 0) {
         break;
      }
   }

   //Print statements
   printf("\nTo print the elements of the list, press 3");
   printf("\nTo insert an element in the list, press 1");
   printf("\nTo rotate the list by 2 units in anticlockwise direction, press 4");
   printf("\nTo delete an element in the list, press 2\n");

   scanf("%d", & m);


    //Working conditions
   if (m == 1) {
      printf("\nAdd the position where you want to insert an element : ");
      scanf("%d", & k);
      if (k < 1 || k > size + 1) {                                  //Validity of position
         printf("Invalid position entered");
         return 0;
      }
      printf("\nEnter the integer you wish to insert: ");
      scanf("%d", & e);
      insert(head, k, e);
   } else if (m == 2) {
      printf("Add the position of the element you want to delete: ");
      scanf("%d", & d);

      if (d < 1 || d > size + 1) {                                  //Validity of position
         printf("Invalid position entered");
         return 0;
      }
      del(head, d);
   } else if (m == 3) {
      printList(head);
   }else if(m==4){
   rotate(head, 2);


   }
   else{
    printf("Invalid input");
    return 0;
   }

   return 0;
}
