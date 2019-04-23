class OperationStatus {
public:
  enum Status {
    OFF,
    AUTO,
    ON
  };

  // 0 is off, 1 is auto, 2 is on
  int read();
};