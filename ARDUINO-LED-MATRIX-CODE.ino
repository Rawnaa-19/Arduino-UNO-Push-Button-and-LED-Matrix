//define column and row pin number
int rows[]={13,12,11,10,9};
int columns[]={6,5,4,3,2};
int delayTime = 300;
int matrix[5][5] = {{1,1,1,1,1},
		       {1,0,1,0,1},
		       {1,0,1,0,1},
		       {0,1,1,1,0},
		       {1,0,0,0,1}};
// initialize pin mode
void setup() {
for (int thisPin = 0; thisPin < 5; thisPin++) {
    // initialize the output pins:
    pinMode(columns[thisPin], OUTPUT);
    pinMode(rows[thisPin], OUTPUT);
  }

}
// define loop
void loop(){
  for (int c=0; c<5; c++){
    digitalWrite(columns[c], HIGH);
    for (int r = 0; r < 5; r++){
      digitalWrite(rows[r], 255*matrix[r][c]);
    delay(1);
    }
    for (int r = 0; r < 5; r++){
      digitalWrite(rows[r], HIGH);
   delay(1);
    }
  
    digitalWrite(columns[c], LOW);
  }
}
  
