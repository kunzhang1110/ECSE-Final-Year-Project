function	pwm_3p_v1(RefSinusoid,TriangularFreq,SamplingFreq)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                                                                                                               %
%           The aim is to:                                                                                                                                      %                                                           
%           generate 3-phase PWM waveform using triangular wave                                                                                                 %                      
%           Version 1, written by Kun Zhang                                                                                                                     %                                          
%                                                                                                                                                               %
%           The input parameters are                                                                                                                            %                                               
%           RefSinusoid: reference sinusoidal signal, a structure contains amplitude, frequency and duration                                                    % 
%           TriangularFreq: the frequency of the triangular wave for PWM generation                                                                             %                                                                          
%           SamplingFreq: sampling frequency                                                                                                                    %
%                                                                                                                                                               %
%           Example:                                                                                                                                            %
%           RefSinusoid= struct('Amp',5,'Freq',20,'Duration',0.3);              pwm_3p_v1(RefSinusoid,100,1000)                                                 % 
%                                                                                                                                                               %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%global     ;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
close all;
if      TriangularFreq<RefSinusoid.Freq
        error('Triangular frequency should be greater than cosine frequency')                                   %error messages
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
von= 5;             tri_per= 1/TriangularFreq;             t= 0:(1/SamplingFreq):RefSinusoid.Duration;          %initial settings      
tri_wav= (2*RefSinusoid.Amp/(tri_per/2))*abs(mod(t,tri_per)-tri_per/2)-RefSinusoid.Amp;                         %triangular wave generation
%prealloacations
pwm_wav_1= zeros(1,length(t));                pwm_wav_2= zeros(1,length(t));                pwm_wav_3= zeros(1,length(t));    
pwm_wav_4= zeros(1,length(t));                pwm_wav_5= zeros(1,length(t));                pwm_wav_6= zeros(1,length(t));   


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Three phase reference signal
cos_wav_a= RefSinusoid.Amp*cos(2*pi*RefSinusoid.Freq*t);
cos_wav_b= RefSinusoid.Amp*cos(2*pi*RefSinusoid.Freq*t+2*pi/3);
cos_wav_c= RefSinusoid.Amp*cos(2*pi*RefSinusoid.Freq*t+4*pi/3);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
for     i=1:length(t)
        if      tri_wav(i)>cos_wav_a(i);            pwm_wav_1(i)= 0;          
        else                                        pwm_wav_1(i)= von;
        end
    
        if      tri_wav(i)>cos_wav_b(i);            pwm_wav_3(i)= 0;
        else                                        pwm_wav_3(i)= von;  
        end    

        if      tri_wav(i)>cos_wav_c(i);            pwm_wav_5(i)= 0;
        else                                        pwm_wav_5(i)= von;
        end
        
        % Delay whenever any switches is not open
        if      pwm_wav_1(i)~=0||pwm_wav_3(i)~=0||pwm_wav_5(i)~=0
        pause on;                pause(1*10^-6);                pause off;                          %pausing for switching time (typically less than 1us
        end
        
        %upper switch and lower switch are pairwise invereted
        if      pwm_wav_1(i)==0;                    pwm_wav_2(i)= von;
        elseif  pwm_wav_1(i)==von;                  pwm_wav_2(i)= 0;
        end
        
        if      pwm_wav_3(i)==0;                    pwm_wav_4(i)= von;
        elseif  pwm_wav_3(i)==von;                  pwm_wav_4(i)= 0;
        end        
        
        if      pwm_wav_5(i)==0;                    pwm_wav_6(i)= von;
        elseif  pwm_wav_5(i)==von;                  pwm_wav_6(i)= 0;
        end

        % Delay whenever any switches is not open
        if      pwm_wav_2(i)~=0||pwm_wav_4(i)~=0||pwm_wav_6(i)~=0
        pause on;                pause(1*10^-6);                pause off;                          %pausing for switching time (typically less than 1us
        end
        
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%plot reference and triangular wave
subplot(4,1,1)
%YLim([-amp-1,amp+1])
ylim([-RefSinusoid.Amp-1,RefSinusoid.Amp+1]);
line(t,tri_wav,'Color',[0 0 1]);                                                                    %plot triangular wave in blue
title('reference and triangular wave');
grid on;                hold on;
line(t,cos_wav_a,'Color',[1 0 0]);              hold on;                                            %plot reference signals in red, green and cyan
line(t,cos_wav_b,'Color',[0 1 0]);              hold on;
line(t,cos_wav_c,'Color',[0 1 1]);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%plot PWM 1
subplot(4,1,2)
line(t,pwm_wav_1);
xlabel('Time(s)');              ylabel('Amplitude');                title('PWM1');
grid on;
%YLim([-amp-1,amp+1]);
ylim([-RefSinusoid.Amp-1,RefSinusoid.Amp+1]);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%plot PWM 2
subplot(4,1,3)
line(t,pwm_wav_2);
xlabel('Time(s)');              ylabel('Amplitude');                title('PWM2');
grid on;
%YLim([-amp-1,amp+1]);
ylim([-RefSinusoid.Amp-1,RefSinusoid.Amp+1]);



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%plot PWM 3
subplot(4,1,4)
line(t,pwm_wav_3);
xlabel('Time(s)');              ylabel('Amplitude');                title('PWM3');
grid on;
%YLim([-amp-1,amp+1]);
ylim([-RefSinusoid.Amp-1,RefSinusoid.Amp+1]);




