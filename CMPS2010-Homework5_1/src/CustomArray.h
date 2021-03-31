////////////////////////////////////////////////////////////////////////////////
// CMPS 2010
// Professor Toothman
// Jonathan Doolittle
// 12/5/2019
//
// Homework 5 (CustomArray.h)
////////////////////////////////////////////////////////////////////////////////


#pragma once

#import <iostream>

template <typename T>

class CustomArray {
private:
	unsigned int capacity_max, capacity_current;
	T * data = nullptr;
	T blank;

	void init() {
		capacity_current = 0;
		data = new T[capacity_max];
		blank = data[0];
	}

public:
	CustomArray() {
		capacity_max = 10;
		init();
	}

	CustomArray(int capacity) {
		capacity_max = capacity;
		init();
	}

	CustomArray(const CustomArray & copy) {
		capacity_max = copy.capacity_max;
		init();
		for(int i = 0; i <= capacity_max; i++) data[i] = copy.data[i];
	}

	~CustomArray() {
		delete [] data;
	}

	void resize(unsigned int capacity) {
		T * _data = new T[capacity];
		for(unsigned int i = 0; i <= capacity_current; i++) {
			_data[i] = data[i];
		}
		capacity_max = capacity;
		delete [] data;
		data = _data;
	}

	void add(T val) {
		if(capacity_current == capacity_max) resize(capacity_max * 2);
		data[capacity_current++] = val;
	}

    T & operator[](unsigned int i) {
        if (i >= 0 && i < capacity_max) {
        	if(capacity_current < i) capacity_current = i;
            return data[i];
        }
        return blank;
    }

};
