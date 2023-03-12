/***
 *  This example shows Arduino bit and byte operation.
***/

// show the bits with binary
void test_bit()
{
    Serial.println(">>>>Test bit()<<<<<");
    Serial.println("(bit 0 is 1, bit 1 is 2, bit 2 is 4, bit 3 is 8,  etc.)");
    Serial.print("bit 0: ");
    Serial.println(bit(0));	// show the bit 0 with binary
    Serial.print("bit 3: ");
    Serial.println(bit(3));	// show the bit 3 with binary

    Serial.println("");
}

// read the bits of number and show the specified bit
void test_bitRead()
{
    Serial.println(">>>>Test bitRead()<<<<<");
    Serial.println("Read the bits of 6(0110)");
    Serial.print("bitRead(6, 0) = ");
    Serial.println(bitRead(6, 0));	// read number 6 of bit 0
    Serial.print("bitRead(6, 1) = ");
    Serial.println(bitRead(6, 1));	// read number 6 of bit 1
    Serial.print("bitRead(6, 2) = ");
    Serial.println(bitRead(6, 2));	// read number 6 of bit 2
    Serial.print("bitRead(6, 3) = ");
    Serial.println(bitRead(6, 3));	// read number 6 of bit 3
  
    Serial.println("");
}

// set the bits of number to 1
void test_bitSet()
{
    Serial.println(">>>>Test bitSet()<<<<<");
    Serial.print("Before bitSet(): 6 => ");
    Serial.println(6, BIN);	// show the number 6 with binary
    Serial.print("After bitSet(6, 0) => ");
    int value = 6;
    int pos = 0;
    Serial.println(bitSet(value, pos), BIN);	// set bit 0 of number 6 to 1
  
    Serial.println("");
}

// set the bits of number to 0
void test_bitClear()
{
    Serial.println(">>>>Test bitClear()<<<<<");
    Serial.print("Before bitClear(): 6 => ");
    Serial.println(6, BIN);	// show the number 6 with binary
    Serial.print("After bitClear(6, 1) => ");
    int value = 6;
    int pos = 1;
    Serial.println(bitClear(value, pos), BIN);	// set bit 1 of number 6 to 0
  
    Serial.println("");
}

// set the bits of number
void test_bitWrite()
{
    Serial.println(">>>>Test bitWrite()<<<<<");
    int target = 6;		// variable for bit write target
    Serial.print("Before bitWrite(): 6 => ");
    Serial.println(target, BIN);	// show the target value
    Serial.print("After bitWrite(target, 0, 1) => ");
    Serial.println(bitWrite(target, 0, 1), BIN);	// set the bit 0 of target to 1
    Serial.print("After bitWrite(target, 1, 0) => ");
    Serial.println(bitWrite(target, 1, 0), BIN);	// set the bit 1 of target to 0
    Serial.print("After bitWrite(target, 2, 0) => ");
    Serial.println(bitWrite(target, 2, 0), BIN);	// set the bit 2 of target to 0
    Serial.print("After bitWrite(target, 3, 1) => ");
    Serial.println(bitWrite(target, 3, 1), BIN);	// set the bit 3 of target to 1
    Serial.println("target now should be 9(1001)");
    Serial.print("target = ");
    Serial.println(target);	// show the changed target value
  
    Serial.println("");
}
  
void test_lowByte_highByte()
{
    int target = 0xABCD;		// define the variable as hexadecimal
    Serial.println(">>>>Test lowByte() and highByte()<<<<<");
    Serial.println("Test target 0xABCD");
    Serial.print("lowByte() of 0xABCD = ");
    Serial.println(lowByte(target), HEX);	// show the target value with hexadecimal low byte
    Serial.print("highByte() of 0xABCD = ");
    Serial.println(highByte(target), HEX);	// show the target value with hexadcimal high byte
  
    Serial.println("");
}

void setup()
{
    // initialize serial communication at 115200 bits per second
    Serial.begin(115200);
  
    Serial.println("RAKwireless Arduino Bit and Byte Example");
    Serial.println("------------------------------------------------------");
    // call function
    test_bit();
    test_bitSet();
    test_bitClear();
    test_bitRead();
    test_bitWrite();
    test_lowByte_highByte();
}

void loop()
{
}
