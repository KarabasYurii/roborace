#ifndef Rangefinder_h
#define Rangefinder_h

class Rangefinder {
public:
    virtual long getDistance() = 0;
};

class RangefinderDigital : public Rangefinder {
private:
    int echoPin;
    int trigPin;
public:
    RangefinderDigital(int echoPin, int trigPin);

    virtual long getDistance();
};

RangefinderDigital::RangefinderDigital(int echoPin, int trigPin) {
    this->echoPin = echoPin;
    this->trigPin = trigPin;

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

long RangefinderDigital::getDistance() {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    return duration / 58.2;
}

#endif
