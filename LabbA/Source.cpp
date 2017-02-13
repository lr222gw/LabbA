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
		<< "1. Lägga till ett nytt virke till lagret" << endl 
		<< "2. Presentera all information om alla virken som finns på lager" << endl
		<< "3. Presentera endast virkesdimensionen för de virken där antal meter på lager understiger ett av användaren angivet värde" << endl
		<< "4. Presentera totalkostnaden för allt virke som finns på lagret" << endl
		<< "5. Ta bort ett virke från lagret givet virkesdimensionen(inga ”hål” i arrayen)" << endl
		<< "6. Ändra uppgifter(pris per löpmeter samt antal löpmeter på lager) för en av användaren angiven virkesdimension" << endl
		<< "7. Spara alla virken på fil där filnamnet matas in av användaren" << endl
		<< "8. Läsa alla virken från fil där filnamnet matas in av användaren" << endl
		<< "9. Kör Testet..." << endl
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
		//bara för att testa min timberToString funktion
		system("cls");
		cout << "Secret case..." << endl;
		string stuff = myRegister->TimberToString();
		cout << stuff;

		getchar();
	}
			  break;
	default:
		cout << "Don't be stupid. That's not a valid number...\n";
		
		getchar(); //två getchar för att den är askonstig...


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
	cout << "Ange ett maxvärde (listan visar alla virken som understiger maxvärdet..) \n";
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
	//Ändra uppgifter(pris per löpmeter samt antal löpmeter på lager) för en av användaren angiven virkesdimension
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
	cout << "Ange filnamn (glöm ej .txt)\n";
	cin >> filename;

	myRegister->saveFile(filename);
}

void loadToFile(TimberRegister * myRegister)
{
	string filename;
	cout << "Ange filnamn (glöm ej .txt)\n";
	cin >> filename;

	myRegister->loadFile(filename);
}
