unsigned char data[10][7]={
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1},
  };

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  int i = 0;
  int j = 0;

  for(i=0;i<10;i++){
    for(j=0;j<7;j++){
      digitalWrite((j+2),data[i][j]);
      }
      delay(1000);
  }
  // put your main code here, to run repeatedly:

}
