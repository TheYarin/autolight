class RoomBrightnessDetector {
public:
    RoomBrightnessDetector(int inputPin);
    int getRoomBrightness();
private:
    int inputPin;
};
