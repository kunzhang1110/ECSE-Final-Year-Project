function	pwm_3p_v2(RefSinusoid,PWMFreq,SamplingFreq)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                                                                                                               %
%           The aim is to:                                                                                                                                      %                                                           
%           generate 3-phase PWM waveform using principle of PWM                                                                                                %                      
%           Version 2, written by Kun Zhang                                                                                                                     %                                          
%                                                                                                                                                               %
%           The input parameters are                                                                                                                            %                                               
%           RefSinusoid: reference sinusoidal signal, a structure contains amplitude, frequency and duration                                                    % 
%           PWMFreq: the frequency of the rectangular PWM                                                                                                       %                                                                          
%           SamplingFreq: sampling frequency                                                                                                                    %
%                                                                                                                                                               %
%           Example:                                                                                                                                            %
%           RefSinusoid= struct('Amp',5,'Freq',20,'Duration',0.3);              pwm_3p_v2(RefSinusoid,100,1000)                                                 % 
%                                                                                                                                                               %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%global     ;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
close all;
von= RefSinusoid.Amp*2;             sp_T= 1/SamplingFreq;             t= 0:sp_T:RefSinusoid.Duration;                                                                                             
%prealloacations
pwm_wav_1= zeros(1,length(t));                pwm_wav_2= zeros(1,length(t));                pwm_wav_3= zeros(1,length(t));    
pwm_wav_4= zeros(1,length(t));                pwm_wav_5= zeros(1,length(t));                pwm_wav_6= zeros(1,length(t));        


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Three phase reference signal
cos_wav_a= RefSinusoid.Amp*cos(2*pi*RefSinusoid.Freq*t)+RefSinusoid.Amp;
cos_wav_b= RefSinusoid.Amp*cos(2*pi*RefSinusoid.Freq*t+2*pi/3)+RefSinusoid.Amp;
cos_wav_c= RefSinusoid.Amp*cos(2*pi*RefSinusoid.Freq*t+4*pi/3)+RefSinusoid.Amp;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
m= 1;                                                                                           %reset counter m
PWMSize= SamplingFreq/PWMFreq;                                                                  %the size of one PWM block

while       m<length(t)-PWMSize                                                                 %for phase a
            D= cos_wav_a(m)/von;                                                                %obtain duty cycle
            ion= round(D*PWMSize);                                                              %on duration
            n= 0;                                                                               %reset counter n
            while       n<PWMSize+1                                                             %while in one rectanglar wave period
                        if      n<(ion+1)                                                       %if witin on duration
                                pwm_wav_1(m+n)= von;                                      
                        else        
                                pwm_wav_1(m+n)= 0;  
                        end

                        % Delay
%                        pause on;                pause(1*10^-6);                pause off;      %pausing for switching time (typically less than 1us)
        
                        %upper switch and lower switch are pairwise invereted
                        if      pwm_wav_1(m+n)==0;                  pwm_wav_2(m+n)= von;
                        elseif  pwm_wav_1(m+n)==von;                pwm_wav_2(m+n)= 0;
                        end
                        n= n+1;
            end                       
            m= m+PWMSize;                                                                       %the first point used to determine duty cycle
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
m= 1;                                                                                           %reset counter m
while       m<length(t)-PWMSize                                                                 %for phase b
            D= cos_wav_b(m)/von;                                                                %obtain duty cycle
            ion= round(D*PWMSize);                                                              %on duration
            n= 0;                                                                               %reset counter n
            while       n<PWMSize+1                                                          	%while in one rectanglar wave period
                        if      n<(ion+1)                                                       %if witin on duration
                                pwm_wav_3(m+n)= von;                pwm_wav_4(m+n)= 0;                                        
                        else        
                                pwm_wav_3(m+n)= 0;                  pwm_wav_5(m+n)= von;  
                        end
                        
                        % Delay
 %                       pause on;                pause(1*10^-6);                pause off;      %pausing for switching time (typically less than 1us)
        
                        %upper switch and lower switch are pairwise invereted
                        if      pwm_wav_3(m+n)==0;                  pwm_wav_4(m+n)= von;
                        elseif  pwm_wav_3(m+n)==von;                pwm_wav_4(m+n)= 0;
                        end 
                        n= n+1;
            end    
            m= m+PWMSize;
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
m= 1;                                                                                           %reset counter m
while       m<length(t)-PWMSize                                                             	%for phase c
            D= cos_wav_c(m)/von;                                                                %obtain duty cycle
            ion= round(D*PWMSize);                                                           	%on duration
            n= 0;                                                                               %reset counter n
            while       n<PWMSize+1                                                             %while in one rectanglar wave period
                        if      n<(ion+1)                                                       %if witin on duration
                                pwm_wav_5(m+n)= von;                pwm_wav_6(m+n)= 0;                                        
                        else        
                                pwm_wav_5(m+n)= 0;                  pwm_wav_6(m+n)= von;  
                        end

                        % Delay
%                        pause on;                pause(1*10^-6);                pause off;      %pausing for switching time (typically less than 1us)
        
                        %upper switch and lower switch are pairwise invereted
                        if      pwm_wav_5(m+n)==0;                	pwm_wav_6(m+n)= von;
                        elseif  pwm_wav_5(m+n)==von;            	pwm_wav_6(m+n)= 0;
                        end  
                        n= n+1;
                        
            end    
            m= m+PWMSize;                                                                    	%the first point used to determine duty cycle        
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%plot reference
subplot(5,1,1)
ylower= -2*RefSinusoid.Amp-1;                                                                   %upper limit of y axis 
yupper= 2*RefSinusoid.Amp+1;                                                                    %lower limitof y axis 
%YLim([-2*amp-1,2*amp+1])
ylim([ylower,yupper])
title('reference');
grid on;                hold on;
line(t,cos_wav_a,'Color',[1 0 0]);              hold on;                                        %plot reference signals in red, green and cyan
line(t,cos_wav_b,'Color',[0 1 0]);              hold on;
line(t,cos_wav_c,'Color',[0 1 1]);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%plot PWM 1
subplot(5,1,2)
line(t,pwm_wav_1);
xlabel('Time(s)');              ylabel('Amplitude');                title('PWM1');
grid on;
%YLim([-2*amp-1,2*amp+1])
ylim([ylower,yupper])


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%plot PWM 1
subplot(5,1,3)
line(t,pwm_wav_2);
xlabel('Time(s)');              ylabel('Amplitude');                title('PWM2');
grid on;
%YLim([-2*amp-1,2*amp+1])
ylim([ylower,yupper])


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%plot PWM1 - PWM2
subplot(5,1,4)
line(t,pwm_wav_3);
xlabel('Time(s)');              ylabel('Amplitude');                title('PWM3');
grid on;
%YLim([-2*amp-1,2*amp+1])
ylim([ylower,yupper])


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%plot PWM1 - PWM2
subplot(5,1,5)
line(t,pwm_wav_1-pwm_wav_2);
xlabel('Time(s)');              ylabel('Amplitude');                title('PWM1-PWM2');
grid on;
%YLim([-2*amp-1,2*amp+1])
ylim([ylower,yupper])


