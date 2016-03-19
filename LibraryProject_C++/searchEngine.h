#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include<string>
#include<vector>
#include<iostream>
#include "Book.h"
#include "Periodic.h"
#include "Video.h"
#include "Film.h"
#include "Media.h"


using namespace std;

class searchEngine{

	public:
		searchEngine();
		~searchEngine();

		void fileProcessing();
		vector<Media*> searchByCallno(const string& call_no) const;
		vector<Media*> searchByTitle(const string& title) const;
		vector<Media*> searchBySubject(const string& subject) const;
		vector<Media*> searchOther(const string& other) const;

	private:
		vector<Media*> cardCatalog;  //Vector to hold data from text files.

};

#endif
