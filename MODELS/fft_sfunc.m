function fft_sfunc(block)
 
% Level-2 M file S-Function.
%  Two-tap FIR filter implementation for frame-based and sample-based signals.
%  Filter coefficients are passed as block parameters.
%
%   Copyright 2009 The MathWorks, Inc.
% $Revision: 1.1.6.1 $ $Date: 2009/11/13 05:06:08 $
        
setup(block);
 
function setup(block)
  % Register number of ports.
  block.NumInputPorts  = 2;
  block.NumOutputPorts = 1;
 
  % In Accelerator mode, the block runs on TLC.
  block.SetAccelRunOnTLC(true);
 
  % Set up the functional port properties.
  block.SetPreCompInpPortInfoToDynamic;
  block.SetPreCompOutPortInfoToDynamic;
 
  % Set up the inport data-type properties.
  block.InputPort(1).DatatypeID  = -1;
  block.InputPort(1).Complexity  = 'Real';
 
  block.InputPort(2).DatatypeID  = -1;
  block.InputPort(2).Complexity  = 'Real';
  
  % Set up the outport data-type properties.
  block.OutputPort(1).DatatypeID  = -1;
  block.OutputPort(1).Complexity  = 'Complex';
 
  % Register the parameters.
  block.NumDialogPrms     = 0;
 
  % Register the methods.
  % Note that the Output method is registered in DoPostProp as it
  % requires knowledge about the signal sampling mode.
  block.RegBlockMethod('SetInputPortDimensions',  @SetInpPortDims);
  block.RegBlockMethod('SetOutputPortDimensions', @SetOutPortDims);
  block.RegBlockMethod('SetInputPortSamplingMode',@SetInpPortFrameData);
  block.RegBlockMethod('PostPropagationSetup',    @DoPostPropSetup);
  block.RegBlockMethod('Start',                   @Start);
  block.RegBlockMethod('WriteRTW',                @WriteRTW);
  
function SetInpPortDims(block, idx, di)
  % Set the port dimensions for forward propagation of the dimensions.
  block.InputPort(idx).Dimensions = di;
  block.OutputPort(1).Dimensions  = di;
 
function SetOutPortDims(block, idx, di)
  % Set the port dimensions for backward propagation of the dimensions.
  block.InputPort(1).Dimensions    = di;
  block.InputPort(2).Dimensions    = di;
  block.OutputPort(idx).Dimensions = di;
 
 
function SetInpPortFrameData(block, idx, fd)
  % Set the block sampling mode to Frame or Sample depending on the
  % sampling mode of the input signal.
  block.InputPort(idx).SamplingMode  = fd;
  block.OutputPort(1).SamplingMode = fd;
 
 
function DoPostPropSetup(block)
  % Set the proper Output method based on the sampling mode.  
    block.RegBlockMethod('Outputs', @OutputFrame);
 
 
  % Set up the dwork vector or scalar.
  block.NumDworks = 0;
  
function Start(block)
  % Initialize the data.
  
function OutputFrame(block)
  % Output method for the frame-based signals.
  
  % Get the input data and allocate space for the output signal.
 block.OutputPort(1).Data = fft(block.InputPort(1).Data + 1j* block.InputPort(2).Data);
