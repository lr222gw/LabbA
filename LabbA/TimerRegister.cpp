//Lowe Raivio
#include "TimerRegister.h"
#include <fstream>

void TimberRegister::expandTimberArr()
{
	//OBS, kontrollera att DeepCopy har utf�rts...

	this->capacity *= 2;

	Timber **tempArr = new Timber*[this->capacity];

	for (int i = 0; i < this->TimbersInArr; i++) {
		tempArr[i] = this->timberArr[i];
	}

	delete[] this->timberArr;
	

	this->timberArr = tempArr;

	//delete[] tempArr;

	tempArr = nullptr;
}

//void TimberRegister::editTimber(string dimension, float newPrice, float newMeter)
void TimberRegister::editTimber(Timber timber) // string dimension, float newPrice, float newMeter
{
	for (int i = 0; i < this->getTimbersAmount(); i++) {

		if (*this->timberArr[i] == timber) {			
			this->timberArr[i]->setPrice(timber.getPricePerMeter());
			this->timberArr[i]->setMeter(timber.getMeter());
		}

		/*if (this->timberArr[i]->getDimension() == dimension) {
			this->timberArr[i]->setPrice(newPrice);
			this->timberArr[i]->setMeter(newMeter);
		}*/
	}
}

void TimberRegister::getTimber(string dimension, Timber &timberToGet)const
{
	
	for (int i = 0; i < this->getTimbersAmount(); i++) {
		if (this->timberArr[i]->getDimension() == dimension) {
			timberToGet = *this->timberArr[i];
		}
	}
}

float TimberRegister::amountOfCash()const
{
	float money = 0; 
	{
		for (int i = 0; i < this->TimbersInArr; i++) {
			money += this->timberArr[i]->getPrice();
		}
	}
	return money;
}

void TimberRegister::saveFile(string fileName)const
{

	ofstream newFile(fileName);
	if (newFile.is_open())
	{
		for (int i = 0; i < this->TimbersInArr; i++)
		{
			//newFile << endl << this->timberArr[i]->getPricePerMeter() << endl;
			newFile << endl;
			newFile << this->timberArr[i]->getWidth() << endl;
			newFile << this->timberArr[i]->getHeight() << endl;			
			newFile << this->timberArr[i]->getMeter() << endl;
			newFile << this->timberArr[i]->getPricePerMeter() << endl;
		}
	}

	newFile.close();
	
}

void TimberRegister::loadFile(string fileName)
{
	ifstream newFile(fileName);
	std::string width, height, meter, pricePerMeter, space;

	if (newFile.is_open())
	{
		while (getline(newFile, space))
		{
	
			getline(newFile, width);
			getline(newFile, height);
			getline(newFile, meter);
			getline(newFile, pricePerMeter);


			
			Timber myTimber(stof(width), stof(height),stof(meter), stof(pricePerMeter));
			
			this->add(myTimber);
		}
	}

	newFile.close();
}

bool TimberRegister::exists(Timber toCheck)const
{
	bool status = false;
	for (int i = 0; i < this->TimbersInArr; i++) {
		if (*this->timberArr[i] == toCheck) {
			status = true;
		}
	}
	return status;
}

void TimberRegister::add(Timber toAdd)
{	
	
	if (!this->exists(toAdd)) {
		if (this->capacity == this->TimbersInArr) {
			this->expandTimberArr();
		}

		Timber *timber = new Timber(toAdd);

		this->timberArr[this->TimbersInArr] = timber;
		this->TimbersInArr++;

		
	}
	
	
}

TimberRegister::TimberRegister()
{
	this->capacity = 5;
	this->timberArr = new Timber*[capacity];
}

TimberRegister::TimberRegister(int capacity)	
{
	this->capacity = capacity;
	this->timberArr = new Timber*[capacity];
	this->TimbersInArr = 0;
}

TimberRegister::~TimberRegister()
{
	

	for (int i = 0; i < this->TimbersInArr; i++) {

		//Denna "this->timberArr[i]" inneh�ller Korupterad data...
		delete this->timberArr[i];
	}
	
	delete[] this->timberArr;
}

