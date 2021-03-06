
const int ledPin = 13;      // the number of the LED pin

// constants won't change. They're used here to 
// set pin numbers:
const int p1_1MovePin = 2;    // the number of the pushbutton pin
const int p1_2MovePin = 3;    // the number of the pushbutton pin
const int p1_3MovePin = 4;    // the number of the pushbutton pin


int last_p1_1MoveState = LOW;   // the previous reading from the input pin
int last_p1_2MoveState = LOW;   // the previous reading from the input pin
int last_p1_3MoveState = LOW;   // the previous reading from the input pin

int debounced_p1_1MoveState = LOW;   // the previous reading from the input pin
int debounced_p1_2MoveState = LOW;   // the previous reading from the input pin
int debounced_p1_3MoveState = LOW;   // the previous reading from the input pin

long last_p1_1MoveTime = 0;  // the last time the output pin was toggled
long last_p1_2MoveTime = 0;  // the last time the output pin was toggled
long last_p1_3MoveTime = 0;  // the last time the output pin was toggled


// player2
const int p2_1MovePin = 6;    // the number of the pushbutton pin
const int p2_2MovePin = 7;    // the number of the pushbutton pin
const int p2_3MovePin = 8;    // the number of the pushbutton pin


int last_p2_1MoveState = LOW;   // the previous reading from the input pin
int last_p2_2MoveState = LOW;   // the previous reading from the input pin
int last_p2_3MoveState = LOW;   // the previous reading from the input pin

int debounced_p2_1MoveState = LOW;   // the previous reading from the input pin
int debounced_p2_2MoveState = LOW;   // the previous reading from the input pin
int debounced_p2_3MoveState = LOW;   // the previous reading from the input pin

long last_p2_1MoveTime = 0;  // the last time the output pin was toggled
long last_p2_2MoveTime = 0;  // the last time the output pin was toggled
long last_p2_3MoveTime = 0;  // the last time the output pin was toggled


// player3
const int p3_1MovePin = 10;    // the number of the pushbutton pin
const int p3_2MovePin = 11;    // the number of the pushbutton pin
const int p3_3MovePin = 12;    // the number of the pushbutton pin


int last_p3_1MoveState = LOW;   // the previous reading from the input pin
int last_p3_2MoveState = LOW;   // the previous reading from the input pin
int last_p3_3MoveState = LOW;   // the previous reading from the input pin

int debounced_p3_1MoveState = LOW;   // the previous reading from the input pin
int debounced_p3_2MoveState = LOW;   // the previous reading from the input pin
int debounced_p3_3MoveState = LOW;   // the previous reading from the input pin

long last_p3_1MoveTime = 0;  // the last time the output pin was toggled
long last_p3_2MoveTime = 0;  // the last time the output pin was toggled
long last_p3_3MoveTime = 0;  // the last time the output pin was toggled

							 // Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin


							 // the following variables are long's because the time, measured in miliseconds,
							 // will quickly become a bigger number than can be stored in an int.

long debounceDelay = 10;    // the debounce time; increase if the output flickers

void setup() {
	pinMode(p1_1MovePin, INPUT);
	pinMode(p1_2MovePin, INPUT);
	pinMode(p1_3MovePin, INPUT);

	pinMode(p2_1MovePin, INPUT);
	pinMode(p2_2MovePin, INPUT);
	pinMode(p2_3MovePin, INPUT);
	
	pinMode(p3_1MovePin, INPUT);
	pinMode(p3_2MovePin, INPUT);
	pinMode(p3_3MovePin, INPUT);
	


	//pinMode(ledPin, OUTPUT);

	// set initial LED state
	//digitalWrite(ledPin, ledState);

	Serial.begin(9600);       // use the serial port
}

void loop() {
	
	handleSwitch(p1_1MovePin, &last_p1_1MoveState, &debounced_p1_1MoveState, &last_p1_1MoveTime, "0");
	handleSwitch(p1_2MovePin, &last_p1_2MoveState, &debounced_p1_2MoveState, &last_p1_2MoveTime, "0");
	handleSwitch(p1_3MovePin, &last_p1_3MoveState, &debounced_p1_3MoveState, &last_p1_3MoveTime, "0");


	handleSwitch(p2_1MovePin, &last_p2_1MoveState, &debounced_p2_1MoveState, &last_p2_1MoveTime, "1");
	handleSwitch(p2_2MovePin, &last_p2_2MoveState, &debounced_p2_2MoveState, &last_p2_2MoveTime, "1");
	handleSwitch(p2_3MovePin, &last_p2_3MoveState, &debounced_p2_3MoveState, &last_p2_3MoveTime, "1");

	handleSwitch(p3_1MovePin, &last_p3_1MoveState, &debounced_p3_1MoveState, &last_p3_1MoveTime, "2");
	handleSwitch(p3_2MovePin, &last_p3_2MoveState, &debounced_p3_2MoveState, &last_p3_2MoveTime, "2");
	handleSwitch(p3_3MovePin, &last_p3_3MoveState, &debounced_p3_3MoveState, &last_p3_3MoveTime, "2");
	

}


void handleSwitch(int movePin, int* lastMoveState, int* debouncedMoveState, long* lastMoveTime, char *str) {
	// read the state of the switch into a local variable:
	int reading = digitalRead(movePin);

	// check to see if you just pressed the button 
	// (i.e. the input went from LOW to HIGH),  and you've waited 
	// long enough since the last press to ignore any noise:  

	// If the switch changed, due to noise or pressing:
	if (reading != *lastMoveState) {
		// reset the debouncing timer
		*lastMoveTime = millis();
	}

	if ((millis() - *lastMoveTime) > debounceDelay) {
		// whatever the reading is at, it's been there for longer
		// than the debounce delay, so take it as the actual current state:

		// if the button state has changed:

		if (*debouncedMoveState == LOW && reading == HIGH) {
			Serial.println(str);
		}
		*debouncedMoveState = reading;

	}

	// set the LED:
	//  digitalWrite(ledPin, ledState);

	// save the reading.  Next time through the loop,
	// it'll be the lastButtonState:
	*lastMoveState = reading;


}

