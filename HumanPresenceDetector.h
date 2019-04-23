class HumanPresenceDetector {
public:
    HumanPresenceDetector(int inputPin);
    bool humanPresenceDetected();
private:
    int inputPin;
};
