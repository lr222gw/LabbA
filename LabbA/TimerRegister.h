//Lowe Raivio
#ifndef TIMBER_REGISTER_H
#define TIMBER_REGISTER_H

#include <string>
#include "Timber.h"

using namespace std;

class TimberRegister{
private:
	int capacity;
	int TimbersInArr;
	Timber ** timberArr;
	void expandTimberArr();

public:

	void editTimber(Timber timber);

	void getTimber(string dimension, Timber &timberToGet)const;

	float amountOfCash()const;

	void saveFile(string fileName)const;

	void loadFile(string fileName);

	bool exists(Timber toCheck)const;

	void add(Timber toAdd);

	TimberRegister();
	TimberRegister(int capacity);
	~TimberRegister(); 

	void getTimberStringArr(string *arr, float min = -1)const; // "-1" betyder skit i att jämföra...

	void removeTimber(string dimension);

	int getTimbersAmount()const;

	
	//TimberRegister &operator=(const TimberRegister & other); //Tilldelnignskonstruktor
	void operator=(const TimberRegister & other); //Tilldelnignskonstruktor


	string TimberToString()const;//Ska gå igenom alla i TimbersArr och sedan lägga dem i en StringArray som ska returneras?

	TimberRegister(const TimberRegister& copy);



};



#endif // !TIMBER_REGISTER_H
