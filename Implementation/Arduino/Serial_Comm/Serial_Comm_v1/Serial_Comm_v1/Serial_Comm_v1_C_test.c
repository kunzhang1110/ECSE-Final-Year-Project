#include <windows.h>
#include <stdio.h>


HANDLE hCOM;                            //handle for PORT
DCB SerialSetting_DCB = {0};				//DCB structure defines the control setting of serial communication device
char users_values[3];
COMMTIMEOUTS Time_out = {0};            //COMMTIMEOUTS determine the behaviour of WriteFile function
DWORD bytes_written= 0;

void main()
{
    //Prompt Users to enter
	users_value="365"

    // Open serial port number COMX
    fprintf(stderr, "Opening serial port");
    hCOM = CreateFile(
                "\\\\.\\COM3", GENERIC_READ|GENERIC_WRITE, 0, NULL,
                OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
	//Check the validity of the serial port
    if (hCOM == INVALID_HANDLE_VALUE)
    {
            printf("Failed\n");
            return;
    }
    else 
	{
		    fprintf(stderr, "OK\n");
	}

    if (GetCommState(hCOM, &SerialSetting_DCB) == 0)
    {
        printf( "Error getting device state\n");
        CloseHandle(hCOM);
        return;
    }
    //Set device to 115200 baud rate, 1 start bit, 1 stop bit, no parity
    SerialSetting_DCB.BaudRate = CBR_115200;
    SerialSetting_DCB.ByteSize = 8;
    SerialSetting_DCB.StopBits = ONESTOPBIT;
    SerialSetting_DCB.Parity = NOPARITY;

 
    // Set COM port timeout settings
    Time_out.ReadIntervalTimeout = 50;
    Time_out.ReadTotalTimeoutConstant = 50;
    Time_out.ReadTotalTimeoutMultiplier = 10;
    Time_out.WriteTotalTimeoutConstant = 50;
    Time_out.WriteTotalTimeoutMultiplier = 10;
 

    printf("Sending bytes...");
    if(!WriteFile(hCOM, users_values, 4, &bytes_written, NULL))
    {
        fprintf(stderr, "Error\n");
        CloseHandle(hCOM);
        return;
    } 
    printf("%d bytes written\n", bytes_written);
     
    // Close serial port
	CloseHandle(hCOM);

    return;
}
