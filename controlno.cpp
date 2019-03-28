#include<iostream>
#include<cstring>
using namespace std;

class Measurement
{
	char* location;
	char* date;
	float temp;
public:
	Measurement();
	Measurement(const Measurement&);
	Measurement& operator=(const Measurement&);
	Measurement(char const* location, char const* date, double temperature);
	~Measurement();
	char const* getLocation() const;
	char const* getDate() const;
	double getTemperature() const;
	void setTemp(float);
	void setDate(char*);
	void setlocation(char*);
};

Measurement::Measurement(char const* location, char const* date, double temperature)
{
	temp = temperature;
	this->date = new char[strlen(date) + 1];
	strcpy(this->date, date);
	this->location = new char[strlen(location) + 1];
	strcpy(this->location, location);
}
Measurement::Measurement() :temp(0)
{
	location = new char[1];
	location[0] = '\0';
	date = new char[1];
	date[0] = '\0';
}
Measurement::Measurement(const Measurement& other) :temp(other.temp)
{
	location = new char[strlen(other.location) + 1];
	strcpy(location, other.location);
	date = new char[strlen(other.date) + 1];
	strcpy(date, other.date);
}
Measurement& Measurement::operator=(const Measurement& other)
{
	delete[] location;
	delete[] date;
	location = new char[strlen(other.location) + 1];
	strcpy(location, other.location);
	date = new char[strlen(other.date) + 1];
	strcpy(date, other.date);
	return *this;
}
Measurement::~Measurement()
{
	delete[] location;
	delete[] date;
}

char const* Measurement::getLocation() const
{
	return location;
}
char const* Measurement::getDate() const
{
	return date;
}
double Measurement::getTemperature() const
{
	return temp;
}
void Measurement::setTemp(float other)
{
	temp = other;
}

void Measurement::setDate(char* other)
{
	//DD/MM/YY
	if (other[0] >= '0'&& other[0] <= '9'&&
		other[1] >= '0'&& other[1] <= '9'&&
		other[3] >= '0'&& other[3] <= '9'&&
		other[4] >= '0'&& other[4] <= '9'&&
		other[6] >= '0'&& other[6] <= '9'&&
		other[7] >= '0'&& other[7] <= '9'&&
		other[2] == '/' && other[5] == '/' && (other[3] == '1' || other[3] == '0') && other[0] >= '0' && other[0] <= '6')
	{
		delete[] date;
		strcpy(date, other);
	}
	else
	{
		cout << " wrong data";
	}
}
void Measurement::setlocation(char* other)
{
	delete[] location;
	strcpy(location, other);
}

class  MaxTemperatures
{
	Measurement* measurements;
	int N;
	int length;

public:
	MaxTemperatures();
	MaxTemperatures(unsigned int);
	MaxTemperatures(const MaxTemperatures&);
	MaxTemperatures& operator= (const MaxTemperatures&);
	~MaxTemperatures();

	void addMeasurement(Measurement const& measurement);
	double findAverage()const;
	double highestMeasurement()const;
	void Resize();

};
MaxTemperatures::MaxTemperatures() :N(2), length(0)
{
	measurements = new Measurement[N];
}
MaxTemperatures::MaxTemperatures(unsigned int N) : N(N), length(0)
{
	measurements = new Measurement[N];
}
MaxTemperatures::MaxTemperatures(const MaxTemperatures& other)
{
	length = other.length;
	N = other.N;
	measurements = new Measurement[N];
	for (int i = 0; i < length; i++)
	{
		measurements[i] = other.measurements[i];
	}
}
MaxTemperatures& MaxTemperatures::operator=(const MaxTemperatures& other)
{
	delete[] measurements;
	length = other.length;
	N = other.N;
	measurements = new Measurement[N];
	for (int i = 0; i < length; i++)
	{
		measurements[i] = other.measurements[i];
	}
	return *this;
}
MaxTemperatures::~MaxTemperatures()
{
	delete[] measurements;
}

void MaxTemperatures::addMeasurement(Measurement const& other)
{
	length++;
	if (length == N)
		Resize();
	for (int i = 0; i < this->length; i++)
	{
		if (strcmp(measurements->getLocation(), other.getLocation()) == 0)
			if (other.getTemperature() > this->measurements[i].getTemperature())
			{
				measurements[i].setTemp(other.getTemperature());
				return;
			}
	}
	for (int i = length - 1; i > 0; i--)
	{
		measurements[i] = measurements[i - 1];
	}
	measurements[0] = other;
}
double MaxTemperatures::findAverage()const
{
	double result = 0;
	for (int i = 0; i < length; i++)
	{
		result += measurements[i].getTemperature();
	}
	return result / length;
}
double MaxTemperatures::highestMeasurement()const
{
	double result = 0;
	for (int i = 0; i < length; i++)
	{
		if (result < measurements[i].getTemperature())
			result = measurements[i].getTemperature();
	}
	return result;
}
void MaxTemperatures::Resize()
{

	N *= 2;
	Measurement* temp = new Measurement[N];
	for (int i = 0; i < length; i++)
	{
		temp[i] = measurements[i];
	}
	delete[] measurements;
	measurements = temp;

}

///

//#define DOCTEST_CONFIG_IMPLEMENT
//#include "doctest.h"

//-------------------------------------------------------------------------
//
// ÂÀÆÍÎ: Ïðåäè ïðåäàâàíå íà ðåøåíèåòî, ìîëÿ ïðåìàõíåòå êîìåíòàðà îò äàäåíèÿ ïî-äîëó ðåä,
//        çà äà àêòèâèðàòå àâòîìàòè÷íèòå òåñòîâå çà ðåøåíèåòî ñè.
//
//-------------------------------------------------------------------------
//#include "var3-tests.h"

int main() {

	//-------------------------------------------------------------------------
	//
	// ÂÀÆÍÎ: Ïðè ïðåäàâàíå íà ðàáîòàòà âúâ òÿëîòî íà ôóíêöèÿòà main íå òðÿáâà äà ñå
	//        èçïúëíÿâà íèùî äðóãî îñâåí äîëíèÿ ðåä.
	//
	//-------------------------------------------------------------------------
	//doctest::Context().run();
	system("pause");
	return 0;
}
