/*Before Running:
Project Was Made In Visual Studio 2017 v15.5.7
OpenSSL v1.1.0 x86
Libeay32MTd.lib Name Has Changed To libcrypto32MTd.lib
https://github.com/arvidn/libtorrent/issues/1931
Add this to Project Properties->C/C++->General->Additional Include Directories: C:\OpenSSL\include
Add this to Project Properties->Linker->Command Line: C:\OpenSSL\lib\VC\libcrypto32MTd.lib
Change Path According To Your OpenSSL Install Directory.*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <openssl\sha.h>
#include <openssl\des.h>
using namespace std;

class PcPart
{
private:
	char* partManufacturer;
	char* partModel;
	long partPrice;
public:

	virtual void printPcPart() = 0; //abstract class

	char* getPartManufacturer()
	{
		if (this->partManufacturer != NULL)
		{
			return this->partManufacturer;
		}
		else
		{
			return NULL;
		}
	}

	char* getPartModel()
	{
		if (this->partModel != NULL)
		{
			return this->partModel;
		}
		else
		{
			return NULL;
		}

	}

	long getPartPrice()
	{
		return this->partPrice;
	}

	void setPartManufacturer(const char* _Manufacturer)
	{
		if (this->partManufacturer != NULL)
		{
			delete[] this->partManufacturer;
			this->partManufacturer = NULL;
			this->partManufacturer = new char[strlen(_Manufacturer) + 1];
			strcpy_s(this->partManufacturer, (strlen(_Manufacturer) + 1), _Manufacturer);
		}
		else
		{
			this->partManufacturer = new char[strlen(_Manufacturer) + 1];
			strcpy_s(this->partManufacturer, (strlen(_Manufacturer) + 1), _Manufacturer);
		}
	}

	void setPartModel(const char* _Model)
	{
		if (this->partModel != NULL)
		{
			delete[] this->partModel;
			this->partModel = NULL;
			this->partModel = new char[strlen(_Model) + 1];
			strcpy_s(this->partModel, (strlen(_Model) + 1), _Model);
		}
		else
		{
			this->partModel = new char[strlen(_Model) + 1];
			strcpy_s(this->partModel, (strlen(_Model) + 1), _Model);
		}
	}

	void setPartPrice(long _Price)
	{
		this->partPrice = _Price;
	}

	PcPart() //default constructor
	{
		//cout << "pcPart Default Constructor" << endl;
		this->partManufacturer = NULL;
		this->partModel = NULL;
		this->partPrice = 0;
	}

	PcPart(const char* _Manufacturer, const  char* _Model, long _Price) //constructor with parameters
	{
		//cout << "pcPart Parameters Constructor" << endl;
		this->partManufacturer = new char[strlen(_Manufacturer) + 1];
		strcpy_s(this->partManufacturer, strlen(_Manufacturer) + 1, _Manufacturer);
		this->partModel = new char[strlen(_Model) + 1];
		strcpy_s(this->partModel, (strlen(_Model) + 1), _Model);
		this->partPrice = _Price;
	}

	PcPart(const PcPart &copy) //copy constructor
	{
		//cout << "pcPart Copy Constructor" << endl;
		if (copy.partManufacturer != NULL)
		{
			this->partManufacturer = new char[strlen(copy.partManufacturer) + 1];
			strcpy_s(this->partManufacturer, strlen(copy.partManufacturer) + 1, copy.partManufacturer);
		}
		else
		{
			this->partManufacturer = NULL;
		}
		if (copy.partModel != NULL)
		{
			this->partModel = new char[strlen(copy.partModel) + 1];
			strcpy_s(this->partModel, (strlen(copy.partModel) + 1), copy.partModel);
		}
		else
		{
			this->partModel = NULL;
		}
		this->partPrice = copy.partPrice;
	}

	~PcPart() //destructror
	{
		//cout << "pcPart Destructor" << endl;
		delete[] this->partManufacturer;
		this->partManufacturer = NULL;
		delete[] this->partModel;
		this->partModel = NULL;
	}
};

class CPU :public PcPart
{
private:
	char* cpuSocket;
	float cpuFrequency;
	int cpuCores;
	int cpuThreads;
public:
	char* getCpuSocket()
	{
		if (this->cpuSocket != NULL)
		{
			return this->cpuSocket;
		}
		else
		{
			return NULL;
		}
	}

	float getCpuFrequency()
	{
		return this->cpuFrequency;
	}

	int getCpuThreads()
	{
		return this->cpuThreads;
	}

	int getCpuCores()
	{
		return this->cpuCores;
	}

	void setCpuSocket(const char* _Socket)
	{
		if (this->cpuSocket != NULL)
		{
			delete[] this->cpuSocket;
			this->cpuSocket = NULL;
			this->cpuSocket = new char[strlen(_Socket) + 1];
			strcpy_s(this->cpuSocket, (strlen(_Socket) + 1), _Socket);
		}
		else
		{
			this->cpuSocket = new char[strlen(_Socket) + 1];
			strcpy_s(this->cpuSocket, (strlen(_Socket) + 1), _Socket);
		}
	}

	void setCpuCores(int _Cores)
	{
		this->cpuCores = _Cores;
	}

	void setCpuThreads(int _Threads)
	{
		this->cpuThreads = _Threads;
	}

	void setCpuFrequency(float _Frequency)
	{
		this->cpuFrequency = _Frequency;
	}

	CPU() : PcPart() //default constructor
	{
		//cout << "CPU Default Constructor" << endl;
		this->cpuSocket = NULL;
		this->cpuFrequency = 0;
		this->cpuCores = 0;
		this->cpuThreads = 0;
	}

	CPU(const char* _Manufacturer, const char* _Model, long _Price, const char* _Socket,
		float _Frequency, int _Cores, int _Threads)
		: PcPart(_Manufacturer, _Model, _Price) //constructor with parameters
	{
		//cout << "CPU Parameters Constructor" << endl;
		this->cpuSocket = new char[strlen(_Socket) + 1];
		strcpy_s(this->cpuSocket, (strlen(_Socket) + 1), _Socket);
		this->cpuFrequency = _Frequency;
		this->cpuCores = _Cores;
		this->cpuThreads = _Threads;
	}

	CPU(const CPU &copy) :PcPart(copy) //copy constructor
	{
		//cout << "CPU Copy Constructor" << endl;
		if (copy.cpuSocket != NULL)
		{
			this->cpuSocket = new char[strlen(copy.cpuSocket) + 1];
			strcpy_s(this->cpuSocket, (strlen(copy.cpuSocket) + 1), copy.cpuSocket);
		}
		else
		{
			this->cpuSocket = NULL;
		}
		this->cpuFrequency = copy.cpuFrequency;
		this->cpuCores = copy.cpuCores;
		this->cpuThreads = copy.cpuThreads;
	}

	CPU operator=(CPU &equal) //= operator
	{
		//cout << "CPU Operator =" << endl;
		this->setPartManufacturer(equal.getPartManufacturer());
		this->setPartModel(equal.getPartModel());
		this->setPartPrice(equal.getPartPrice());
		delete[] this->cpuSocket;
		this->cpuSocket = NULL;
		this->cpuSocket = new char[strlen(equal.cpuSocket) + 1];
		strcpy_s(this->cpuSocket, (strlen(equal.cpuSocket) + 1), equal.cpuSocket);
		this->cpuFrequency = equal.cpuFrequency;
		this->cpuCores = equal.cpuCores;
		this->cpuThreads = equal.cpuThreads;
		return *this;
	}

	CPU operator++() //++ pre increment
	{
		long price = this->getPartPrice();
		price += 50;
		this->setPartPrice(price);
		return *this;
	}

	CPU operator++(int) //++ post increment
	{
		CPU aux = *this;
		long price = this->getPartPrice();
		price += 50;
		this->setPartPrice(price);
		return aux;
	}

	bool operator!=(CPU _Cpu) //operator != (compare two CPU)
	{
		if ((_stricmp(this->getPartManufacturer(), _Cpu.getPartManufacturer()) == 0) &&
			(_stricmp(this->getPartModel(), _Cpu.getPartModel()) == 0) &&
			(this->getPartPrice() == _Cpu.getPartPrice()) &&
			(_stricmp(this->cpuSocket, _Cpu.cpuSocket) == 0) &&
			(this->cpuFrequency == _Cpu.cpuFrequency) &&
			(this->cpuCores == _Cpu.cpuCores) &&
			(this->cpuThreads == _Cpu.cpuThreads))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	explicit operator int() //cast operator long to double
	{
		long price = this->getPartPrice();
		int castPrice = (int)price;
		return castPrice;
	}

	CPU operator+(long _Price) //binary operator + (CPU + long)
	{
		long price = this->getPartPrice();
		price += _Price;
		this->setPartPrice(price);
		return *this;
	}

	friend ostream& operator<<(ostream &output, CPU _Cpu) //<< operator
	{
		output << "CPU @:" << &_Cpu << endl;
		if (_Cpu.getPartManufacturer() != NULL)
		{
			output << "CPU Manufacturer: " << _Cpu.getPartManufacturer() << endl;
		}
		else
		{
			output << "CPU Manufacturer: NULL" << endl;
		}
		if (_Cpu.getPartModel() != NULL)
		{
			output << "CPU Model: " << _Cpu.getPartModel() << endl;
		}
		else
		{
			output << "CPU Model: NULL" << endl;
		}
		output << "CPU Price: " << _Cpu.getPartPrice() << endl;
		if (_Cpu.cpuSocket != NULL)
		{
			output << "CPU Socket: " << _Cpu.cpuSocket << endl;
		}
		else
		{
			output << "CPU Socket: NULL" << endl;
		}
		output << "CPU Frequency: " << _Cpu.cpuFrequency << endl;
		output << "CPU Cores: " << _Cpu.cpuCores << endl;
		output << "CPU Threads: " << _Cpu.cpuThreads << endl;
		output << endl;
		return output;
	}

	void printPcPart() //method inherited from the abstract class
	{
		cout << "CPU @:" << this << endl;
		if (this->getPartManufacturer() != NULL)
		{
			cout << "Part Manufacturer: " << this->getPartManufacturer() << endl;
		}
		else
		{
			cout << "Part Manufacturer: NULL" << endl;
		}
		if (this->getPartModel() != NULL)
		{
			cout << "Part Model: " << this->getPartModel() << endl;
		}
		else
		{
			cout << "Part Model: NULL" << endl;
		}
		cout << "Part Price: " << this->getPartPrice() << endl;
		if (this->cpuSocket != NULL)
		{
			cout << "CPU Socket: " << this->cpuSocket << endl;
		}
		else
		{
			cout << "CPU Socket: NULL" << endl;
		}
		cout << "CPU Frequency: " << this->cpuFrequency << endl;
		cout << "CPU Cores: " << this->cpuCores << endl;
		cout << "CPU Threads: " << this->cpuThreads << endl;
		cout << endl;
	}

	~CPU() //destructor
	{
		//cout << "CPU Destructor" << endl;
		delete[] this->cpuSocket;
		this->cpuSocket = NULL;
	}
};

CPU operator+(long _Price, CPU cpu) //binary operator + (long + CPU)
{
	long price = cpu.getPartPrice();
	price += _Price;
	cpu.setPartPrice(price);
	return cpu;
}

CPU operator+(CPU cpu1, CPU cpu2) //binary operator + (CPU + CPU)
{
	long price = cpu1.getPartPrice();
	price += cpu2.getPartPrice();
	cpu1.setPartPrice(price);
	return cpu1;
}

class RAM : public PcPart
{
private:
	char* ramType;
	float ramFrequency;
	int ramSize;
public:
	char* getRamType()
	{
		if (this->ramType != NULL) {
			return this->ramType;
		}
		else
		{
			return NULL;
		}
	}

	float getRamFrequency()
	{
		return this->ramFrequency;
	}

	int getRamSize()
	{
		return this->ramSize;
	}

	void setRamType(const char* _Type)
	{
		if (this->ramType != NULL)
		{
			delete[] this->ramType;
			this->ramType = NULL;
			this->ramType = new char[strlen(_Type) + 1];
			strcpy_s(this->ramType, (strlen(_Type) + 1), _Type);
		}
		else
		{
			this->ramType = new char[strlen(_Type) + 1];
			strcpy_s(this->ramType, (strlen(_Type) + 1), _Type);
		}
	}

	void setRamSize(int _Size)
	{
		this->ramSize = _Size;
	}

	void setRamFrequency(float _Frequency)
	{
		this->ramFrequency = _Frequency;
	}

	RAM() : PcPart() //default constructor
	{
		//cout << "RAM Default Constructor" << endl;
		this->ramType = NULL;
		this->ramFrequency = 0;
		this->ramSize = 0;
	}

	RAM(const char* _Manufacturer, const char* _Model, long _Price,
		const char* _Type, float _Frequency, int _Size) :
		PcPart(_Manufacturer, _Model, _Price) //parameters constructor
	{
		//cout << "RAM Parameters Constructors" << endl;
		this->ramFrequency = _Frequency;
		this->ramSize = _Size;
		this->ramType = new char[strlen(_Type) + 1];
		strcpy_s(this->ramType, (strlen(_Type) + 1), _Type);
	}

	RAM(const RAM &copy) : PcPart(copy) //copy constructor
	{
		//cout << "RAM Copy Constructor" << endl;
		if (copy.ramType != NULL)
		{
			this->ramType = new char[strlen(copy.ramType) + 1];
			strcpy_s(this->ramType, (strlen(copy.ramType) + 1), copy.ramType);
		}
		else
		{
			this->ramType = NULL;
		}
		this->ramFrequency = copy.ramFrequency;
		this->ramSize = copy.ramSize;
	}

	RAM operator=(RAM &equal) //operator =
	{
		//cout << "RAM Operator =" << endl;
		this->setPartManufacturer(equal.getPartManufacturer());
		this->setPartModel(equal.getPartModel());
		this->setPartPrice(equal.getPartPrice());
		delete[] this->ramType;
		this->ramType = NULL;
		this->ramType = new char[strlen(equal.ramType) + 1];
		strcpy_s(this->ramType, (strlen(equal.ramType) + 1), equal.ramType);
		this->ramFrequency = equal.ramFrequency;
		this->ramSize = equal.ramSize;
		return *this;
	}

	RAM operator--() //-- pre increment
	{
		float frequency = this->ramFrequency;
		frequency -= 50;
		this->setRamFrequency(frequency);
		return *this;
	}

	RAM operator--(int) //-- post increment
	{
		RAM aux = *this;
		float frequency = this->ramFrequency;
		frequency -= 50;
		this->setRamFrequency(frequency);
		return aux;
	}

	bool operator!=(RAM _Ram) // operator !=
	{
		if ((_stricmp(this->getPartManufacturer(), _Ram.getPartManufacturer()) == 0) &&
			(_stricmp(this->getPartModel(), _Ram.getPartModel()) == 0) &&
			(this->getPartPrice() == _Ram.getPartPrice()) &&
			(_stricmp(this->ramType, _Ram.ramType) == 0) &&
			(this->ramSize == _Ram.ramSize) &&
			(this->ramFrequency == _Ram.ramFrequency))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	explicit operator int() //cast operator float to int
	{
		float frequency = this->ramFrequency;;
		int castedFrequency = (int)frequency;
		return castedFrequency;
	}

	RAM operator+(float _Frequency) //binary operator + (RAM + float)
	{
		float frequency = this->ramFrequency;
		frequency += _Frequency;
		this->setRamFrequency(frequency);
		return *this;
	}

	RAM operator-(float _Frequency) //binary operator - (RAM - float)
	{
		float frequency = this->ramFrequency;
		frequency -= _Frequency;
		this->setRamFrequency(frequency);
		return *this;
	}

	friend ostream& operator<<(ostream &output, RAM _Ram) //<< operator
	{
		output << "RAM @:" << &_Ram << endl;
		if (_Ram.getPartManufacturer() != NULL)
		{
			output << "RAM Manufacturer: " << _Ram.getPartManufacturer() << endl;
		}
		else
		{
			output << "RAM Manufacturer: NULL" << endl;
		}
		if (_Ram.getPartModel() != NULL)
		{
			output << "RAM Model: " << _Ram.getPartModel() << endl;
		}
		else
		{
			output << "RAM Model: NULL" << endl;
		}
		output << "RAM Price: " << _Ram.getPartPrice() << endl;
		if (_Ram.ramType != NULL)
		{
			output << "RAM Type: " << _Ram.ramType << endl;
		}
		else
		{
			output << "RAM Type: NULL" << endl;
		}
		output << "RAM Frequency: " << _Ram.ramFrequency << endl;
		output << "RAM Size: " << _Ram.ramSize << endl;
		output << endl;
		return output;
	}

	void printPcPart() //method inherited from the abstract class
	{
		cout << "RAM @:" << this << endl;
		if (this->getPartManufacturer() != NULL)
		{
			cout << "Part Manufacturer: " << this->getPartManufacturer() << endl;
		}
		else
		{
			cout << "Part Manufacturer: NULL" << endl;
		}
		if (this->getPartModel() != NULL)
		{
			cout << "Part Model: " << this->getPartModel() << endl;
		}
		else
		{
			cout << "Part Model: NULL" << endl;
		}
		cout << "Part Price: " << this->getPartPrice() << endl;
		if (this->ramType != NULL)
		{
			cout << "RAM Type: " << this->ramType << endl;
		}
		else
		{
			cout << "RAM Type: NULL" << endl;
		}
		cout << "RAM Frequency: " << this->ramFrequency << endl;
		cout << "RAM Size: " << this->ramSize << endl;
		cout << endl;
	}

	~RAM() //destructor
	{
		//cout << "RAM Destructor" << endl;
		delete[] this->ramType;
		this->ramType = NULL;
	}
};

float operator+(float _Frequency, RAM _Ram) //binary operator + (long + RAM)
{
	float frequency = _Ram.getRamFrequency();
	frequency += _Frequency;
	return frequency;
}

float operator-(long _Frequency, RAM _Ram) //binary operator - (long - RAM)
{
	float frequency = _Ram.getRamFrequency();
	frequency -= _Frequency;
	return frequency;
}

RAM operator+(RAM _Ram1, RAM _Ram2) //binary operator + (RAM + RAM)
{
	float frequency = _Ram1.getRamFrequency();
	frequency += _Ram2.getRamFrequency();
	_Ram1.setRamFrequency(frequency);
	return _Ram1;
}

RAM operator-(RAM _Ram1, RAM _Ram2) //binary operator - (RAM - RAM)
{
	float frequency = _Ram1.getRamFrequency();
	frequency -= _Ram2.getRamFrequency();
	_Ram1.setRamFrequency(frequency);
	return _Ram1;
}

class Motherboard : public PcPart
{
private:
	char* cpuSocket;
	char* chipset;
	char* ramType;
	int ramSlots;
	int pciExpressSlots;
public:
	char* getCpuSocket()
	{
		if (this->cpuSocket != NULL)
		{
			return this->cpuSocket;
		}
		else
		{
			return NULL;
		}
	}

	char* getChipset()
	{
		if (this->chipset != NULL)
		{
			return this->chipset;
		}
		else
		{
			return NULL;
		}
	}

	char* getRamType()
	{
		if (this->ramType != NULL)
		{
			return this->ramType;
		}
		else
		{
			return NULL;
		}
	}

	int getRamSlots()
	{
		return this->ramSlots;
	}

	int getPciExpressSlots()
	{
		return this->pciExpressSlots;
	}

	void setCpuSocket(const char* _Socket)
	{
		if (this->cpuSocket != NULL)
		{
			delete[] this->cpuSocket;
			this->cpuSocket = NULL;
			this->cpuSocket = new char[strlen(_Socket) + 1];
			strcpy_s(this->cpuSocket, (strlen(_Socket) + 1), _Socket);
		}
		else
		{
			this->cpuSocket = new char[strlen(_Socket) + 1];
			strcpy_s(this->cpuSocket, (strlen(_Socket) + 1), _Socket);
		}
	}

	void setChipset(const char* _Chipset)
	{
		if (this->chipset != NULL)
		{
			delete[] this->chipset;
			this->chipset = NULL;
			this->chipset = new char[strlen(_Chipset) + 1];
			strcpy_s(this->chipset, (strlen(_Chipset) + 1), _Chipset);
		}
		else
		{
			this->chipset = new char[strlen(_Chipset) + 1];
			strcpy_s(this->chipset, (strlen(_Chipset) + 1), _Chipset);
		}
	}

	void setRamType(const char* _ramType)
	{
		if (this->ramType != NULL)
		{
			delete[] this->ramType;
			this->ramType = NULL;
			this->ramType = new char[strlen(_ramType) + 1];
			strcpy_s(this->ramType, (strlen(_ramType) + 1), _ramType);
		}
		else
		{
			this->ramType = new char[strlen(_ramType) + 1];
			strcpy_s(this->ramType, (strlen(_ramType) + 1), _ramType);
		}
	}

	void setRamSlots(int _Slots)
	{
		this->ramSlots = _Slots;
	}

	void setPcieExpressSlots(int _Slots)
	{
		this->pciExpressSlots = _Slots;
	}

	Motherboard() :PcPart() //default constructor
	{
		//cout << "Motherboard Default Constructor" << endl;
		this->chipset = NULL;
		this->cpuSocket = NULL;
		this->ramType = NULL;
		this->ramSlots = 0;
		this->pciExpressSlots = 0;
	}

	Motherboard(const char* _Manufacturer, const  char* _Model, long _Price,
		const char* _CpuSocket, const char* _Chipset, const char* _RamType, int _RamSlots,
		int _PciExpressSlots) :PcPart(_Manufacturer, _Model, _Price) //parameters constructor
	{
		//cout << "Motherboard Parameters Constructor" << endl;
		this->chipset = new char[strlen(_Chipset) + 1];
		strcpy_s(this->chipset, (strlen(_Chipset) + 1), _Chipset);
		this->cpuSocket = new char[strlen(_CpuSocket) + 1];
		strcpy_s(this->cpuSocket, (strlen(_CpuSocket) + 1), _CpuSocket);
		this->ramType = new char[strlen(_RamType) + 1];
		strcpy_s(this->ramType, (strlen(_RamType) + 1), _RamType);
		this->ramSlots = _RamSlots;
		this->pciExpressSlots = _PciExpressSlots;
	}

	Motherboard(const Motherboard &copy) :PcPart(copy) //copy constructor
	{
		//cout << "Motherboard Copy Constructor" << endl;
		if (copy.chipset != NULL)
		{
			this->chipset = new char[strlen(copy.chipset) + 1];
			strcpy_s(this->chipset, (strlen(copy.chipset) + 1), copy.chipset);
		}
		else
		{
			this->chipset = NULL;
		}
		if (copy.cpuSocket != NULL)
		{
			this->cpuSocket = new char[strlen(copy.cpuSocket) + 1];
			strcpy_s(this->cpuSocket, (strlen(copy.cpuSocket) + 1), copy.cpuSocket);
		}
		else
		{
			this->cpuSocket = NULL;
		}
		if (copy.ramType != NULL)
		{
			this->ramType = new char[strlen(copy.ramType) + 1];
			strcpy_s(this->ramType, (strlen(copy.ramType) + 1), copy.ramType);
		}
		else
		{
			this->ramType = NULL;
		}
		this->ramSlots = copy.ramSlots;
		this->pciExpressSlots = copy.pciExpressSlots;
	}

	Motherboard operator=(Motherboard &equal) //operator =
	{
		//cout << "Motherboard Operator =" << endl;
		this->setPartManufacturer(equal.getPartManufacturer());
		this->setPartModel(equal.getPartModel());
		this->setPartPrice(equal.getPartPrice());
		delete[] this->chipset;
		this->chipset = NULL;
		this->chipset = new char[strlen(equal.chipset) + 1];
		strcpy_s(this->chipset, (strlen(equal.chipset) + 1), equal.chipset);
		delete[] this->cpuSocket;
		this->cpuSocket = NULL;
		this->cpuSocket = new char[strlen(equal.cpuSocket) + 1];
		strcpy_s(this->cpuSocket, (strlen(equal.cpuSocket) + 1), equal.cpuSocket);
		delete[] this->ramType;
		this->ramType = NULL;
		this->ramType = new char[strlen(equal.ramType) + 1];
		strcpy_s(this->ramType, (strlen(equal.ramType) + 1), equal.ramType);
		this->ramSlots = equal.ramSlots;
		this->pciExpressSlots = equal.pciExpressSlots;
		return *this;
	}

	Motherboard operator++() //++ pre increment
	{
		int ramSlots = this->ramSlots;
		ramSlots += 1;
		this->setRamSlots(ramSlots);
		return *this;
	}

	Motherboard operator--() //-- pre increment
	{
		int ramSlots = this->ramSlots;
		ramSlots -= 1;
		this->setRamSlots(ramSlots);
		return *this;
	}

	Motherboard operator++(int) //++ post increment
	{
		Motherboard aux = *this;
		int ramSlots = this->ramSlots;
		ramSlots -= 1;
		this->setRamSlots(ramSlots);
		return aux;
	}

	Motherboard operator--(int) //-- post increment
	{
		Motherboard aux = *this;
		int ramSlots = this->ramSlots;
		ramSlots -= 1;
		this->setRamSlots(ramSlots);
		return aux;
	}

	explicit operator int() //cast operator long to int
	{
		return (int)this->getPartPrice();
	}

	Motherboard operator+(int _RamSlots) //binary operator + (Motherboard + int)
	{
		int ramSlots = this->ramSlots;
		ramSlots += _RamSlots;
		this->setRamSlots(ramSlots);
		return *this;
	}

	Motherboard operator-(int _RamSlots) //binary operator - (Motherboard - int)
	{
		int ramSlots = this->ramSlots;
		ramSlots -= _RamSlots;
		this->setRamSlots(ramSlots);
		return *this;
	}

	bool operator!=(Motherboard _Motherboard) //operator !=
	{
		if ((((_stricmp(this->getPartManufacturer(), _Motherboard.getPartManufacturer()) == 0)) &&
			(((_stricmp(this->getPartModel(), _Motherboard.getPartModel()) == 0)) &&
			(((_stricmp(this->chipset, _Motherboard.chipset)) == 0)) &&
				(((_stricmp(this->ramType, _Motherboard.ramType)) == 0)) &&
				(((_stricmp(this->cpuSocket, _Motherboard.cpuSocket)) == 0)))) &&
				(this->getPartPrice() == _Motherboard.getPartPrice()) &&
			(this->pciExpressSlots == _Motherboard.pciExpressSlots) &&
			(this->ramSlots == _Motherboard.ramSlots))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void compareTo(Motherboard _Motherboard) //a function to compare two objects
	{
		if ((*this != _Motherboard))
		{
			cout << "Motherboards Are Equal" << endl << endl;
		}
		else
		{
			cout << "Motherboards Are Different" << endl << endl;
		}
	}

	friend ostream& operator<<(ostream &output, Motherboard _Motherboard) //<< operator
	{
		output << "Motherboard @:" << &_Motherboard << endl;
		if (_Motherboard.getPartManufacturer() != NULL)
		{
			output << "Motherboard Manufacturer: " << _Motherboard.getPartManufacturer() << endl;
		}
		else
		{
			output << "Motherboard Manufacturer: NULL" << endl;
		}
		if (_Motherboard.getPartModel() != NULL)
		{
			output << "Motherboard Model: " << _Motherboard.getPartModel() << endl;
		}
		else
		{
			output << "Motherboard Model: NULL" << endl;
		}
		output << "Motherboard Price: " << _Motherboard.getPartPrice() << endl;
		if (_Motherboard.cpuSocket != NULL)
		{
			output << "Motherboard CPU Socket: " << _Motherboard.cpuSocket << endl;
		}
		else
		{
			output << "Motherboard CPU Socket: NULL" << endl;
		}
		if (_Motherboard.chipset != NULL)
		{
			output << "Motherboard Chipset: " << _Motherboard.chipset << endl;
		}
		else
		{
			output << "Motherboard Chipset: NULL" << endl;
		}
		if (_Motherboard.ramType != NULL)
		{
			output << "Motherboard Ram Type: " << _Motherboard.ramType << endl;
		}
		else
		{
			output << "Motherboard Ram Type: NULL" << endl;
		}
		output << "Motherboard RAM Slots: " << _Motherboard.ramSlots << endl;
		output << "Motherboard PCI Express Slots: " << _Motherboard.pciExpressSlots << endl;
		output << endl;
		return output;
	}

	void printPcPart() //method inherited from the abstract class
	{
		cout << "Motherboard @:" << this << endl;
		if (this->getPartManufacturer() != NULL)
		{
			cout << "Part Manufacturer: " << this->getPartManufacturer() << endl;
		}
		else
		{
			cout << "Part Manufacturer: NULL" << endl;
		}
		if (this->getPartModel() != NULL)
		{
			cout << "Part Model: " << this->getPartModel() << endl;
		}
		else
		{
			cout << "Part Model: NULL" << endl;
		}
		cout << "Part Price: " << this->getPartPrice() << endl;
		if (this->cpuSocket != NULL)
		{
			cout << "Motherboard CPU Socket: " << this->cpuSocket << endl;
		}
		else
		{
			cout << "Motherboard CPU Socket: NULL" << endl;
		}
		if (this->ramType != NULL)
		{
			cout << "Motherboard RAM Type: " << this->ramType << endl;
		}
		else
		{
			cout << "Motherboard RAM Type: NULL" << endl;
		}
		cout << "Motherboard Ram Slots: " << this->ramSlots << endl;
		cout << "Motherboard Pci Express Slots: " << this->pciExpressSlots << endl;
		cout << endl;
	}

	~Motherboard() //destructor
	{
		//cout << "Motherboard Destructor" << endl;
		delete[] this->chipset;
		this->chipset = NULL;
		delete[] this->cpuSocket;
		this->cpuSocket = NULL;
		delete[] this->ramType;
		this->ramType = NULL;
	}
};

Motherboard operator+(Motherboard _M1, Motherboard _M2) //operator + (Motherboard + Motherboard)
{
	int ramSlots = _M1.getRamSlots();
	ramSlots += _M2.getRamSlots();
	int pciExpressSlots = _M1.getPciExpressSlots();
	pciExpressSlots += _M2.getPciExpressSlots();
	_M1.setRamSlots(ramSlots);
	_M1.setPcieExpressSlots(pciExpressSlots);
	return _M1;
}

Motherboard operator-(Motherboard _M1, Motherboard _M2) //operator - (Motherboard + Motherboard)
{
	int ramSlots = _M1.getRamSlots();
	ramSlots -= _M2.getRamSlots();
	int pciExpressSlots = _M1.getPciExpressSlots();
	pciExpressSlots -= _M2.getPciExpressSlots();
	_M1.setRamSlots(ramSlots);
	_M1.setPcieExpressSlots(pciExpressSlots);
	return _M1;
}

class PowerSupply : public PcPart
{
private:
	char* powerSupplyType;
	float ouputPower;
	float certificationPrecentage;
public:
	char* getPowerSupplyType()
	{
		if (this->powerSupplyType != NULL)
		{
			return this->powerSupplyType;
		}
		else
		{
			return NULL;
		}
	}

	float getOuputPower()
	{
		return this->ouputPower;
	}

	float getCertificationPercentage()
	{
		return this->certificationPrecentage;
	}

	void setPowerSupplyType(const char* _Type)
	{
		if (this->powerSupplyType != NULL)
		{
			delete[] this->powerSupplyType;
			this->powerSupplyType = NULL;
			this->powerSupplyType = new char[strlen(_Type) + 1];
			strcpy_s(this->powerSupplyType, (strlen(_Type) + 1), _Type);
		}
		else
		{
			this->powerSupplyType = new char[strlen(_Type) + 1];
			strcpy_s(this->powerSupplyType, (strlen(_Type) + 1), _Type);
		}
	}

	void setOutputPower(float _Power)
	{
		this->ouputPower = _Power;
	}

	void setCertificationPercentage(float _Percentage)
	{
		this->certificationPrecentage = _Percentage;
	}

	PowerSupply() :PcPart() //default constructor
	{
		//cout << "Power Supply Default Constructor" << endl;
		this->powerSupplyType = NULL;
		this->certificationPrecentage = 0.0f;
		this->ouputPower = 0.0f;
	}

	PowerSupply(const char* _Manufacturer, const char* _Model, long _Price,
		const char* _Type, float _Power, float _CertificationPercentage) :
		PcPart(_Manufacturer, _Model, _Price) //parameters constructor
	{
		//cout << "Motherboard Parameters Constructor" < endl;
		this->powerSupplyType = new char[strlen(_Type) + 1];
		strcpy_s(this->powerSupplyType, (strlen(_Type) + 1), _Type);
		this->ouputPower = _Power;
		this->certificationPrecentage = _CertificationPercentage;
	}

	PowerSupply(const PowerSupply &copy) :PcPart(copy) //copy constructor
	{
		//cout << "Power Supply Copy Constructor" << endl;
		if (copy.powerSupplyType != NULL)
		{
			this->powerSupplyType = new char[strlen(copy.powerSupplyType) + 1];
			strcpy_s(this->powerSupplyType, (strlen(copy.powerSupplyType) + 1), copy.powerSupplyType);
		}
		else
		{
			this->powerSupplyType = NULL;
		}
		this->ouputPower = copy.ouputPower;
		this->certificationPrecentage = copy.certificationPrecentage;
	}

	PowerSupply operator=(PowerSupply& equal) //operator =
	{
		//cout << "PowerSupply Operator =" << endl;
		this->setPartManufacturer(equal.getPartManufacturer());
		this->setPartModel(equal.getPartModel());
		this->setPartPrice(equal.getPartPrice());
		delete[] this->powerSupplyType;
		this->powerSupplyType = NULL;
		this->powerSupplyType = new char[strlen(equal.powerSupplyType) + 1];
		strcpy_s(this->powerSupplyType, (strlen(equal.powerSupplyType) + 1), equal.powerSupplyType);
		this->ouputPower = equal.ouputPower;
		this->certificationPrecentage = equal.certificationPrecentage;
		return *this;
	}

	bool operator>(PowerSupply _PowerSupply) //binary operator >
	{
		if (((this->ouputPower >= _PowerSupply.ouputPower) &&
			(this->certificationPrecentage >= _PowerSupply.certificationPrecentage)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	PowerSupply operator++() //++ pre increment
	{
		float certPercentage = this->certificationPrecentage;
		certPercentage += 5;
		this->certificationPrecentage = certPercentage;
		return *this;
	}

	PowerSupply operator--() //-- pre increment
	{
		float certPercentage = this->certificationPrecentage;
		certPercentage -= 5;
		this->certificationPrecentage = certPercentage;
		return *this;
	}

	PowerSupply operator++(int) //++ post increment
	{
		PowerSupply aux = *this;
		float outputPower = this->ouputPower;
		ouputPower += 50;
		this->setOutputPower(ouputPower);
		return aux;
	}

	PowerSupply operator--(int) //-- post increment
	{
		PowerSupply aux = *this;
		float outputPower = this->ouputPower;
		ouputPower -= 50;
		this->setOutputPower(ouputPower);
		return aux;
	}

	PowerSupply operator+(float _Power) //binary operator + (PowerSupply + float)
	{
		float power = this->ouputPower;
		power += _Power;
		this->ouputPower = power;
		return *this;
	}

	PowerSupply operator-(float _Power) //binary operator - (PowerSupply - float)
	{
		float power = this->ouputPower;
		power -= _Power;
		this->ouputPower = power;
		return *this;
	}

	bool operator!= (PowerSupply _Ps) // binary operator !=
	{
		if ((_stricmp(this->getPartManufacturer(), _Ps.getPartManufacturer()) == 0) &&
			(_stricmp(this->getPartModel(), _Ps.getPartModel()) == 0) &&
			(this->getPartPrice() == _Ps.getPartPrice()) &&
			(_stricmp(this->powerSupplyType, _Ps.powerSupplyType) == 0) &&
			(this->certificationPrecentage == _Ps.certificationPrecentage) &&
			(this->ouputPower == _Ps.ouputPower))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend ostream& operator<<(ostream &output, PowerSupply _PowerSupply) //<< operator
	{
		output << "Motherboard @:" << &_PowerSupply << endl;
		if (_PowerSupply.getPartManufacturer() != NULL)
		{
			output << "Power Supply Manufacturer: " << _PowerSupply.getPartManufacturer() << endl;
		}
		else
		{
			output << "Power Supply Manufacturer: NULL" << endl;
		}
		if (_PowerSupply.getPartModel() != NULL)
		{
			output << "Power Supply Model: " << _PowerSupply.getPartModel() << endl;
		}
		else
		{
			output << "Power Supply Model: NULL" << endl;
		}
		output << "Power Supply Price: " << _PowerSupply.getPartPrice() << endl;
		if (_PowerSupply.powerSupplyType != NULL)
		{
			output << "Power Supply Type: " << _PowerSupply.powerSupplyType << endl;
		}
		else
		{
			output << "Power Supply Type: NULL" << endl;
		}
		output << "Power Supply Power: " << _PowerSupply.ouputPower << endl;
		output << "Power Supply Certification: " << _PowerSupply.certificationPrecentage << endl;
		output << endl;
		return output;
	}

	void printPcPart() //method inherited from the abstract class
	{
		cout << "Power Supply @:" << this << endl;
		if (this->getPartManufacturer() != NULL)
		{
			cout << "Part Manufacturer: " << this->getPartManufacturer() << endl;
		}
		else
		{
			cout << "Part Manufacturer: NULL" << endl;
		}
		if (this->getPartModel() != NULL)
		{
			cout << "Part Model: " << this->getPartModel() << endl;
		}
		else
		{
			cout << "Part Model: NULL" << endl;
		}
		cout << "Part Price: " << this->getPartPrice() << endl;
		if (this->powerSupplyType != NULL)
		{
			cout << "Power Supply Type: " << this->powerSupplyType << endl;
		}
		else
		{
			cout << "Power Supply Type: NULL" << endl;
		}
		cout << "Power Supply Ouput Power: " << this->ouputPower << endl;
		cout << "Power Supply Type Certification Percentage: " << this->certificationPrecentage << endl;
		cout << endl;
	}

	friend void compareTwoPowerSupply(PowerSupply _Ps1, PowerSupply _Ps2);

	~PowerSupply()
	{
		//cout << "Power Supply Destructor" << endl;
		delete[] this->powerSupplyType;
		this->powerSupplyType = NULL;
	}
};

PowerSupply operator+(PowerSupply _Ps1, PowerSupply _Ps2) //operator + (PowerSupply + PowerSupply)
{
	float power = _Ps1.getOuputPower();
	power += _Ps2.getOuputPower();
	_Ps1.setOutputPower(power);
	return _Ps1;
}

PowerSupply operator-(PowerSupply _Ps1, PowerSupply _Ps2) //operator - (PowerSupply - PowerSupply)
{
	float power = _Ps1.getOuputPower();
	power -= _Ps2.getOuputPower();
	_Ps1.setOutputPower(power);
	return _Ps1;
}

PowerSupply operator+ (float _Power, PowerSupply _Ps)
{
	float power = _Ps.getOuputPower();
	power += _Power;
	_Ps.setOutputPower(power);
	return _Ps;
}

void compareTwoPowerSupply(PowerSupply _Ps1, PowerSupply _Ps2)
{
	if (_Ps1 > _Ps2)
	{
		cout << "Power Supply 1 Is Better Than Power Supply 2" << endl;
	}
	else
	{
		cout << "Power Supply 2 Is Better Than Power Supply 1" << endl;
	}
}

class Computer
{
private:
	Motherboard * motherboard;
	CPU* cpu;
	RAM* ram;
	PowerSupply* powerSupply;
public:
	Motherboard * getMotherboard()
	{
		if (this->motherboard != NULL)
		{
			return this->motherboard;
		}
		else
		{
			return NULL;
		}
	}

	CPU* getCpu()
	{
		if (this->cpu != NULL)
		{
			return this->cpu;
		}
		else
		{
			return NULL;
		}
	}

	RAM* getRam()
	{
		if (this->ram != NULL)
		{
			return this->ram;
		}
		else
		{
			return NULL;
		}
	}

	PowerSupply* getPowerSupply()
	{
		if (this->powerSupply != NULL)
		{
			return this->powerSupply;
		}
		else
		{
			return NULL;
		}
	}

	void setMotherboard(Motherboard _Motherboard)
	{
		if (this->motherboard != NULL)
		{
			delete this->motherboard;
			this->motherboard = NULL;
			this->motherboard = new Motherboard(_Motherboard);
		}
		else
		{
			this->motherboard = new Motherboard(_Motherboard);
		}
	}

	void setCpu(CPU _Cpu)
	{
		if (this->cpu != NULL)
		{
			delete this->cpu;
			this->cpu = NULL;
			this->cpu = new CPU(_Cpu);
		}
		else
		{
			this->cpu = new CPU(_Cpu);
		}
	}

	void setRam(RAM _Ram)
	{
		if (this->ram != NULL)
		{
			delete this->ram;
			this->ram = NULL;
			this->ram = new RAM(_Ram);
		}
		else
		{
			this->ram = new RAM(_Ram);
		}
	}

	void setPowerSupply(PowerSupply _PowerSupply)
	{
		if (this->powerSupply != NULL)
		{
			delete this->powerSupply;
			this->powerSupply = NULL;
			this->powerSupply = new PowerSupply(_PowerSupply);
		}
		else
		{
			this->powerSupply = new PowerSupply(_PowerSupply);
		}
	}

	Computer() //default constructor
	{
		//cout << "Computer Default Constructor" << endl;
		this->cpu = NULL;
		this->motherboard = NULL;
		this->powerSupply = NULL;
		this->ram = NULL;
	}

	Computer(Motherboard _Motherboard, CPU _Cpu, RAM _Ram, PowerSupply _PowerSupply) //parameters constructor
	{
		//cout << "Computer Parameters Constructor" << endl;
		this->motherboard = new Motherboard(_Motherboard);
		this->cpu = new CPU(_Cpu);
		this->powerSupply = new PowerSupply(_PowerSupply);
		this->ram = new RAM(_Ram);
	}

	Computer(const Computer &copy) //copy constructor
	{
		//cout << "Computer Copy Constructor" << endl;
		this->cpu = new CPU(*copy.cpu);
		this->motherboard = new Motherboard(*copy.motherboard);
		this->powerSupply = new PowerSupply(*copy.powerSupply);
		this->ram = new RAM(*copy.ram);
	}

	Computer operator=(Computer &equal)
	{
		//cout << "Computer Operator =" << endl;
		delete this->cpu;
		this->cpu = NULL;
		this->cpu = new CPU(*equal.cpu);
		delete this->ram;
		this->ram = NULL;
		this->ram = new RAM(*equal.ram);
		delete this->powerSupply;
		this->powerSupply = NULL;
		this->powerSupply = new PowerSupply(*equal.powerSupply);
		delete this->motherboard;
		this->motherboard = NULL;
		this->motherboard = new Motherboard(*equal.motherboard);
		return *this;
	}

	bool operator!=(Computer _Computer) //binary operator !=
	{
		if ((this->cpu->operator!=(*_Computer.cpu) == true) &&
			((this->ram->operator!=(*_Computer.ram) == true) &&
			((this->powerSupply->operator!=(*_Computer.powerSupply) == true) &&
				((this->motherboard->operator!=(*_Computer.motherboard) == true)))))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	char* pcSpecs()
	{
		ostringstream ostringStream;
		string mbManufacturer = this->motherboard->getPartManufacturer() + string(" ");
		string mbModel = this->motherboard->getPartModel() + string(" ");
		ostringStream << this->motherboard->getPartPrice();
		string mbPrice = ostringStream.str() + string(" ");
		ostringStream.clear();
		ostringStream.str("");
		string mbCpuSocket = this->motherboard->getCpuSocket() + string(" ");
		string mbChipset = this->motherboard->getChipset() + string(" ");
		string mbRamType = this->motherboard->getRamType() + string(" ");
		ostringStream << this->motherboard->getRamSlots();
		string mbRamSlots = ostringStream.str() + string(" ");
		ostringStream.clear();
		ostringStream.str("");
		string cpuManufacturer = this->cpu->getPartManufacturer() + string(" ");
		string cpuModel = this->cpu->getPartModel() + string(" ");
		ostringStream << this->cpu->getPartPrice();
		string cpuPrice = ostringStream.str() + string(" ");
		ostringStream.clear();
		ostringStream.str("");
		string cpuSocket = this->cpu->getCpuSocket() + string(" ");
		ostringStream << this->cpu->getCpuFrequency();
		string cpuFrequency(ostringStream.str());
		ostringStream.clear();
		ostringStream.str("");
		ostringStream << this->cpu->getCpuCores();
		string cpuCores = ostringStream.str() + string(" ");
		ostringStream.clear();
		ostringStream.str("");
		ostringStream << this->cpu->getCpuThreads();
		string cpuThreads = ostringStream.str() + string(" ");
		ostringStream.clear();
		ostringStream.str("");
		string ramManufacturer = this->ram->getPartManufacturer() + string(" ");
		string ramModel = this->ram->getPartModel() + string(" ");
		ostringStream << this->ram->getPartPrice();
		string ramPrice = ostringStream.str() + string(" ");
		ostringStream.clear();
		ostringStream.str("");
		string ramType = this->ram->getRamType() + string(" ");
		ostringStream << this->ram->getRamFrequency();
		string ramFrequency = ostringStream.str() + string(" ");
		ostringStream.clear();
		ostringStream.str("");
		ostringStream << this->ram->getRamSize();
		string ramSize = ostringStream.str() + string(" ");
		ostringStream.clear();
		ostringStream.str("");
		string powerSupplyManufacturer = this->powerSupply->getPartManufacturer() + string(" ");
		string powerSupplyModel = this->powerSupply->getPartModel() + string(" ");
		ostringStream << this->powerSupply->getPartPrice();
		string powerSupplyPrice = ostringStream.str() + string(" ");
		ostringStream.clear();
		ostringStream.str("");
		string powerSupplyType = this->powerSupply->getPowerSupplyType() + string(" ");
		ostringStream << this->powerSupply->getOuputPower();
		string powerSuppluOutputPower = ostringStream.str() + string(" ");
		ostringStream.clear();
		ostringStream.str("");
		ostringStream << this->powerSupply->getCertificationPercentage();
		string powerSupplyCertificationPercentage = ostringStream.str();
		ostringStream.clear();
		ostringStream.str("");
		string specs = mbManufacturer + mbModel + mbPrice + mbCpuSocket + mbChipset +
			mbCpuSocket + mbRamSlots + mbRamType + cpuManufacturer + cpuModel +
			cpuPrice + cpuSocket + cpuFrequency + cpuCores + cpuThreads +
			ramManufacturer + ramModel + ramPrice + ramFrequency + ramType +
			ramType + powerSupplyManufacturer + powerSupplyModel +
			powerSupplyPrice + powerSupplyType + powerSuppluOutputPower +
			powerSupplyCertificationPercentage;
		char* value = new char[specs.length() + 1];
		strcpy_s(value, (specs.length() + 1), specs.c_str());
		return value;
	}

	friend ostream& operator<< (ostream& output, Computer &_Computer)
	{
		cout << "Computer @:" << &_Computer << endl;
		if (_Computer.motherboard != NULL)
		{
			_Computer.motherboard->printPcPart();
		}
		else
		{
			output << "Motherboard: NULL" << endl;
		}
		if (_Computer.cpu != NULL)
		{
			_Computer.cpu->printPcPart();
		}
		else
		{
			output << "CPU: NULL" << endl;
		}
		if (_Computer.ram != NULL)
		{
			_Computer.ram->printPcPart();
		}
		else
		{
			output << "RAM: NULL" << endl;
		}
		if (_Computer.powerSupply != NULL)
		{
			_Computer.powerSupply->printPcPart();
		}
		else
		{
			output << "Power Supply: NULL" << endl;
		}
		return output;
	}

	~Computer() //destructor
	{
		//cout << "Computer Destructor" << endl;
		delete this->cpu;
		this->cpu = NULL;
		delete this->motherboard;
		this->motherboard = NULL;
		delete this->ram;
		this->ram = NULL;
		delete this->powerSupply;
		this->powerSupply = NULL;
	}
};

class Cipher
{
private:
	unsigned char hash[SHA256_DIGEST_LENGTH];
	char* messageContent;
	char* encryptedMessage;
	char* decryptedMessage;
	char* encryptionKey;

	char* KeyGenerator() //function for generating DES key
	{
		char* key = new char[8];
		static const char alphanum[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		for (int i = 0; i < 8; ++i)
		{
			key[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
		}
		return key;
	}
public:

	char* getMessageContent()
	{
		return this->messageContent;
	}

	char* getEncryptedMessage()
	{
		return this->encryptedMessage;
	}

	char* getDecryptedMessage()
	{
		return this->decryptedMessage;
	}

	Cipher() //default constructor
	{
		this->messageContent = NULL;
		this->encryptedMessage = NULL;
		this->decryptedMessage = NULL;
		this->encryptionKey = NULL;
	}

	Cipher(const char* _MessageContent) //parameters constructor
	{
		this->messageContent = new char[strlen(_MessageContent) + 1];
		strcpy_s(this->messageContent, (strlen(_MessageContent) + 1), _MessageContent);
		this->encryptionKey = KeyGenerator();
		this->encryptedMessage = NULL;
		this->decryptedMessage = NULL;
	}

	Cipher(const Cipher &copy) //copy constructor
	{
		this->messageContent = new char[strlen(copy.messageContent) + 1];
		strcpy_s(this->messageContent, (strlen(copy.messageContent) + 1), copy.messageContent);
		this->encryptedMessage = new char[strlen(copy.encryptedMessage) + 1];
		strcpy_s(this->encryptedMessage, (strlen(copy.encryptedMessage) + 1), copy.encryptedMessage);
		this->decryptedMessage = new char[strlen(copy.decryptedMessage) + 1];
		strcpy_s(this->decryptedMessage, (strlen(copy.decryptedMessage) + 1), copy.decryptedMessage);
		this->encryptionKey = new char[strlen(copy.encryptionKey) + 1];
		strcpy_s(this->encryptionKey, (strlen(copy.encryptionKey) + 1), copy.encryptionKey);
	}

	Cipher operator=(Cipher &equal) //operator =
	{
		delete[] this->messageContent;
		this->messageContent = NULL;
		this->messageContent = new char[strlen(equal.messageContent) + 1];
		strcpy_s(this->messageContent, (strlen(equal.messageContent) + 1), equal.messageContent);
		delete[] this->encryptedMessage;
		this->encryptedMessage = NULL;
		this->encryptedMessage = new char[strlen(equal.encryptedMessage) + 1];
		strcpy_s(this->encryptedMessage, (strlen(equal.encryptedMessage) + 1), equal.encryptedMessage);
		delete[] this->decryptedMessage;
		this->decryptedMessage = NULL;
		this->decryptedMessage = new char[strlen(equal.decryptedMessage) + 1];
		strcpy_s(this->decryptedMessage, (strlen(equal.decryptedMessage) + 1), equal.decryptedMessage);
		delete[] this->encryptionKey;
		this->encryptionKey = NULL;
		this->encryptionKey = new char[strlen(equal.encryptionKey) + 1];
		strcpy_s(this->encryptionKey, (strlen(equal.encryptionKey) + 1), equal.encryptionKey);
		return *this;
	}

	void computeHash() //function for computting hash
	{
		if (this->messageContent != NULL)
		{
			SHA256_CTX sha256;
			SHA256_Init(&sha256);
			char* Buffer = this->messageContent;
			int MessageChunk = 8;
			int MessageLength = strlen(this->messageContent);
			while (MessageLength > 0)
			{
				if (MessageLength > MessageChunk)
				{
					SHA256_Update(&sha256, Buffer, MessageChunk);
				}
				else
				{
					SHA256_Update(&sha256, Buffer, MessageLength);
				}
				Buffer += MessageChunk;
				MessageLength -= MessageChunk;
			}
			SHA256_Final(this->hash, &sha256);
		}
		else
		{
			cout << "Content Is NULL" << endl;
			this->messageContent = new char[1];
			strcpy_s(this->messageContent, 1, "");
			SHA256_CTX sha256;
			SHA256_Init(&sha256);
			SHA256_Update(&sha256, this->messageContent, strlen(this->messageContent));
			SHA256_Final(this->hash, &sha256);
		}
	}

	void printHash() //function to print hash
	{
		cout << "SHA-256 For Input :" << endl << this->messageContent << endl << "Is:" << endl;
		cout << "SHA-256:";
		for (int indexHash = 0; indexHash < SHA256_DIGEST_LENGTH; indexHash++)
		{
			cout << hex << setw(2) << setfill('0') << (int)this->hash[indexHash];
		}
		cout << endl;
	}

	void DESencrypt() //function to encrypt with DES
	{
		unsigned char* Res;
		int n = 0;
		DES_cblock Key2;
		DES_key_schedule schedule;
		Res = new unsigned char[strlen(this->messageContent) + 1];
		memcpy(Key2, this->encryptionKey, 8);
		DES_set_odd_parity(&Key2);
		if (DES_set_key_checked(&Key2, &schedule))
		{
			cout << "Key Error!" << endl;
			delete[] Res;
			Res = NULL;
		}
		else
		{
			DES_cfb64_encrypt((unsigned char*)this->messageContent, (unsigned char*)Res, (strlen(this->messageContent) + 1), &schedule, &Key2, &n, DES_ENCRYPT);
			this->encryptedMessage = new char[strlen((char*)Res) + 1];
			strcpy_s(this->encryptedMessage, (strlen((char*)Res) + 1), (char*)Res);
		}
	}

	void DESdecrypt() //fucntion to decrypt with DES
	{
		unsigned char* Res;
		int n = 0;
		DES_cblock Key2;
		DES_key_schedule schedule;
		Res = new unsigned char[strlen(this->messageContent) + 1];
		memcpy(Key2, this->encryptionKey, 8);
		DES_set_odd_parity(&Key2);
		if (DES_set_key_checked(&Key2, &schedule))
		{
			cout << "Key Error!";
			delete[] Res;
			Res = NULL;
		}
		else
		{
			DES_cfb64_encrypt((unsigned char *)this->encryptedMessage, (unsigned char *)Res, (strlen(this->messageContent) + 1), &schedule, &Key2, &n, DES_DECRYPT);
			this->decryptedMessage = new char[strlen((char*)Res) + 1];
			strcpy_s(this->decryptedMessage, (strlen((char*)Res) + 1), (char*)Res);
		}
	}

	~Cipher() //destructor
	{
		delete[] this->messageContent;
		this->messageContent = NULL;
		delete[] this->encryptedMessage;
		this->encryptedMessage = NULL;
	}
};

void testCPU()
{
	cout << "~~~ CPU Default Constructor Test ~~~" << endl;
	CPU cpu1;
	cout << "~~~ CPU Operator << Test ~~~" << endl;
	cout << cpu1;
	cout << "~~~ CPU Parameters Constructor Test ~~~" << endl;
	CPU cpu2("Intel", "Core I7 6700K", 1450l, "1151v1", 4000.0f, 4, 8);
	cout << "~~~ CPU printPcPart() Test ~~~" << endl;
	cpu2.printPcPart();
	cout << "~~~ CPU Copy Constructor Test ~~~" << endl;
	CPU cpu3 = cpu2;
	cout << "~~~ CPU printPcPart() Test ~~~" << endl;
	cpu3.printPcPart();
	cout << "~~~ CPU Operator = Test ~~~" << endl;
	cpu1 = cpu3;
	cout << "~~~ CPU printPcPart() Test ~~~" << endl;
	cpu1.printPcPart();
	cout << "~~~ CPU Operator + (CPU + long) Test ~~~" << endl;
	cpu1 + 34l;
	cout << "~~~ CPU Operator << Test ~~~" << endl;
	cout << cpu1;
	cout << "~~~ CPU Operator + (long + CPU) Test ~~~" << endl;
	34l + cpu1;
	cout << "~~~ CPU printPcPart() Test ~~~" << endl;
	cout << "~~~ CPU Operator + (CPU + CPU) ~~~" << endl;
	CPU cpu4 = cpu2 + cpu3;
	cout << cpu4;
	cout << "~~~ CPU printPcPart() Test ~~~" << endl;
	cpu4.printPcPart();
	cout << "~~~CPU Operator != Test ~~~" << endl;
	if (cpu4 != cpu1)
	{
		cout << "CPU's Are Same" << endl;
	}
	else
	{
		cout << "CPU's Are Different" << endl;
	}
	cout << "~~~ CPU Operator ++ Pre Increment Test ~~~" << endl;
	++cpu1;
	cout << "~~~ CPU Operator << Test ~~~" << endl;
	cout << cpu1;
	cout << "~~~ CPU Operator ++ Post Increment Test ~~~" << endl;
	cpu1++;
	cout << "~~~ CPU Operator << Test ~~~" << endl;
	cout << cpu1;
	cout << "~~~ CPU Operator (int) ~~~" << endl;
	cpu1.setPartPrice(1450.5l);
	int castedPrice = (int)cpu1;
	cout << "Price: " << castedPrice << endl;
}

void testRAM()
{
	cout << "~~~ RAM Default Constructor Test ~~~" << endl;
	RAM ram1;
	cout << "~~~ RAM Operator << Test ~~~" << endl;
	cout << ram1;
	cout << "~~~ CPU Parameters Constructor Test ~~~" << endl;
	RAM ram2("Corsair", "Vengeance LPX", 450l, "DDR-4", 3200, 8);
	cout << "~~~ RAM printPcPart() Test ~~~" << endl;
	ram2.printPcPart();
	cout << "~~~ RAM Copy Constructor Test ~~~" << endl;
	RAM ram3 = ram2;
	cout << "~~~ RAM printPcPart() Test ~~~" << endl;
	ram3.printPcPart();
	cout << "~~~ RAM Operator = Test ~~~" << endl;
	ram1 = ram3;
	cout << "~~~ RAM printPcPart() Test ~~~" << endl;
	ram1.printPcPart();
	cout << "~~~ RAM Operator + (RAM + float) Test ~~~" << endl;
	ram1 + 34.3f;
	cout << "~~~ RAM Operator << Test ~~~" << endl;
	cout << ram1;
	cout << "~~~ RAM Operator - (RAM - float) Test ~~~" << endl;
	ram1 - 34.3f;
	cout << "~~~ RAM Operator << Test ~~~" << endl;
	cout << ram1;
	cout << "~~~ RAM Operator + (float + RAM) Test ~~~" << endl;
	float frequency = 34.5f + ram1;
	cout << "~~~ RAM Frequency Test ~~~" << endl;
	cout << "Frequency: " << frequency << endl;
	cout << "~~~ RAM Operator + (RAM + RAM) ~~~" << endl;
	RAM ram4 = ram2 + ram3;
	cout << ram4;
	cout << "~~~ RAM Operator != Test ~~~" << endl;
	if (ram4 != ram1)
	{
		cout << "RAM's Are Same" << endl;
	}
	else
	{
		cout << "RAM's Are Different" << endl;
	}
	cout << "~~~ RAM Operator -- Pre Increment Test ~~~" << endl;
	--ram1;
	cout << "~~~ RAM Operator << Test ~~~" << endl;
	cout << ram1;
	cout << "~~~ RAM Operator -- Post Increment Test ~~~" << endl;
	ram1--;
	cout << "~~~ RAM Operator << Test ~~~" << endl;
	cout << ram1;
	cout << "~~~ RAM Operator (int) ~~~" << endl;
	ram1.setRamFrequency(3333.3f);
	int castedFrequency = (int)ram1;
	cout << "Frequency: " << castedFrequency << endl;
	RAM ram5("Kingston", "HyperX", 500l, "DDR-4", 2666.0f, 4);
	RAM ram6("Kingmax", "Value RAM", 320l, "DDR-3", 1866, 4);
	cout << "~~~ Ram Operator - (RAM - RAM) Test ~~~" << endl;
	cout << "~~~ RAM Operator << Test ~~~" << endl;
	RAM ram7 = ram5 - ram6;
	cout << ram7;
	cout << "~~~ RAM Operator + (float - RAM) Test ~~~" << endl;
	float freqMinus = 333 + ram7;
	cout << "FreqAdd: " << freqMinus << endl;
	cout << "~~~ RAM Operator - (float - RAM)" << endl;
	float freqAdd = 3200 - ram3;
	cout << "FreqMinus: " << freqMinus << endl;
}

void testMotherboard()
{
	cout << "~~~ Motherboard Default Constructor Test ~~~" << endl;
	Motherboard mb1;
	cout << "~~~ Motherboard Operator << Test ~~~" << endl;
	cout << mb1;
	cout << "~~~ Motherboard Parameters Constructor Test ~~~" << endl;
	Motherboard mb2("ASUS", "Z170 Pro Gaming", 450l, "1151v1", "Z170", "DDR-4", 4, 3);
	cout << "~~~ Motherboard printPcPart() Test ~~~" << endl;
	mb2.printPcPart();
	cout << "~~~ Motherboard Copy Constructor Test ~~~" << endl;
	Motherboard mb3 = mb2;
	cout << "~~~ Motherboard printPcPart() Test ~~~" << endl;
	mb2.printPcPart();
	cout << "~~~ Motherboard Operator = Test ~~~" << endl;
	mb1 = mb3;
	cout << "~~~ Motherboard printPcPart() Test ~~~" << endl;
	mb1.printPcPart();
	cout << "~~~ Motherboard Operator + (Motherboard + float) Test ~~~" << endl;
	mb1 + 2;
	cout << "~~~ Motherboard Operator << Test ~~~" << endl;
	cout << mb1;
	cout << "~~~ Motherboard Operator - (Motherboard - float) Test ~~~" << endl;
	mb1 - 2;
	cout << "~~~ Motherboard Operator << Test ~~~" << endl;
	cout << mb1;
	cout << "~~~ Motherboard Operator + (Motherboard + Motherboard) ~~~" << endl;
	Motherboard mb4 = mb2 + mb3;
	cout << mb4;
	cout << "~~~ Motherboard Operator != Test ~~~" << endl;
	if (mb4 != mb1)
	{
		cout << "Motherboard's Are Same" << endl;
	}
	else
	{
		cout << "Motherboard's Are Different" << endl;
	}
	cout << "~~~ Motherboard Operator -- Pre Increment Test ~~~" << endl;
	--mb1;
	cout << "~~~ Motherboard Operator << Test ~~~" << endl;
	cout << mb1;
	cout << "~~~ Motherboard Operator -- Post Increment Test ~~~" << endl;
	mb1--;
	cout << "~~~ Motherboard Operator << Test ~~~" << endl;
	cout << mb1;
	cout << "~~~ Motherboard Operator (int) ~~~" << endl;
	mb1.setPartPrice(3333.3f);
	int castedPrice = (int)mb1;
	cout << "Price: " << castedPrice << endl;
	Motherboard mb5("Gigabyte", "Z370 Gaming", 500l, "1151v2", "Z370", "DDR-4", 4, 3);
	Motherboard mb6("MSI", "Z270 Aura", 320l, "1151v1", "Z270", "DDR-4", 4, 2);
	cout << "~~~ Motherboard Operator - (Motherboard - Motherboard) Test ~~~" << endl;
	cout << "~~~ Motherboard Operator << Test ~~~" << endl;
	Motherboard mb7 = mb5 - mb6;
	cout << mb7;
	cout << "~~~ Motherboard Operator + (Motherboard + Motherboard) Test ~~~" << endl;
	Motherboard mb8 = mb5 + mb7;
	cout << "~~~ Motherboard PrinPcPart Test ~~~" << endl;
	cout << mb8;
}

void testPowerSupply()
{
	cout << "~~~ PowerSupply Default Constructor Test ~~~" << endl;
	PowerSupply p1 = PowerSupply();
	cout << "~~~ PowerSupply PrinPcPart Test ~~~" << endl;
	p1.printPcPart();
	cout << "~~~ PowerSupply Parameters Constructor Test ~~~" << endl;
	PowerSupply p2 = PowerSupply("Sirtec", "EP-750", 350l, "ATX 2.2", 750.0f, 80.0f);
	cout << "~~~ PowerSupply Operator << ~~~" << endl;
	cout << p2;
	cout << "~~~ PowerSupply Setters Test ~~~" << endl;
	p1.setPartManufacturer("Corsair");
	p1.setPartModel("CX-750");
	p1.setPartPrice(800l);
	p1.setOutputPower(800.0f);
	p1.setPowerSupplyType("ATX 2.3");
	p1.setCertificationPercentage(95);
	cout << "~~~ PowerSupply Operator << Test ~~~" << endl;
	cout << p1;
	cout << "~~~ PowerSupply Operator = Test" << endl;
	cout << "~~~ PowerSupply Copy Constructor Test ~~~" << endl;
	PowerSupply p3(p1);
	cout << "~~~ PowerSupply printPcPart Test ~~~" << endl;
	p3.printPcPart();
	cout << "~~~ PowerSupply compareTwoPowerSupply Test ~~~" << endl;
	compareTwoPowerSupply(p1, p2);
	cout << "~~~ PowerSupply Operator ++ Pre Test ~~~" << endl;
	++p1;
	cout << "~~~ PowerSupply printPcPart Test ~~~" << endl;
	p1.printPcPart();
	cout << "~~~ PowerSupply Operator ++ Post Test~~~" << endl;
	p1++;
	cout << "~~~ PowerSupply Operator << Test ~~~" << endl;
	cout << p1;
	cout << "~~~ PowerSupply + (PowerSupply + PowerSupply)" << endl;
	PowerSupply p4 = p1 + p2;
	cout << "~~~ PowerSupply Operator << Test ~~~" << endl;
	cout << p4;
	cout << "~~~ PowerSupply Operator + (PowerSupply + float)" << endl;
	cout << p2 + 45;
	cout << "~~~ PowerSupply Operator + (float + PowerSupply)" << endl;
	cout << 45 + p2;
	if (p1 != p4)
	{
		cout << "PSU's Are Same" << endl;
	}
	else
	{
		cout << "PSU's Are Diffrent" << endl;
	}
}

void testComputer()
{
	cout << "~~~ Computer Default Constructor Test ~~~" << endl;
	Computer com1;
	cout << "~~~ Computer Operator << Test ~~~" << endl;
	cout << com1;
	Motherboard motherboard1 = Motherboard("ASUS", "Z170 Pro Gaming", 850l, "1151v1", "Z170", "DDR-4", 4, 3);
	CPU cpu1 = CPU("Intel", "Core I7 6700K", 1850l, "1151v1", 4000.0f, 4, 8);
	RAM ram1 = RAM("Corsair", "Vengeance LPX", 1000l, "DDR-4", 3000, 32);
	PowerSupply powersupply1 = PowerSupply("Sirtec", "Element Smart EP-750s", 350l, "ATX 2.2", 750.0f, 80);
	cout << "~~~ Computer Setters Test ~~~" << endl;
	Computer com2 = Computer();
	com2.setMotherboard(motherboard1);
	com2.setCpu(cpu1);
	com2.setRam(ram1);
	com2.setPowerSupply(powersupply1);
	cout << "~~~ Computer Operator << Test ~~~" << endl;
	cout << com2;
	Motherboard motherboard2 = Motherboard("MSI", "Z270 Gaming", 1000l, "1151v2", "Z270", "DDR-4", 4, 2);
	CPU cpu2 = CPU("Intel", "Core I7 8700K", 2250l, "1151v2", 4200.0f, 8, 16);
	RAM ram2 = RAM("Kingston", "HyperX Fury Red", 1300, "DDR-4", 3333, 64);
	PowerSupply powersupply2 = PowerSupply("Corsair", "Builder Series CX-750", 350l, "ATX 2.3", 870.0f, 95);
	Computer com3 = Computer(motherboard2, cpu2, ram2, powersupply2);
	com3 = com2;
	cout << "~~~ Computer Operator << Test ~~~" << endl;
	cout << com2 << endl;
	com1.setCpu(cpu1);
	com1.setRam(ram2);
	com1.setMotherboard(motherboard2);
	com1.setPowerSupply(powersupply1);
	if (com1 != com2)
	{
		cout << "Computers's Are Same" << endl;
	}
	else
	{
		cout << "Computer's Are Different" << endl;
	}
	const char* toString = com3.pcSpecs();

	Cipher c = Cipher(toString);
	c.computeHash();
	c.printHash();
	c.DESencrypt();
	cout << "DES Encrypted: ";
	cout << c.getEncryptedMessage() << endl;
	c.DESdecrypt();
	cout << "Decrypted DES: ";
	cout << c.getDecryptedMessage() << endl;
}

void main()
{
	testCPU();
	testRAM();
	testMotherboard();
	testPowerSupply();
	testComputer();
	system("pause");
}