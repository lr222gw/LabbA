//Lowe Raivio
#include "Timber.h"

void Timber::setPrice( float price)
{
	this->prisPerMeter = price;
}

void Timber::setMeter( float meter)
{
	this->antalMeter = meter;
}

float Timber::getPrice()const
{
	
	return this->prisPerMeter*this->antalMeter;
	
}

Timber::Timber(float width, float height, float meters, float prisPerMeter)
{
	this->height = height;
	this->width = width;
	this->antalMeter = meters;
	this->dimension = to_string((int)width) + "x" + to_string((int)height);
	this->prisPerMeter = prisPerMeter;
	
}

Timber::Timber()
{// Konstruktor
	this->antalMeter = -1;
	this->dimension = "null";
	this->prisPerMeter = -1;	
	this->height = -1;
	this->width = -1;

}

void Timber::toString(string &myString)
{
	myString =	this->dimension + "| " +
						to_string(this->antalMeter) + "m | "	+
						to_string((int)roundf(this->prisPerMeter)) + " cash/meter | "	+
						to_string((int)roundf(this->height)) +	" height| "	+
						to_string((int)roundf(this->width))  +	" width| "	;
	
}

string Timber::getDimension()const
{
	return this->dimension;
}

float Timber::getMeter()const
{
	return this->antalMeter;
}

float Timber::getPricePerMeter()const
{
	return this->prisPerMeter;
}

float Timber::getWidth()const
{
	return this->width;
}

float Timber::getHeight()const
{
	return this->height;
}



void Timber::operator=(const Timber& other)
{

	this->antalMeter = other.antalMeter;
	this->dimension = other.dimension;

	this->prisPerMeter = other.prisPerMeter;

	this->height = other.height;
	this->width = other.width;
	
}

Timber::Timber(const Timber& copy)
{

	this->antalMeter = copy.antalMeter;
	this->dimension = copy.dimension;

	this->prisPerMeter = copy.prisPerMeter;

	this->height = copy.height;
	this->width = copy.width;
}

bool Timber::operator==(const Timber & other)const
{	
	
	return (this->dimension == other.dimension);

}