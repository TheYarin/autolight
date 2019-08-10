class OperationStatus {
public:
  enum Status {
    OFF,
    AUTO,
    ON
  };

  OperationStatus(int inputPin);
  // 0 is off, 1 is auto, 2 is on
  int read();

private:
  int inputPin;
  int updateState();
  int previousButtonState;
  int currentButtonState;
};
