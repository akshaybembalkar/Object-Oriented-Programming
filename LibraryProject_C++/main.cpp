#include<iostream>
#include<string>
#include "searchEngine.h"

using namespace std;

int main(){

	int choice;
	char select;
	searchEngine object;          //searchEngine object.
	vector<Media*> resultVector;  //Vector to hold search result
	vector<Media*>::const_iterator iter;
	string input_str;              //Input string

	do
	{
		cout<<"Selct your search type: ";
		cout<<"\n1.Search by Call number";
		cout<<"\n2.Search by Title";
		cout<<"\n3.Search by Subject";
		cout<<"\n4.Search Other";
		cout<<"\n5.Quit";

		cout<<"\nEnter your choice: ";
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"\nEnter Call Number you want to search : ";
				cin.ignore();
				getline(cin,input_str);

				resultVector = object.searchByCallno(input_str);

				for (size_t i = 0;i<resultVector.size(); ++i){
					resultVector[i]->display();
				}
				
				break;

			case 2:
				cout<<"\nEnter Title you want to search : ";
				cin.ignore();
				getline(cin,input_str);
				resultVector = object.searchByTitle(input_str);

				for (size_t i = 0;i<resultVector.size(); ++i){
					resultVector[i]->display();
				}
				
				break;

			case 3:
				cout<<"\nEnter Subject you want to search : ";
				cin.ignore();
				getline(cin,input_str);
				resultVector = object.searchBySubject(input_str);

				for (size_t i = 0;i<resultVector.size(); ++i){
					resultVector[i]->display();
				}
				
				break;

			case 4:
				cout<<"\nEnter other string you want to search : ";
				cin.ignore();
				getline(cin,input_str);
				resultVector = object.searchOther(input_str);

				for (size_t i = 0;i<resultVector.size(); ++i){
					resultVector[i]->display();
				}
				
				break;

			case 5:
				return 0;
				break;

			default:
				return 0;
				break;
		}
		cout<<"Do you want to continue your search (y/n) : ";
		cin>>select;
	}while(select=='y' || select=='Y');

	return 0;
}