//string * TimberRegister::getTimberStringArr(float min, string *arr)const
void TimberRegister::getTimberStringArr(string *arr, float min)const
{
	

	//string *arr;
	/*if (this->TimbersInArr == 0) {
		arr = new string[1];
	}
	else {
		arr = new string[this->TimbersInArr];
	}
	*/
	int counter = 0;
	for (int i = 0; i < this->TimbersInArr; i++) {
		if (min == -1) {
			 this->timberArr[i]->toString(arr[i]);
		}
		else {
			if (min >= this->timberArr[i]->getMeter()) {

				this->timberArr[i]->toString(arr[counter]);
				counter++;
				//arr[i] = this->timberArr[i]->toString();
			}
		}
		
	}

	/*if (this->TimbersInArr == 0) {
		arr[0] = "TimberRegister �r helt tom...\n";
	}*/

	//return arr;
}

void TimberRegister::removeTimber(string dimension)
{
	
	for (int i = 0; i < this->TimbersInArr; i++) {
		
		//Om jag ska anv�nda "==" s� m�ste jag ju j�mf�ra 2 Timber objekt...
		//D� m�ste jag ju skapa ett nytt... On�digt?
		//OBS, att jag fixade Exist funktionen som anv�nds av add()... (den anv�nder == operatorn f�r timber)
		if (this->timberArr[i]->getDimension() == dimension ) {

			delete this->timberArr[i];

			this->timberArr[i] = this->timberArr[this->TimbersInArr - 1];

			Timber *toAdd = new Timber();

			this->timberArr[this->TimbersInArr - 1] = toAdd;
			delete toAdd;

			this->TimbersInArr = this->TimbersInArr - 1;
		
		}
		
	}


}

int TimberRegister::getTimbersAmount()const
{
	//returnera din timbersArray
	return this->TimbersInArr;
}


//TimberRegister & TimberRegister::operator=(const TimberRegister &other)
TimberRegister& TimberRegister::operator=(const TimberRegister &other) 
{

				

	if (this != &other) { //Ingen "Sj�lvtilldeningskoll" g�rs, vad �r det?
		
		
		// G�r vi inte djuphetskopierng ? Nu g�r vi..
		for (int i = 0; i < this->TimbersInArr; i++) {
			delete this->timberArr[i];
		}
		delete[] this->timberArr;

		this->capacity = other.capacity;		
		this->TimbersInArr = other.TimbersInArr;

		this->timberArr = new Timber*[this->capacity];

		for (int i = 0; i < other.TimbersInArr; i++) {
					

			this->timberArr[i] = new Timber();
			*this->timberArr[i] = *other.timberArr[i]; 
			// TODO: "Ej korrekt, du har gl�mt kopiera �ver TimbersInArr"

			//^�r inte detta r�tt! 

			//this->TimbersInArr = other.TimbersInArr;
		}


		//return *this; //? 
	}

	return *this;

}



string TimberRegister::TimberToString()const
{
	
	string myLongString;
	string myTemp;
	for (int i = 0; i < this->TimbersInArr; i++) {
		 this->timberArr[i]->toString(myTemp);
		 myLongString += myTemp + "\n";
	}

	return myLongString;
}

TimberRegister::TimberRegister(const TimberRegister& copy)
{
	
	this->capacity = copy.capacity;
	this->TimbersInArr = copy.TimbersInArr;


	this->timberArr = new Timber*[this->capacity];

	for (int i = 0; i < this->TimbersInArr; i++) {

		 //�r detta inte r�tt? �r det inte deepcopy?
											//Nu m�ste det vara r�tt(?)
		this->timberArr[i] = new Timber();
							//^Detta l�ste mitt tidigare problem... Det var visserligen en array av Timbers
							// men inga objekt i den Arrayen var initierade (?), s� genom att initiera dem f�re vi anger ett v�rde
		*this->timberArr[i] = *copy.timberArr[i];
	}

	//this->timberArr = &tempArr;

	//**this->timberArr = *tempArr;


}
