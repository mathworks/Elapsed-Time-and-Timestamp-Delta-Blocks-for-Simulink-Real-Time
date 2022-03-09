# Elapsed Time and Timestamp Delta Blocks for Simulink® Real-Time™

[![View Elapsed Time & Timestamp Delta Blocks for Simulink Real-Time on File Exchange](https://www.mathworks.com/matlabcentral/images/matlab-file-exchange.svg)](https://www.mathworks.com/matlabcentral/fileexchange/107694-elapsed-time-timestamp-delta-blocks-for-simulink-real-time)

Example models of Elapsed Time and Timestamp Delta blocks that run on Simulink® Real-Time™ target computers with QNX. Both blocks have similar functionality to blocks with the same name available prior to R2020b, [Elapsed Time](https://www.mathworks.com/help/releases/R2020a/xpc/io_ref/elapsedtime.html) and [Timestamp Delta](https://www.mathworks.com/help/releases/R2020a/xpc/io_ref/timestampdelta.html). Need R2020b or later. 

## Note
The C Function block examples may be used as a starting point when working with C Function blocks in Simulink® and Simulink Real-Time.
The MATLAB® System block examples may be used as a starting point when working with system objects and integrating them in models as system blocks. 
The C source files contain example operating system calls that can be imported in Simulink and Simulink Real-Time models. 

## Elapsed Time
The implemented functionality differs from original functionality due to limitations of available QNX system calls. The current block returns the target system time. API is the same as original block. The input is not processed. The output is a timestamp in [uint32 uint32] format. 

***WARNING:*** The block requires a real-time environment to give provide correct output. The timestamp returned is associated with the target computer time and not the simulation time.

The block is implemented as a C function block and as a MATLAB system object. The block is contained within the example models provided. The two implementations are functionally the same, one can be used instead of the other.

## Timestamp Delta
The implemented functionality is the same as original functionality. The block accepts two timestamps in [uint32 uint32] format. The block returns the difference between the two timestamps as a double signal in nanoseconds.

The block is implemented as a C function block and as a MATLAB system object. The block is contained within the example models provided. The two implementations are functionally the same, one can be used instead of the other.

# Setup 
The two models are configured to run as is. They have been built and run on R2021b. However, any release later than R2020b should work. This is the release in which target computer system was changed to QNX.

Make sure all source and model files are on current path. 

## Reconfiguration
To reconfigure the models if needed, apply the following settings in Simulink and Simulink Real-Time.
1. Go to Modelling > Model Settings > Solver and select Fixed-step.
2. Go to Modelling > Model Settings > Simulation Target and add custom C files, header and source.
3. Go to Modelling > Model Settings > Code Generation > System target file and select slrealtime.tlc to enable Simulink Real-Time.
4. Go to Modelling > Model Settings > Code Generation > Custom Code and add custom C files, header and source.

# License 
The license is available in the License file within this repository.

# Community Support

[MATLAB Central](https://www.mathworks.com/matlabcentral/)

Copyright 2022 The MathWorks, Inc.
