//Lowe Raivio
#include "TimerRegister.h"
#include <fstream>

void TimberRegister::expandTimberArr()
{
	//OBS, kontrollera att DeepCopy har utförts...

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
		if (this->timberArr[i]->getDimension() == toCheck.getDimension()) {
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
	//TODO HJÄLP: Detta orsakar problem med kopieringskonstruktorn...

	for (int i = 0; i < this->TimbersInArr; i++) {

		//Denna "this->timberArr[i]" innehåller Korupterad data...
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

	for (int i = 0; i < this->TimbersInArr; i++) {
		if (min == -1) {
			 this->timberArr[i]->toString(arr[i]);
		}
		else {
			if (min >= this->timberArr[i]->getMeter()) {
				this->timberArr[i]->toString(arr[i]);
				//arr[i] = this->timberArr[i]->toString();
			}
		}
		
	}

	if (this->TimbersInArr == 0) {
		arr[0] = "TimberRegister är helt tom...\n";
	}

	//return arr;
}

void TimberRegister::removeTimber(string dimension)
{
	
	for (int i = 0; i < this->TimbersInArr; i++) {
		
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
void  TimberRegister::operator=(const TimberRegister &other)
{

	//TODO Fråga om: Ingen "Självtilldeningskoll" görs, vad är det?
	// Gör vi inte djuphetskopierng ?


	this->capacity = other.capacity;
	*this->timberArr = *other.timberArr;
	this->TimbersInArr = other.TimbersInArr;
	
	//return *this; //? 

}



string TimberRegister::TimberToString()const
{
	//TODO:  loopa timberArr, använd "toString", spara ner alla resultat, returnera stringArr
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
	//TODO Fråga om: Är detta ingen deepcopy?
	this->capacity = copy.capacity;
	this->TimbersInArr = copy.TimbersInArr;

	//Timber **tempArr = new Timber*[this->capacity];
	//Timber *tempArr = new Timber[this->capacity];
	//this->timberArr = new Timber[this->capacity];
	Timber *tempArr = new Timber[this->capacity];

	for (int i = 0; i < this->TimbersInArr; i++) {

		tempArr[i] = *copy.timberArr[i];   //Är detta inte rätt? Är det inte deepcopy?
											//Nu måste det vara rätt(?)
	}

	this->timberArr = &tempArr;

	//**this->timberArr = *tempArr;


}
