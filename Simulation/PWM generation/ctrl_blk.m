function    [ctrl_sig,error]= ctrl_blk(ref_a,ref_b,t,fb_phase_a,fb_phase_b)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                                                                                                               %
%           The aim is to:                                                                                                                                      %                                                           
%           generate 3-phase PWM waveform using principle of PWM in simulink                                                                                    %                      
%           Version 1, written by Kun Zhang                                                                                                                     %                                          
%                                                                                                                                                               %
%           The input parameters are                                                                                                                            %                                               
%           phase_a: reference signal a                                                                                                                         %                              
%           phase_b: reference signal b                                                                                                                         %         
%           t: running time                                                                                                                                     %                      
%           fb_phase_a: feedback signal a                                                                                                                       %                                             
%           fb_phase_a: feedback signal b                                                                                                                       %
%                                                                                                                                                               %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%space reserved for gloabal variables declaration


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Parameter settings
REF_AMP= 1;                         %magnitude of reference
REF_FREQ= 300;                      %frequency of reference
AMP_MOD= 0.9;                       %amplitude modulation ratio=M(control)/M(tri)
FREQ_MOD= 100;                      %frequency modulation ratio=f(tri)/f(control)

TRI_AMP= REF_AMP/AMP_MOD;           %triangluar amplitude
TRI_FREQ= FREQ_MOD*REF_FREQ;        %triangular frequency
TRI_PER= 1/TRI_FREQ;                %triangular period

%SAMP_FREQ= 10*1000000;              %sampling frequency
%SAMP_PER= 1/SAMP_FREQ;              %sampling period


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ref_c= -ref_a-ref_b;                                                                %phase_c obatined by phase_a and phase_b
tri_wav= (2*TRI_AMP/(TRI_PER/2))*abs(mod(t,TRI_PER)-TRI_PER/2)-TRI_AMP;             %triangular wave 

if      (ref_a>tri_wav);                pwm_1= REF_AMP;     
else                                    pwm_1= 0;
end

if      (ref_b>tri_wav);                pwm_3= REF_AMP;                 
else                                    pwm_3= 0;  
end

if      (ref_c>tri_wav);                pwm_5= REF_AMP; 
else                                    pwm_5= 0; 
end

% Delay
% pause on;                pause(2.1*10^-6);                pause off;                %pausing for switching time (typically less than 1us)

%upper switch and lower switch are pairwise invereted
if      pwm_1==0;                       pwm_2= REF_AMP;
else                                    pwm_2= 0;
end

if      pwm_3==0;                       pwm_4= REF_AMP;
else                                    pwm_4= 0;
end

if      pwm_5==0;                       pwm_6= REF_AMP;
else                                    pwm_6= 0;
end

% %Delay
% pause on;                pause(2.1*10^-6);                pause off;                %pausing for switching time (typically less than 1us)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ctrl_sig= [pwm_1 pwm_2 pwm_3 pwm_4 pwm_5 pwm_6];        %PWM output
mag_fb= 200;                                            %magnitude of feedback
error= fb_phase_a-mag_fb*ref_a;                       %error

%plot inverter device voltage
%plot(motor_2kW_Inverter.time,motor_2kW_Inverter.signals.values)
