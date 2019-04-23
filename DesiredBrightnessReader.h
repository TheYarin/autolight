class DesiredBrightnessReader {
public:
    DesiredBrightnessReader(int inputPin);
    int get();
private:
    int inputPin;
};
