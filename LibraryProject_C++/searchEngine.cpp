/*
searchEngine.cpp
*/


#include "searchEngine.h"
#include<fstream>
#include<sstream>


searchEngine::searchEngine(){

	fileProcessing();   //Begin file processing
}

/*
   Destructor frees memoy allocated to the cardCatalog vector
 */
searchEngine::~searchEngine(){
	vector<Media*>::iterator it;
	for (it = cardCatalog.begin() ; it != cardCatalog.end(); ++it)
	{
		delete *it;
	}    
}

/*
   fileProcessing function is called when an object of searchEngine
   class is created. This function processes all text files and passes
   data to the vector
 */
void searchEngine::fileProcessing(){

	string line;
	ifstream readbook("book.txt");
	ifstream readperiodic("periodic.txt");
	ifstream readvideo("video.txt");
	ifstream readfilm("film.txt");

	string l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12;
	if(readbook.is_open()){
		while (!getline(readbook, line).eof())
		{
			stringstream tempRead(line);
			getline(tempRead,l1,'|');
			getline(tempRead,l2,'|');
			getline(tempRead,l3,'|');
			getline(tempRead,l4,'|');
			getline(tempRead,l5,'|');
			getline(tempRead,l6,'|');
			getline(tempRead,l7,'|');
			getline(tempRead,l8,'|');
			getline(tempRead,l9,'|');
			getline(tempRead,l10);
			//create Media object for book class and
			//add data to cardCatalog vector
			Media *book = new Book(l1,l2,l3,l4,l5,l6,l7,l8,l9,l10);
			cardCatalog.push_back(book);

		}
		readbook.close();
	}

	if(readperiodic.is_open()){
		while (!getline(readperiodic, line).eof())
		{
			stringstream tempRead(line);
			getline(tempRead,l1,'|');
			getline(tempRead,l2,'|');
			getline(tempRead,l3,'|');
			getline(tempRead,l4,'|');
			getline(tempRead,l5,'|');
			getline(tempRead,l6,'|');
			getline(tempRead,l7,'|');
			getline(tempRead,l8,'|');
			getline(tempRead,l9,'|');
			getline(tempRead,l10,'|');
			getline(tempRead,l11,'|');
			getline(tempRead,l12);
			//create Media object for Periodic class and
			//add data to cardCatalog vector

			Media *periodic = new Periodic(l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12);
			cardCatalog.push_back(periodic);

		}
		readperiodic.close();
	}

	if(readvideo.is_open()){
		while (!getline(readvideo, line).eof())
		{
			stringstream tempRead(line);
			getline(tempRead,l1,'|');
			getline(tempRead,l2,'|');
			getline(tempRead,l3,'|');
			getline(tempRead,l4,'|');
			getline(tempRead,l5,'|');
			getline(tempRead,l6,'|');
			getline(tempRead,l7,'|');
			getline(tempRead,l8);
			//create Media object for Video class and
			//add data to cardCatalog vector

			Media *video = new Video(l1,l2,l3,l4,l5,l6,l7,l8);
			cardCatalog.push_back(video);

		}
		readvideo.close();
	}

	if(readfilm.is_open()){
		while (!getline(readfilm, line).eof())
		{
			stringstream tempRead(line);
			getline(tempRead,l1,'|');
			getline(tempRead,l2,'|');
			getline(tempRead,l3,'|');
			getline(tempRead,l4,'|');
			getline(tempRead,l5,'|');
			getline(tempRead,l6);

			//create Media object for Film class and
			//add data to cardCatalog vector

			Media *film = new Film(l1,l2,l3,l4,l5,l6);
			cardCatalog.push_back(film);

		}
		readfilm.close();
	}
}


/*
   searchByCallno function compares each field in a vector with input string
   by calling compare_Callno function in Media class and returns the result to main()
Input: constant string with reference
output: result vector
 */
vector<Media*> searchEngine::searchByCallno(const string& call_no) const
{
	bool result;
	vector<Media*> resultVector;
	resultVector.clear();
	for(size_t i=0 ; i<cardCatalog.size();i++){              //size_t : To avoide signed/unsigned mismatch
		result = cardCatalog[i]->compare_Callno(call_no);

		if(result){
			resultVector.push_back(cardCatalog[i]);
		}
	}

	return resultVector;
}

/*
   searchByTitle function compares each field in a vector with input string
   by calling compare_Title function in Media class and returns the result to main()
Input: constant string with reference
output: result vector
 */

vector<Media*> searchEngine::searchByTitle(const string& title) const
{
	bool result;
	vector<Media*> resultVector;
	resultVector.clear();
	for(size_t i=0; i<cardCatalog.size(); i++){
		result = cardCatalog[i]->compare_Title(title);

		if(result){
			resultVector.push_back(cardCatalog[i]);
		}
	}
	
	return resultVector;
}

/*
   searchBySubject function compares each field in a vector with input string
   by calling compare_Subject function in Media class and returns the result to main()
Input: constant string with reference
output: result vector
 */

vector<Media*> searchEngine::searchBySubject(const string& subject) const
{
	bool result;
	vector<Media*> resultVector;
	resultVector.clear();
	for(size_t i=0; i<cardCatalog.size(); i++){
		result = cardCatalog[i]->compare_Subject(subject);

		if(result){
			resultVector.push_back(cardCatalog[i]);
		}
	}
	
	return resultVector;
}

/*
   searchByOther function compares each field in a vector with input string
   by calling compare_other function in Media class and returns the result to main()
Input: constant string with reference
output: result vector
 */

vector<Media*> searchEngine::searchOther(const string& other) const
{

	bool result;
	vector<Media*> resultVector;
	for(size_t i=0; i<cardCatalog.size(); i++){
		result = cardCatalog[i]->compare_other(other);

		if(result){
			resultVector.push_back(cardCatalog[i]);
		}
	}
	
	return resultVector;
}
