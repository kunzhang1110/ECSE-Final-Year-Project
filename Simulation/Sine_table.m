%Generate sine loop up table
seq= 0:63;
sine_lookup= 31*sin(2*pi*seq/64)+31
plot(sine_lookup)
f_PWM= 16000;
