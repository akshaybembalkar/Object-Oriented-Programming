#pragma once
/*
Author: Akshay Bembalkar
*/

#include<iostream>
#include<deque>

using namespace std;

template <class T>

class TrackingDeque : public std::deque<T>
{
public:
	TrackingDeque();
	~TrackingDeque();
	void push_front(char val);
	void push_back(char val);
	bool empty();

private:
	int	max_size;

};

template<class T>
TrackingDeque<T>::TrackingDeque()
{
	max_size = 0;

}


template<class T>
TrackingDeque<T>::~TrackingDeque()
{
	cout << "Max Size: " << max_size << endl;
}

template<class T>
void TrackingDeque<T>::push_front(char val)
{
	deque<T>::push_front(val);
	if (max_size < deque<T>::size()) {
		max_size = deque<T>::size();
	}
}


template<class T>
void TrackingDeque<T>::push_back(char val)
{
	deque<T>::push_back(val);
	if (max_size < deque<T>::size()) {
		max_size = deque<T>::size();
	}
}

template<class T>
bool TrackingDeque<T>::empty()
{
	if (deque<T>::size() == 0) {
		return true;
	}
	else{
		return false;
	}
}