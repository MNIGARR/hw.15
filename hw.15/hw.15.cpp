#include<iostream>
#include<stack>
using namespace std;

class Engine {
public:
	string engineNo;
	string company;
	double volume;
	Engine() {}
	Engine(string engineNo, string company, double volume) {
		this->engineNo = engineNo;
		this->company = company;
		this->volume = volume;
	}

	void Show() {
		cout << "Engine company: " << company << "\nEngine No: " << engineNo << "\nEngine Volume: " << volume << endl;
	}
};

class Vehicle {
public:
	int id;
	string vendor;
	string model;
	Engine engine;

	//Vehicle() {}
	Vehicle(int id, string vendor, string model, Engine engine) {
		this->id = id;
		this->vendor = vendor;
		this->model = model;
		this->engine = engine;
	}
	virtual void Show() {
		cout << "Id: " << id << "\nVendor: " << vendor << "\nModel: " << model << "\n";
		engine.Show();
	}
};

class Car : public Vehicle {
public:
	bool hasSpoiler;
	Car(int id, string vendor, string model, Engine engine, bool hasSpoiler) : Vehicle(id, vendor, model, engine) {
		this->hasSpoiler = hasSpoiler;
	}
	void Show() {
		cout << "\tCar\n";
		Vehicle::Show();
		cout << "Spoiler: " << (hasSpoiler ? "Has" : "Has not") << "\n\n";
	}
};

class Ship : public Vehicle {
public:
	bool hasSail;
	Ship(int id, string vendor, string model, Engine engine, bool hasSail) : Vehicle(id, vendor, model, engine) {
		this->hasSail = hasSail;
	}
	void Show() {
		cout << "\tShip\n";
		Vehicle::Show();
		cout << "Sail: " << (hasSail ? "has" : "has not") << "\n\n";
	}
};

class Airplane : public Vehicle {
	int engineCount;
	int passengersCapacity;

	Airplane(int id, string vendor, string model, Engine engine, int engineCount, int passengersCapacity) : Vehicle(id, vendor, model, engine) {
		this->engineCount = engineCount;
	}
	void Show() {
		cout << "\tAirplane\n";
		Vehicle::Show();
		cout << "Engine count: " << engineCount << "\nCapacity of passengers: " << passengersCapacity << "\n\n";
	}
};

class VehicleDepo {
public:
	stack<Vehicle*> vehicles;

	void AddVehicle(Vehicle* vehicle) {
		vehicles.push(vehicle);
	}
	void ShowAllVehicles() {
		while (!vehicles.empty()) {
			vehicles.top()->Show();
			vehicles.pop();
		}
	}
};

void main() {
	VehicleDepo* vehicleDepo = new VehicleDepo();
	vehicleDepo->AddVehicle(new Car(102, "mini", "cooper", Engine("bmw123", "bmw", 1.9), true));
	vehicleDepo->AddVehicle(new Car(101, "lada", "vaz2107", Engine("123", "lada", 1.6), false));
	vehicleDepo->AddVehicle(new Ship(10, "yamaha", "SX220", Engine("TWIN TR-1 HIGH OUTPUT", "YAMAHA MARINE ENGINES", 1.6), false));
	//vehicleDepo->AddVehicle(new Airplane(1, ));
	vehicleDepo->ShowAllVehicles();
}
