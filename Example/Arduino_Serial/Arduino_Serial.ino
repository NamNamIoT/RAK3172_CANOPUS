/***
 *  This example shows serial function.
 *  In this example, Serial1 set 5 seconds timeout, user can type in Serial1,
 *  after read '\r' or exceed 5 seconds, Serial1 will print the user's input.
***/

void setup()
{
  // initialize serial communication at 115200 bits per second, and use the AT mode
  Serial.begin(115200, RAK_AT_MODE);
  // initialize serial communication at 115200 bits per second, and use the custom mode
  Serial1.begin(115200, RAK_CUSTOM_MODE);
  Serial.println("RAKwireless Arduino Serial Example");
  Serial.println("------------------------------------------------------");
  delay(3000);
  Serial1.print("Current time out: ");
  Serial1.println(Serial.getTimeout());	// get Serial timeout
  Serial1.println("Set Timeout to 5000");
  Serial1.setTimeout(5000);	// set the Serial timeout to 5 seconds
  Serial1.print("Current time out: ");
  Serial1.println(Serial.getTimeout());	// get Serial timeout after changed
}

void loop()
{
  String returnString = " ";
  // reply only when receive data on Serial port
  Serial1.println("Please type any words in 5 seconds");
  returnString = Serial1.readStringUntil('\r');	// Read the string until the end of enter
  if (returnString == " ")
    Serial1.println("read nothing");
  else {
    Serial1.print("Typed: ");
    Serial1.println(returnString);	//Show the string you typed
  }
  Serial1.println("");
  delay(1000);
}
