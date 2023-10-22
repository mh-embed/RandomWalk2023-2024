// Search up Arduino Time library

#define CONST_ROW_0 2
#define CONST_ROW_1 3
#define CONST_COL_0 5
#define CONST_COL_1 6

const int _rowPins[] = {CONST_ROW_0, CONST_ROW_1};
const int _colPins[] = {CONST_COL_0, CONST_COL_1};
LedMatrix matrix;

class LedMatrix
{
  static const int NUM_ROWS = 2;
  static const int NUM_COLS = 2;

public:
  LedMatrix(const int rowPins[], const int colPins[]) : rowOn(-1), colOn(-1)
  {
    for (int row : rowPins) pinMode(row, OUTPUT);
    for (int col : colPins) pinMode(col, OUTPUT);

    this->rowPins = rowPins;
    this->colPins = colPins;
  }
  
    void turnOn(int row, int col)
    {
      this->clear();
      digitalWrite(this->rowPins[row], HIGH);
      digitalWrite(this->colPins[col], HIGH);
      this->rowOn = row;
      this->colOn = col;
    }

    void clear()
    {
      digitalWrite(this->rowPins[rowOn], LOW);
      digitalWrite(this->colPins[colOn], LOW);
      this->rowOn = -1;
      this->colOn = -1;
    }

    int getRowOn()
    {
      return this->rowOn;
    }

    int getColOn()
    {
      return this->colOn;
    }

  private:
    const int rowPins[NUM_ROWS];
    const int colPins[NUM_COLS];
    // These are -1 when no LED is active
    int rowOn;
    int colOn;
  };

  // Set up for eight Digital Pins
  void setup()
  {
    matrix = LedMatrix(_rowPins, _colPins);
  }

  void loop()
  {
    for (int row = 0; row < 2; row++) {
      for (int col = 0; col < 2; col++) {
        matrix.turnOn(row, col);
        delay(100);
      }
    }
  }
