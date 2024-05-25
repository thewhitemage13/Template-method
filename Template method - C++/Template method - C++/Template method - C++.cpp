#include <iostream>
using namespace std;

class Transmitter {
protected:
	virtual void VoiceRecord() {
		cout << "voice recording\n";
	}
	virtual void Simpling() {};
	virtual void Digitization() {};
	virtual void Modulation() = 0;
	virtual void Transmission() {
		cout << "radio transmission\n";
	};
public:
	void ProcessStart() {
		VoiceRecord();
		Simpling();
		Digitization();
		Modulation();
		Transmission();
	}
	virtual ~Transmitter(){}
};

class AnalogTransmitter : public Transmitter {
public:
	void Modulation() override {
		cout << "analog signal modulation\n";
	}
};

class DigitTransmitter : public Transmitter {
public:
	void Simpling() {
		cout << "sampling of the recorded fragment\n";
	}
	void Digitization() override {
		cout << "digitization\n";
	}
	void Modulation() override {
		cout << "digital signal modulation\n";
	}
};

int main() {
	Transmitter* analog = new AnalogTransmitter();
	analog->ProcessStart();
	cout << "\n";
	Transmitter* digit = new DigitTransmitter();
	digit->ProcessStart();
	delete analog;
	delete digit;
}