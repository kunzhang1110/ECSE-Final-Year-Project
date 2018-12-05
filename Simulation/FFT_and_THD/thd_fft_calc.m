function [thd] = thd_fft_calc(Sig_in,fd_frequency,THDBit,PltBit)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                                                                                                               %
%           The aim is to                                                                                                                                       %                                                           
%           Calculate Total Harmonic Distortions (THD) of a signal                                                                                              %                      
%           Version 1, written by Kun Zhang                                                                                                                     %                                          
%                                                                                                                                                               %
%           The input parameters are                                                                                                                            %                                               
%           Sig_in: input signal into the function                                                                                                              %                              
%           THDBit: Calculate THD when THDBit is asserted                                                                                                       %         
%           Pltbit: plot when Pltbit >1 and 0 otherwise                                                                                                         %                      
%           fd_frequency: fundamental frequency (Hz)                                                                                                            %                                             
%                                                                                                                                                               %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%global      ;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fs= 9600;                                                                  %sampling frequency > 2*factor*maximum siganl frequency


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if      nargin==0                                                          %default intputs when no input signal is provided
        PltBit= 1;                      THDBit= 1;               
        L=9600*(0.06);                                                     %defalut data length
        nd= (0:L-1)/fs;                                                    %n vectors (s)
        fd_frequency= 50;                                                  %defalut fundamental frequency (Hz)       

        Sig_in= sin(2*pi*fd_frequency*nd)+0.08*sin(2*pi*3*fd_frequency*nd)+0.009*sin(2*pi*5*fd_frequency*nd)    
        thd_exp= norm([0.08 0.0009],2)^2/norm(1,2)^2                       %expected thd

%         Sig_in= sin(2*pi*fd_frequency*nd)+0.08*sin(2*pi*3*fd_frequency*nd)+0.009*sin(2*pi*5*fd_frequency*nd); 
%         thd_exp= norm([0.08 0.0009],2)/norm(1,2)
% 
%         Sig_in= 5*sin(2*pi*fd_frequency*nd)+sin(2*pi*3*fd_frequency*nd)+0.01*sin(2*pi*5*fd_frequency*nd); 
%         thd_exp= norm([1 0.01],2)/norm(5,2)
% 
%         Sig_in= sin(2*pi*fd_frequency*nd)+0.01*sin(2*pi*3*fd_frequency*nd)+randn(1,length(nd));
%         Sig_in= randn(1,length(nd));
end

if      nargin==1                                                          %default intputs when only an input signal is provided
        PltBit= 1;              THDBit= 1;              fd_frequency= 50;  %defalut fundamental frequency   
                                                                           
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
L= length(Sig_in);                                                         %total length
N= 2^nextpow2(L)*500;                                                      %N is determined this way to be used in FFT
Y= fft(Sig_in,N);                                                          %FFT with N points
f= fs/2*linspace(0,1,N/2+1);                                               %one sided with N points plus piont 0                              
Y_mag= 2*abs(Y(1:N/2+1));                                                  %magnitude, eliminate imaginary parts


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if      PltBit                                                             %plot DFT spectrum when PltBit is set
        f_dis= 300;                                                        %max frequency to be displayed (Hz)
        dis_b= fs/N;                                                       %distance between two points
        p_int= floor(f_dis/(dis_b))+1;                                     %no. of points to get the max displayed frequency
        % line(f(1:p_int),Y_mag(1:p_int),'o')                              %plot points of FFT
        bar(f(1:p_int),Y_mag(1:p_int))                                     %plot bars of FFT
        title('Single-Sided Amplitude Spectrum of y(t)');               xlabel('Frequency (Hz)');              ylabel('|Y(f)|');
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if      THDBit                                                                                          %calculate THD when THDBit is set
        data_f= zeros(1,L);             datavec= zeros(1,L);                                            %preallocate arrays
        i= 1;                                                                                        	%counter used in a loop
        while i<=5                                                                                      %up to 2*10-1 th harmonics
            data_f(i)= f(abs(f-(2*i-1)*fd_frequency)<dis_b/2);                                          %harmonics frequencies
            datavec(i)= Y_mag(abs(f-(2*i-1)*fd_frequency)<dis_b/2);                                     %find magnitudes corresponding to harmonics
            i= i+1;                                                     
        end    
        thd= (datavec(2)^2 +datavec(3)^2 +datavec(4)^2 +datavec(5)^2 )/datavec(1)^2;                    %THD calculated   
end


