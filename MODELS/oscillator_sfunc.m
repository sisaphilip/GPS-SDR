function oscillator_sfunc()
%MSFUNTMPL A template for an M-file S-function
%   The M-file S-function is written as a MATLAB function with the
%   same name as the S-function. Replace 'msfuntmpl' with the name
%   of your S-function.
%
%   It should be noted that the M-file S-function is very similar
%   to Level-2 C-Mex S-functions. You should be able to get more
%   information for each of the block methods by referring to the
%   documentation for C-Mex S-functions.
%
%   Copyright 2003-2009 The MathWorks, Inc.
%   $Revision: 1.1.6.17 $
 
%
% The setup method is used to setup the basic attributes of the
% S-function such as ports, parameters, etc. Do not add any other
% calls to the main body of the function.
%
setup();

%endfunction
 
% Function: setup ===================================================
% Abstract:
%   Set up the S-function block's basic characteristics such as:
%   - Input ports
%   - Output ports
%   - Dialog parameters
%   - Options
%
%   Required         : Yes
%   C-Mex counterpart: mdlInitializeSizes
%
function setup()
 
% Register the number of ports.
block.NumInputPorts  = 0;
block.NumOutputPorts = 2;
 
% Set up the port properties to be inherited or dynamic.
block.SetPreCompOutPortInfoToDynamic;
 
% Override the output port properties.
% trigger
block.OutputPort(1).DatatypeID  = 0; % boolean
block.OutputPort(1).Complexity  = 'Real';
block.OutputPort(1).SamplingMode = 'Sample';
block.OutputPort(1).Dimensions   = [56000 1];
 
% Override the output port properties.
% trigger
block.OutputPort(2).DatatypeID  = 0; % boolean
block.OutputPort(2).Complexity  = 'Real';
block.OutputPort(2).SamplingMode = 'Sample';
block.OutputPort(2).Dimensions   = [56000 1];
 
% Register the parameters.
block.NumDialogPrms     = 1;
block.DialogPrmsTunable = {'Tunable'};
block.DialogPrm(1).DataTypeId = 0;
 
% Set up the continuous states.
block.NumContStates = 1;
 
% Register the sample times.
 
block.SampleTimes = [-1 0];
 
% -----------------------------------------------------------------
% Options
% -----------------------------------------------------------------
% Specify if Accelerator should use TLC or call back to the
% M-file
block.SetAccelRunOnTLC(false);
 
% Specify the block simStateCompliance. The allowed values are:
%    'UnknownSimState', < The default setting; warn and assume DefaultSimState
%    'DefaultSimState', < Same SimState as a built-in block
%    'HasNoSimState',   < No SimState
%    'CustomSimState',  < Has GetSimState and SetSimState methods
%    'DisallowSimState' < Errors out when saving or restoring the SimState
block.SimStateCompliance = 'DefaultSimState';
 
% -----------------------------------------------------------------
% The M-file S-function uses an internal registry for all
% block methods. You should register all relevant methods
% (optional and required) as illustrated below. You may choose
% any suitable name for the methods and implement these methods
% as local functions within the same file.
% -----------------------------------------------------------------
 
% -----------------------------------------------------------------
% Register the methods called during update diagram/compilation.
% -----------------------------------------------------------------
 
%% Register methods
block.RegBlockMethod('CheckParameters',         @CheckPrms);
block.RegBlockMethod('ProcessParameters',       @ProcessPrms);
block.RegBlockMethod('PostPropagationSetup',    @DoPostPropSetup);
block.RegBlockMethod('Start',                   @Start);
block.RegBlockMethod('WriteRTW',                @WriteRTW);
block.RegBlockMethod('Outputs',                 @Outputs);
 
% -------------------------------------------------------------------
% The local functions below are provided to illustrate how you may implement
% the various block methods listed above.
% -------------------------------------------------------------------
 
function CheckPrms()
 
a = block.DialogPrm(1).Data;
if ~strcmp(class(a), 'double')
    DAStudio.error('Simulink:block:invalidParameter');
end
 
%endfunction
 
function ProcessPrms()
 
block.AutoUpdateRuntimePrms;
 
%endfunction
 
function DoPostPropSetup()
 
block.NumDworks = 0;
 
block.AutoRegRuntimePrms;
 
%endfunction
 
function Start()
 
  
function WriteRTW()
 
block.WriteRTWParam('string', 'Mode', 'Auto');
 
%endfunction
 
function Outputs()
ts = block.RuntimePrm(1).Data;
load acq_data
block.OutputPort(1).Data = sin((0:56000)' * 2 * pi * ts*IFval);
block.OutputPort(2).Data = cos((0:56000)' * 2 * pi * ts*IFval);
 
%endfunction
