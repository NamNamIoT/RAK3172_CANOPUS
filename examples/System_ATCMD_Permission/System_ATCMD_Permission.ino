
/***
 *  This example shows AT command permission level.
 *  PERMISSION LEVEL:
 *  RAK_ATCMD_PERM_WRITE,
 *  RAK_ATCMD_PERM_READ,
 *  RAK_ATCMD_PERM_WRITEONCEREAD,
 *  RAK_ATCMD_PERM_DISABLE
 *  RAK_ATCMD_PERM_DISABLE will have the highest priority then other permission.
 *  Every commands will have a default permission, the permission you set could only be the subset of default permission.
 *  If the default permission is RAK_ATCMD_PERM_READ and RAK_ATCMD_PERM_WRITE, then you can only set the permission to RAK_ATCMD_PERM_WRITE or RAK_ATCMD_PERM_READ or RAK_ATCMD_PERM_DISABLE.
 *  If the permission you set is not the subset of default permisson, the commands will set permission as default.
 *  Can also add the directives in variant.h
 *  The format is AT_*your_command*_PERM.
 *  For example:
 *  #define AT_APPKEY_PERM      RAK_ATCMD_PERM_READ
 *  #define AT_DEVEUI_PERM      RAK_ATCMD_PERM_WRITE
 *  #define AT_PWORD_PERM       RAK_ATCMD_PERM_WRITEONCEREAD
 *  #define AT_APPEUI_PERM      RAK_ATCMD_PERM_DISABLE
 *  #define AT_ALIAS_PERM       RAK_ATCMD_PERM_READ | RAK_ATCMD_PERM_WRITE
***/

CHANGE_ATCMD_PERM("AT+APPKEY", RAK_ATCMD_PERM_READ);
CHANGE_ATCMD_PERM("AT+DEVEUI", RAK_ATCMD_PERM_WRITE);
CHANGE_ATCMD_PERM("AT+PWORD", RAK_ATCMD_PERM_WRITEONCEREAD);
CHANGE_ATCMD_PERM("AT+APPEUI", RAK_ATCMD_PERM_DISABLE);
CHANGE_ATCMD_PERM("AT+ALIAS", RAK_ATCMD_PERM_READ | RAK_ATCMD_PERM_WRITE);

void setup()
{
    Serial.begin(115200);
    Serial.println("RAKwireless AT Command Permission Example");
    Serial.println("------------------------------------------------------");
}

void loop()
{

}
