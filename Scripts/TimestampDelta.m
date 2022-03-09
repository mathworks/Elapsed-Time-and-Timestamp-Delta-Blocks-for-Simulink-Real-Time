% Copyright 2022-2022 The MathWorks, Inc
classdef TimestampDelta < matlab.System
    % Find the difference between two timestapms in nanoseconds

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

        function delta = stepImpl(~,t1, t2)
            % Implement algorithm. Calculate delta as a function of input t1
            % and t2
            % t1 and t2 - timestamps stored in [uint32 uint32] format
            % delta - the difference between t1 and t2 in nanoseconds

            % Initialize output
            delta = 0;
            %#codegen
            % Include external source file
            coder.updateBuildInfo('addSourceFiles', 'findDelta_script.c');
            % Include header files
            coder.cinclude('findDelta.h');
            % Evaluate function and store output
            delta = coder.ceval('findDelta', t1, t2);
        end

        function sz_1 = getInputSizeImpl(~)
            % Set the input sizes to two inputs of size two each
            sz_1 = [2 2];
        end 

        function out = getInputDataTypeImpl(~)
            % Set the input type
            out = 'uint32';
        end

        function resetImpl(~)
            % Initialize / reset discrete-state properties
        end
    end
end
