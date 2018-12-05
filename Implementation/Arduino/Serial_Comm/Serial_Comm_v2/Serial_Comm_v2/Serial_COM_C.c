//using system functions

void main(){
	system("echo off");
	system("set /p x=Enter a value for Frequency: "); //prompt the user to enter a value
	system("echo %x%>COM3");						  //echo the value to PORT COM3	

}

