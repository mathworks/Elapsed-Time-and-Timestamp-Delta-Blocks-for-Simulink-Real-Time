% Copyright 2022-2022 The MathWorks, Inc
classdef ElapsedTime < matlab.System
    % Read the target system time

    % Public, tunable properties
    properties
    end

    properties(DiscreteState)
    end

    % Pre-computed constants
    properties(Access = private)
    end

    methods(Access = protected)
        function setupImpl(~)
            % Perform one-time calculations, such as computing constants
        end

        function T = stepImpl(~,input)
            % Implement algorithm. Calculate T by making a system call to
            % the QNX operating system. 
            % Initialize T
            T = uint32(zeros(1,2));
            %#codegen
            % Import external C files
            coder.updateBuildInfo('addSourceFiles', 'getTime_script.c');
            % Import header files
            coder.cinclude('getTime.h');
            % Call external C function with arguments by reference and
            % store output in T
            coder.ceval('findUnixTime', coder.ref(T), input);
        end

        function sz_1 = getOutputSizeImpl(~)
            % Set the output size to two
            sz_1 = [1 2];
        end 

        function out = getOutputDataTypeImpl(~)
            % Set the output type to uint32 
            out = 'uint32';
        end

        function resetImpl(~)
            % Initialize / reset discrete-state properties
        end
    end
end
