// Search up Arduino Time library

#define CONST_ROW_0 5
#define CONST_ROW_1 6
#define CONST_COL_0 2
#define CONST_COL_1 3

const int _rowPins[] = {CONST_ROW_0, CONST_ROW_1};
const int _colPins[] = {CONST_COL_0, CONST_COL_1};

int* arrayDeepCopy(const int arr1[], const int size){
  int* arr2 = new int[size];
  for(int i = 0; i < size; i++){
    arr2[i] = arr1[i];
  }
  return arr2;
}

class LedMatrix
{
  static const int NUM_ROWS = 2;
  static const int NUM_COLS = 2; 
  //int rowPins[NUM_ROWS];
public:
  LedMatrix(const int input_row[],const int input_col[]) : rowOn(-1), colOn(-1)
  {
    for (int i = 0; i < NUM_ROWS; i++){
      pinMode(input_row[i], OUTPUT);
    } 
    for (int j = 0; j < NUM_COLS; j++) {
      pinMode(input_col[j], OUTPUT);
    }
    rowPins = arrayDeepCopy(input_row, NUM_ROWS);
    colPins = arrayDeepCopy(input_col, NUM_COLS);
  }
  
    void turnOn(int row, int col)
    {
      this->clear();
      digitalWrite(this->rowPins[row], HIGH); // We can rewrite this as a Setter function for setting individual rowPins
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
    int* rowPins;
    int* colPins;
    // These are -1 when no LED is active
    int rowOn;
    int colOn;
  };

  LedMatrix matrix = LedMatrix(_rowPins, _colPins);

  // Set up for eight Digital Pins
  void setup()
  {
    Serial.begin(9600);
  }

  void loop()
  {
    for (int row = 0; row < 2; row++) {
      for (int col = 0; col < 2; col++) {
        matrix.turnOn(row, col);
        delay(100);
        matrix.clear();
      }
    }

  }

