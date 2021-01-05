/* name: hussein saleh
 * class: second
 * department: computer
 */
#include <iostream>
#include <bits/stdc++.h>
#include <string>
// the combound that uses std that not need to repeat std:: again in cin or cout
using namespace std;
// data structure type that can have many concepts and access specifiers
class contact{
//its can be accessed just in the class
	private:
		string name, family, phone, address, email;
// can be accessed for everyone in program
	public:
// make pointer
		contact *next;
		contact(){
		};
		contact(string name, string family, string phone, string address, string email){
			this -> name = name ; this -> phone = phone; this -> family = family ; this -> address = address ; this -> email = email ; next = NULL;
		}
		string getName(){
			return name;
		}
// storage private variable in a public and when make call its accessed because public
		string getPhone(){
			return phone;
		}
		string getFamily(){
			return family;
		}
		string getAddress(){
			return address;
		}
		string getEmail(){
			return email;
		}
		void setContact(string name, string family, string phone, string address, string email){
			this -> name = name ; this -> family = family; this -> phone = phone ; this -> address = address ; this -> email = email;
		}
// this is how to show contacts in program window
		void getContact(){
			cout << "<-  " << name << "   Ꙭ   " << family << "   Ꙭ   " << phone << "   Ꙭ   " << address << "   Ꙭ   " << email << "  ->" << endl;
		}
};
class contactsList{
// the class that shows for us the list of contacts
	private:
		contact *head;
		contact *last;
		int size;
	public:
// functions with what it can hold within are here public
		contactsList();
		void addBegin(string, string, string, string, string);
		void showContacts();
		void deleteContact(string);
		contact* findContact(string);
		contact* find(string);
	};
contact* f;
contactsList::contactsList(){
// the defined member belongs to the class
	head = NULL ; last = NULL; size = 0;
}
void contactsList::addBegin(string name, string family, string phone, string address, string email){
// function that adds new contacts
	contact* new_contact = new contact(name , family , phone , address , email);
	if (last == NULL || head == NULL){
		head = new_contact;
		last = new_contact;
	}
	else {
		new_contact -> next = head;
		head = new_contact;
	}
	size++;
}
contact* contactsList::find(string serachQuery ){
// function that search and locate contacts
	contact* n = NULL;
	for( n = head ; n != NULL ; n = n->next)
		if (n -> getName() == serachQuery || n -> getFamily() == serachQuery || ( n -> getName() + " " + n -> getFamily() ) == serachQuery) {
			return n;
		}
	return n;
}
contact* contactsList::findContact(string serachQuery){
	contact* f = find(serachQuery);
	if (f == NULL){
		cout << "\nEmpty" << endl;
	}
	else {
		cout << "\n\n------------------------------------" << endl;
		f -> getContact();
		cout << "-----------------------------------" << endl;
	}
	return f;
}
void contactsList::deleteContact(string serachQuery){
// function that delete contact using search and locate function also
	if( head->getName() == serachQuery || head->getFamily() == serachQuery || ( head->getName() + " " + head->getFamily() ) == serachQuery )  {
		contact* temp = head->next;
		delete head;
		head = temp;
		size--;
		return;
	}
// delete destroys pointers and makes them disappear
	contact* temp = head;
	if( temp->next == NULL ){
		 cout << "\nEmpty";
		 return;
	}
	while(temp -> next -> getName() != serachQuery && temp -> next -> getFamily() != serachQuery && ( head -> getName() + " " + head -> getFamily() ) != serachQuery && temp != NULL ){ 
		temp = temp -> next;
		if ( temp -> next == NULL ) {
			 cout << "\nEmpty";
			 return;
		};
	}
	if(temp != NULL){
	contact* temp2 = temp -> next;
	temp -> next = temp2 -> next;
	delete temp2;
	if( last -> getName() == serachQuery || last -> getFamily() == serachQuery || ( last->getName() + " " + last->getFamily() ) == serachQuery ) {
		last = temp;
	}
	size--;
	}
}
void contactsList::showContacts(){
// the function that display all contacts added before
	cout << "\n" << endl;
	if (last == NULL || head == NULL){
		cout<<"empty\n\n";
	}
	int l = 1;
// this is the code how contacts are displayed
	for (contact* n = head ; n != NULL ; n = n -> next) {
		cout << " (" << l << ") "; l++;
		n -> getContact();
		cout << "\n\n" << endl;
	}
};
int main(){
	int n;
// definitions
	string name, family, phone, address, email, locate;
	contactsList a;
// hold class in a as pointer
hussein:
//this is my name used as loop
	cout<<"\n(1) add contact"<<endl;
	cout<<"(2) remove contact"<<endl;
	cout<<"(3) show contacts"<<endl;
//this is askings about what you want
	cout<<"(4) search"<<endl;
	cout<<"(5) exit"<<endl;
// that loop continues forever
	while(true){
		cout<<"\nYor choice: ";
		cin>>n;
		switch(n){
//switch execetes only when user chooses the right case
			case 1:
				cout << "\nName: ";
				cin >> name;
				cout << "Family: ";
				cin >> family;
				cout << "Phone: ";
				cin >> phone;
				cout << "Address: ";
				cin >> address;
				cout << "Email: ";
				cin >> email;
				a.addBegin(name,family,phone,address,email);
				goto hussein;
			case 2:
				cout << "\nContact to delete by name and family: ";
				cin >> locate;
				a.deleteContact(locate);
				break;
			case 3:
				a.showContacts();
				goto hussein;
			case 4:
				cout << "\nSearch Contact by name and family: ";
				cin >> locate;
				f = a.findContact(locate);
				break;
			case 5:
				exit(1);
			default:
				break;
		}
	}
//program is end here
	return 0;
}
