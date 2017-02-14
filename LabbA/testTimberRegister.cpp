//Lowe Raivio
#include "Timber.h"
#include "TimerRegister.h"
#include "testTimberRegister.h"
#include <iostream>

using namespace std;



void testFunction() {
	//Testning:
	//1. Skapa ett objekt av typen TimberRegister(låt startkapaciteten vara 2).

	TimberRegister myRegister = TimberRegister(2);
	

	//2. Lägg in 2 virken.
	Timber timb1 = Timber(20, 30, 40, 60.9);
	Timber timb2 = Timber(25, 35, 40, 60.9);
	
	myRegister.add(timb1);
	myRegister.add(timb2);
	
	//Skriv ut de strängar som erhålls i arrayen som medlemsfunktionen för TimberRegister-objektet fyller i.
	string *stringArr = new string[500];
	myRegister.getTimberStringArr(stringArr);
	
	for (int i = 0; i < myRegister.getTimbersAmount(); i++) {
		cout << stringArr[i] << endl;
	}
	//delete[] stringArr;
	
	//3. Lägg till ytterligare ett virke(vilket ska medföra att arrayen i TimberRegister - objektet expanderar).
	//Skriv ut de strängar som erhålls i arrayen som medlemsfunktionen för TimberRegister - objektet fyller i.
	Timber timb3 = Timber(40, 30, 40, 62.9);
	
	myRegister.add(timb3);

	cout << "\nLägger till en tredje\n";

	//stringArr;
	myRegister.getTimberStringArr(stringArr);

	for (int i = 0; i < myRegister.getTimbersAmount(); i++) {
		cout << stringArr[i] << endl;
	}
	//delete[] stringArr;
	


	//4. Försök ta bort ett virke som inte finns inlagt och kontrollera att ingen borttagning gjordes samt
	//generera en utskrift av detta.

	myRegister.removeTimber("25x32");
	

	cout << "\nTar bort den med dimensionen '25x32', vilket som inte finns.. bör inte vara någon skillnad från föregående\n";

	//stringArr = myRegister.getTimberStringArr();
	myRegister.getTimberStringArr(stringArr);

	for (int i = 0; i < myRegister.getTimbersAmount(); i++) {
		cout << stringArr[i] << endl;
	}
	//delete[] stringArr;

	
	//5. Ta bort ett virke som finns inlagt och kontrollera att borttagningen genomförts.
	myRegister.removeTimber("25x35");
	

	cout << "\nTar bort den med dimensionen '25x35'\n";
	
	//stringArr = myRegister.getTimberStringArr();
	myRegister.getTimberStringArr(stringArr);

	for (int i = 0; i < myRegister.getTimbersAmount(); i++) {
		cout << stringArr[i] << endl;
	}
	//delete[] stringArr;
	
	//6. Tag bort de resterande 2 virkena från TimberRegister - objektet och kontrollera att det därefter inte
	//innehåller några virken.

	myRegister.removeTimber("20x30");
	myRegister.removeTimber("40x30");


	cout << "\nTar bort de restrerande virkerna; 40x30 och 20x30 \n";

	//stringArr = myRegister.getTimberStringArr();
	myRegister.getTimberStringArr(stringArr);

	for (int i = 0; i < 1; i++) {
		cout << stringArr[i] << endl;
	}
	//delete[] stringArr;

	//7. Lägg till 2 nya virken till TimberRegister - objektet och kontrollera att dessa finns inlagda.


	cout << "\nLägger till två nya virken och skriver ut dem \n";
	
	Timber timb4 = Timber(65, 35, 40, 62.9);
	Timber timb5 = Timber(70, 80, 40, 62.9);

	myRegister.add(timb4);
	myRegister.add(timb5);


	//stringArr = myRegister.getTimberStringArr();
	myRegister.getTimberStringArr(stringArr);

	for (int i = 0; i < myRegister.getTimbersAmount(); i++) {
		cout << stringArr[i] << endl;
	}
	//delete[] stringArr;

	//cout << "\nLägger till två nya virken och skriver ut dem 1\n";

	//8. Testa på lämpligt sätt kopieringskonstruktor(copykonstruktor) och tilldelningsoperator.
	//Avsluta programmet och kontrollera slutligen att inga minnesläckor upptäckts!
	cout << "\nTesta Kopieringskonstruktor och tilldelningskonstruktorn för Timber, '80x30' kommer skrivas ut två gånger, '75x15' en gång. MEN eftersom vi inte får har dubletter så skrivs inte den ut heller... \n";
	Timber timb6 = Timber(75, 15, 40, 62.9);
	Timber timb7 = Timber(80, 30, 40, 62.9);
	Timber timb8 = Timber(timb6);
	timb6 = timb7; // Vi använder tilldelningsoperatorn för att skriva över timb6 med timb7...


	cout << "\nTesta Kopieringskonstruktor och tilldelningskonstruktorn för TimberRegister \n";

	TimberRegister myRegister2 = TimberRegister(myRegister); //Testar copyConstructorn
	cout << "23" << endl;
	cout << "23" << endl; // om båda är samma så har kopieringen gått rätt till (iaf gällande amount of cash...)
	//to_string(myRegister2.amountOfCash)
	//to_string(myRegister.amountOfCash) 

	myRegister = myRegister2; //testa tilldelnings operatorn


	myRegister.add(timb6);
	myRegister.add(timb7);
	myRegister.add(timb8);


	//stringArr = myRegister.getTimberStringArr();
	myRegister.getTimberStringArr(stringArr);
	for (int i = 0; i < myRegister.getTimbersAmount(); i++) {
		cout << stringArr[i] << endl;
	}
	delete[] stringArr;		
}
