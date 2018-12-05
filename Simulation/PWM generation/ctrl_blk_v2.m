function	ctrl_sig = ctrl_blk_v2(phase_a,phase_b,t)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                                                                                                               %
%           The aim of the function is:
%           To generate PWM signals in real-time using iteration                                                                                                                                  %
%           Version 2, written by Kun Zhang
%           t:input from simulink digital clock
%                                                                                                                                                               %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
global ton tstart

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
REF_AMP= 1;                     %magnitude of reference
REF_FREQ= 50;                   %frequency of reference
REC_FREQ= 200;                  %frequency of PWM 
REC_PER= 1/REC_FREQ;            %period of PWM 
VON= REF_AMP*2;                 %set on voltage =2* reference voltage

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
phase_a= phase_a+REF_AMP;                       %shift phase_a by REF_AMP
phase_b= phase_b+REF_AMP;                       %shift phase_b by REF_AMP
phase_c= -phase_a-phase_b;                      %phase_c obatined by phase_a and phase_b

if t>tstart+REC_PER;
            D= phase_a/von;                     %duty cycle for phase a
            tstart= t;                          %record the start time
            ton= D*REC_PER;                     %on time
elseif t<=(tstart+ton)
                        pwm_1= von;             %pwm1 on               
                        pwm_2= 0;               %pwm2 off
    else
                        pwm_1= von;             %pwm1 on               
                        pwm_2= 0;               %pwm2 off
end

if t>tstart+REC_PER;
            D= phase_b/von;                     %duty cycle for phase b
            tstart= t;                          %record the start time
            ton= D*REC_PER;                     %on time
elseif t<=(tstart+ton)
                        pwm_3= von;             %pwm3 on               
                        pwm_4= 0;               %pwm4 off
    else
                        pwm_3= von;             %pwm3 on               
                        pwm_4= 0;               %pwm4 off
end

if t>tstart+REC_PER;
            D= phase_c/von;                     %duty cycle for phase a
            tstart= t;                          %record the start time
            ton= D*REC_PER;                     %on time
elseif t<=(tstart+ton)
                        pwm_5= von;             %pwm5 on               
                        pwm_6= 0;               %pwm6 off
    else
                        pwm_5= von;             %pwm5 on               
                        pwm_6= 0;               %pwm6 off
end

ctrl_sig =[pwm_1 pwm_2 pwm_3 pwm_4 pwm_5 pwm_6];        %output















