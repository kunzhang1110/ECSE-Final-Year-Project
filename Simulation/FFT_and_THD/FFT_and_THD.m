%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                                                                                                               %
%           The aim is to                                                                                                                                       %                                                   
%           Test function thd_fft_calc()                                                                                                                        %
%           version 1, written by Kun Zhang                                                                                                                     %                                 
%                                                                                                                                                               %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%global      ;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc;clear;close all;

fd_frequency= 50;       %fundamental frequency
fs= 9600;               %sampling frequency > 2*factor*maximum siganl frequency
ts= 0.06;               %total sampling time in seconds
L= fs*ts;               %total length
t= (0:L-1)/fs;          %n vector
i= 1;                   %counter used in loops


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% v_out= sin(2*pi*fd_frequency*t)+0.5*sin(2*pi*3*fd_frequency*t)+0.1*sin(2*pi*5*fd_frequency*t)+0.05*sin(2*pi*7*fd_frequency*t);      %distorted signal
% thd_exp= norm([0.5 0.1 0.05],2)/norm(1,2)                                                                                           %expected THD

v_out= sin(2*pi*fd_frequency*t)+0.08*sin(2*pi*3*fd_frequency*t)+0.009*sin(2*pi*5*fd_frequency*t); 
thd_exp= norm([0.08 0.0009],2)^2/norm(1,2)^2

%newplot
%plot(t,v_out,'-x')     %plot distorted signal
%xlabel('t');
%ylabel('v_out');


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
N= 2^nextpow2(L)*10;                                            %N is the length of Y, higher N higher accuracy and computation time
Y= fft(v_out,N);                                                %FFT with N points
f= fs/2*linspace(0,1,N/2+1);                                    %one sided with N points plus piont 0                              
Y_mag= 2*abs(Y(1:N/2+1));                                       %magnitude, eliminate imaginary parts

f_dis= 300;                                                     %max frequency to be displayed
dis_b= fs/N;                                                    %distance between two points
p_int= floor(f_dis/(dis_b))+1;                                  %no. of points to get the max displayed frequency
% plot(f(1:p_int),Y_mag(1:p_int),'o')                           %plot points of FFT
bar(f(1:p_int),Y_mag(1:p_int))                                  %plot bars of FFT
title('Single-Sided Amplitude Spectrum of y(t)')
xlabel('Frequency (Hz)')
ylabel('|Y(f)|')
while i<=5
    data_f(i)= f(abs(f-(2*i-1)*fd_frequency)<dis_b/2);          %harmonics frequencies
    datavec(i)= Y_mag(abs(f-(2*i-1)*fd_frequency)<dis_b/2);     %find magnitudes corresponding to harmonics
    i= i+1;                                                     
end    
thd= (datavec(2)^2 +datavec(3)^2 +datavec(4)^2 +datavec(5)^2 )/datavec(1)^2                  %THD calculated        
