//Lowe Raivio
#include <iostream>
#include <crtdbg.h>
#include "testTimberRegister.h"
#include "Timber.h"
#include "TimerRegister.h"

using namespace std;

void writeMenu();
void getInput(char &status);
void doChoice(char status, TimberRegister *myRegister);
void addTimber(TimberRegister *myRegister);
void presentRegister(TimberRegister *myRegister);
void presentTimberIfLessThan(TimberRegister *myRegister);
void presentAllCash(TimberRegister *myRegister);
void removeTimber(TimberRegister *myRegister);
void changeTimber(TimberRegister *myRegister);
void saveToFile(TimberRegister *myRegister);
void loadToFile(TimberRegister *myRegister);

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//testFunction();
	char status = 'a';
	setlocale(0, "swedish");
	
	TimberRegister myTimberRegister(5);


	while (status != 'q') {
		status = 'a';
		system("cls");
		writeMenu();
		getInput(status);

		if (status != 'q') {
			doChoice(status, &myTimberRegister);
		}
	}


	return 0;
	
}

void writeMenu() {
	cout << "------------------------------------------------------------------------------------------------\n"
		<< "1. L�gga till ett nytt virke till lagret" << endl 
		<< "2. Presentera all information om alla virken som finns p� lager" << endl
		<< "3. Presentera endast virkesdimensionen f�r de virken d�r antal meter p� lager understiger ett av anv�ndaren angivet v�rde" << endl
		<< "4. Presentera totalkostnaden f�r allt virke som finns p� lagret" << endl
		<< "5. Ta bort ett virke fr�n lagret givet virkesdimensionen(inga �h�l� i arrayen)" << endl
		<< "6. �ndra uppgifter(pris per l�pmeter samt antal l�pmeter p� lager) f�r en av anv�ndaren angiven virkesdimension" << endl
		<< "7. Spara alla virken p� fil d�r filnamnet matas in av anv�ndaren" << endl
		<< "8. L�sa alla virken fr�n fil d�r filnamnet matas in av anv�ndaren" << endl
		<< "9. K�r Testet..." << endl
		<< "------------------------------------------------------------------------------------------------\n"<< "q to quit...\n";
	
}

void getInput(char & status) {
	cin >> status; 

	cin.ignore();
}

void doChoice(char status, TimberRegister * myRegister) {
	string stringArr[500];
	myRegister->getTimberStringArr(stringArr);
	//char choice = status;
	switch (status) {
	case '1':{
		addTimber(myRegister);
	}
		break;
	case '2': {
		presentRegister(myRegister);	
	}
		break;
	case '3': {
		presentTimberIfLessThan(myRegister);
	}
		break;
	case '4': {
		presentAllCash(myRegister);		
	}
		break;
	case '5': {
		removeTimber(myRegister);
	}
		break;
	case '6': {
		changeTimber(myRegister);
	}
		break;
	case '7': {
		saveToFile(myRegister);
	}
		break;
	case '8': {
		loadToFile(myRegister);

	}
		break;
	case '9': {
		system("cls");
		testFunction();
		getchar();
	}
		break;
	case 'r': {
		//bara f�r att testa min timberToString funktion
		system("cls");
		cout << "Secret case..." << endl;
		string stuff = myRegister->TimberToString();
		cout << stuff;

		getchar();
	}
			  break;
	default:
		cout << "Don't be stupid. That's not a valid number...\n";
		
		getchar(); //tv� getchar f�r att den �r askonstig...


		break;
	};


	//delete[] stringArr;
}

void addTimber(TimberRegister * myRegister)
{
	float width, height, price, meter;
	cout << "What Width? \n";
	cin >> width;
	cout << "What height? \n";
	cin >> height;
	cout << "How many meters?\n";
	cin >> meter;
	cout << "What price per meter? \n";
	cin >> price;
	myRegister->add(Timber(width, height, meter, price));
}

void presentRegister(TimberRegister * myRegister)
{
	
	string *stringArr = new string[myRegister->getTimbersAmount()];
	myRegister->getTimberStringArr(stringArr);

	for (int i = 0; i < myRegister->getTimbersAmount(); i++) {
		cout << stringArr[i] << endl;
	}
	delete[] stringArr;

	getchar();
}

void presentTimberIfLessThan(TimberRegister * myRegister)
{
	float minMeter;
	cout << "Ange ett maxv�rde (listan visar alla virken som understiger maxv�rdet..) \n";
	cin >> minMeter;
	cin.ignore();
	string stringArr[500];
	myRegister->getTimberStringArr(stringArr,minMeter);

	for (int i = 0; i < myRegister->getTimbersAmount(); i++) {

		cout << stringArr[i] << endl;
	}
	//delete[] stringArr;

	getchar();
}

void presentAllCash(TimberRegister * myRegister)
{
	cout << to_string(myRegister->amountOfCash());

	getchar();
}

void removeTimber(TimberRegister * myRegister)
{
	string dimension;
	cout << "Type a dimension you want to remove \n";
	cin >> dimension;
	cin.ignore();
	myRegister->removeTimber(dimension);

	getchar();
}

void changeTimber(TimberRegister * myRegister)
{
	//�ndra uppgifter(pris per l�pmeter samt antal l�pmeter p� lager) f�r en av anv�ndaren angiven virkesdimension
	string dimension;
	float cash, meter;
	cout << "Type a dimension you want to Edit \n";
	cin >> dimension;
	cin.ignore();

	Timber myTimber;
	myRegister->getTimber(dimension, myTimber);
	if (myTimber.getMeter() == -1) {
		cout << "Hittade inget med den dimensionen";
	}
	else {
		cout << "Select New Price, old price was " << myTimber.getPricePerMeter() << " \n";
		cin >> cash;
		cin.ignore();


		cout << "Select new Meter, old Meter was " << myTimber.getMeter() << " \n";
		cin >> meter;
		cin.ignore();

		myTimber.setMeter(meter);
		myTimber.setPrice(cash);

		myRegister->editTimber(myTimber);
	}

	getchar();
}

void saveToFile(TimberRegister * myRegister)
{
	string filename;
	cout << "Ange filnamn (gl�m ej .txt)\n";
	cin >> filename;

	myRegister->saveFile(filename);
}

void loadToFile(TimberRegister * myRegister)
{
	string filename;
	cout << "Ange filnamn (gl�m ej .txt)\n";
	cin >> filename;

	myRegister->loadFile(filename);
}
