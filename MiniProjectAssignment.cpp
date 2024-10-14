#include <iostream>
using namespace std;

class Node 
{
  public:
    int data;
    Node *next;

    Node() 
	{
        data = 0;
        next = NULL;
    }

    Node(int data) 
	{
        this->data = data;
        this->next = NULL;
    }
};
//==========================================================================
class SinglyLinkedlist 
{
    Node *head;

  public:
    SinglyLinkedlist() 
	{
        head = NULL;
    }

 //==========================================================================  
    void insertAtHead(int data) 
	{
        Node *newNode = new Node(data);

        if (head == NULL) 
		{
            head = newNode;
            return;
        }

        newNode->next = this->head;
        this->head = newNode;
    }
//==========================================================================
    void Toprint() 
	{
        Node *temp = head;

        if (head == NULL) 
		{
            cout << "List empty" << endl;
            return;
        }

        while (temp != NULL) 
		{
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
//==========================================================================
    //Reverse the list
    void reverseList() 
    {
        Node *curr = head;
        Node *prev = nullptr;
        Node *next;

        while(curr != nullptr){
            next = curr -> next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
    }
//==========================================================================
    void deleteNode(int value)
    {
        if(head->data == value){
            Node* temp = head;
            head = temp->next;
            delete temp;
        }
        Node *current = head;
        Node *prev = NULL;

        while (current != NULL)
        {
            if (current->data == value)
            {
                prev->next = current->next;
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }
        // if(current == NULL){
        //     return;
        // }
        // prev->next = current->next;
        // delete current;
    }
//==========================================================================
    void findMiddle(){
        if(head == NULL){
            return;
        }

        Node *slow = head;
        Node *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "The middle element is: " << slow->data << endl;
    }
//==========================================================================
    bool hasCycle(){
        if(head == NULL){
            return false;
        }
        Node *slow = head;
        Node *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
//==========================================================================
    void createCycle(int pos){
        if (head == NULL){
            return;
        }
        Node *temp = head;
        Node *cycleNode = NULL;
        int count = 0;

        while(temp->next != NULL){
            if(count == pos){
                cycleNode = temp;}
            temp = temp->next;
            count++;
        }

        if(cycleNode != NULL){
            temp->next = cycleNode;
        }
    }
//==========================================================================
    bool seatInList(int seat)
    {
        if (head == NULL)
        {
            return false;
        }
        Node* current = head;
        while (current != NULL)
        {
            if (current->data == seat)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

//==========================================================================

int main() 
{

    SinglyLinkedlist bookingSystem;
    int option = 0;
    int seatNumber;

    while(option != 4){
        cout << "Event Ticket Booking System" << endl;
        cout << "   1. Book a Seat" << endl;
        cout << "   2. Cancel a Seat" << endl;
        cout << "   3. Show Available Seats" << endl;
        cout << "   4. Exit" << endl;
        cout << "Choose an option (1-4):" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter seat number to book" << endl;
            cin >> seatNumber;
            if (bookingSystem.seatInList(seatNumber))
            {
                cout << "Enter an available seat." << endl;
                break;
            }
            bookingSystem.insertAtHead(seatNumber);
            cout << "Seat " << seatNumber << " has been booked." << endl;
            //cout << "Explanation: The user chooses to book a seat and enters seat number " << seatNumber << ". The system adds this seat to the list." << endl;
            break;
        case 2:
            cout << "Enter seat number to cancel" << endl;
            cin >> seatNumber;
            if(bookingSystem.seatInList(seatNumber))
            {
                cout << "its in list" << endl;
                bookingSystem.deleteNode(seatNumber);
                cout << "Seat " << seatNumber << " has been cancelled." << endl;
            }
            else
            {
                cout << "Seat is not booked. Please enter a booked seat." << endl;
            }
            break;
        case 3:
            cout << "Available Seats: " << endl;
            bookingSystem.Toprint();
            cout << endl;
            break;
            //cout << "Explanation: The user chooses to view the available seats, and the system displays all the booked seats in the order they were added." << endl;
        case 4:
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option, please choose another option" << endl;
        }
    }
    return 0;
}
