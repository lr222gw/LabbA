//Lowe Raivio
#ifndef TIMBER_H
#define TIMBER_H

#include <string>

using namespace std;


class Timber {

private:
	string dimension;
	int antalMeter;
	float width;
	float height;
	float prisPerMeter;

public:

	float getPricePerMeter() const;

	float getWidth() const;

	float getHeight() const;

	void setPrice(float price);

	void setMeter(float meter);

	float getMeter() const;

	float getPrice() const;

	Timber(float width, float height, float meters, float prisPerMeter);

	Timber();

	void toString(string &myString)const;

	string getDimension()const;

	void Timber::operator=(const Timber& copy);

	bool operator==(const Timber& other)const;
	

	Timber::Timber(const Timber& copy);


};


#endif // !TIMBER_H
