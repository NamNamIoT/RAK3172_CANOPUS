/***
 *  This example shows character operation.
***/

char j;

void checkCharacter()
{
    // Analyze six characters and run six loops respectively
    for (int i = 0; i < 6; i++) { 
        switch (i) {
        case 0:
            j = ' ';			// In the first loop, the j variable is ' ' (space)
            break;
        case 1:
            j = 'A';			// In the second loop, the j variable is 'A'
            break;
        case 2:
            j = 'a';			// In the third loop, the j variable is 'a'
            break;
        case 3:
            j = '\n';			// In the fourth loop, the j variable is '\n' (new line)
            break;
        case 4:
            j = '1';			// In the fifth loop, the j variable is '1'
            break;
        case 5:
            j = '!';			// In the sixth loop, the j variable is '!'
            break;
        }
    
        Serial.print(">>>>>>>>>>>>Check Character :");
        Serial.print((String) j);	// show the variable j with string
        Serial.println(" <<<<<<<<<<<");
        if (isWhitespace(j))	// Analyse if char j is a white space character.
            Serial.println("is white space: O");
        else
            Serial.println("is white space: X");
    
        if (isUpperCase(j))		// Analyse if a char is a upper case
            Serial.println("is uppercase: O");
        else
            Serial.println("is uppercase: X");
    
        if (isSpace(j))		// Analyse if a char is a space character
            Serial.println("is space: O");
        else
            Serial.println("is space: X");
    
        if (isPunct(j))		// Analyse if a char is a punctuation character
            Serial.println("is punct: O");
        else
            Serial.println("is punct: X");
    
        if (isPrintable(j))		// Analyse if a char is printable
            Serial.println("is printable: O");
        else
            Serial.println("is printable: X");
    
        if (isLowerCase(j))		// Analyse if a char is lower case
            Serial.println("is lowercase: O");
        else
            Serial.println("is lowercase: X");
    
        if (isHexadecimalDigit(j))	// Analyse if a char is an hexadecimal digit (A-F,0-9)
            Serial.println("is HexadecimalDigit: O");
        else
            Serial.println("is HexadecimalDigit: X");
    
        if (isDigit(j))		// Analyse if a char is a digit (number)
            Serial.println("is digit: O");
        else
            Serial.println("is digit: X");
    
        if (isControl(j))		// Analyse if a char is a control character. 
            Serial.println("is control: O");
        else
            Serial.println("is control: X");
    
        if (isAscii(j))		// Analyse if a char is a Ascii
            Serial.println("is ascii: O");
        else
            Serial.println("is ascii: X");
    
        if (isAlphaNumeric(j))	// Analyse if a char is a alphanumeric
            Serial.println("is AlphaNumeric: O");
        else
            Serial.println("is AlphaNumeric: X");
    
        if (isAlpha(j))		// Analyse if a char is a control character. 
            Serial.println("is alpha: O");
        else
            Serial.println("is alpha: X");
    
        if (isGraph(j))		// Analyse if a char is printable with some content
            Serial.println("is graph: O");
        else
            Serial.println("is graph: X");
    
        Serial.println("");
    }
}

void setup()
{
    // initialize serial communcation at 115200 bits per second
    Serial.begin(115200);
    Serial.println("RAKwireless Arduino Characters Example");
    Serial.println("------------------------------------------------------");
  
    Serial.println("check characters START");
    Serial.println("");
    // call function
    checkCharacter();
}

void loop()
{
}
