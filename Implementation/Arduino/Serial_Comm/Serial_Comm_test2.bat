mode COM3 BAUD=115200 PARITY=n DATA=8
echo off
set /p x=Enter a value: 
echo %x%>COM3
echo Serial Communication......Completed
PAUSE