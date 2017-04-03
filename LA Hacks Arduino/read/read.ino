
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){
    ;  
  }
  Serial.println("\nString substring():");
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  String rawInput = "090090090090";// input array
  Serial.println("It's an array");
  
  String temp = rawInput.substring(0, 3);
  //int value = atoi(temp);
  Serial.println(temp);
}
