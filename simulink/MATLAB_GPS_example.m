% Create a serial port object.
obj1 = instrfind('Type', 'serial', 'Port', 'COM4', 'Tag', '');

% Create the serial port object if it does not exist
% otherwise use the object that was found.
if isempty(obj1)
obj1 = serial('COM4');
else
fclose(obj1);
obj1 = obj1(1);
end

% Set the BaudRate
obj1.BaudRate = 4800;

% Connect to instrument object, obj1.
fopen(obj1);

% We only want the strings with $GPGLL…  

data='';
while isempty(strmatch('$GPGLL',data))
data = fscanf(obj1);
end

% Parse the string to obtain coordinates
[lat,data] = strtok(data,',');
[lat,data] = strtok(data,',');
[nsCardinal,data] = strtok(data,',');
[long,data] = strtok(data,',');
[ewCardinal,data] = strtok(data,',');
lat = str2double(lat);
long = str2double(long);

% Display the results
disp({lat,nsCardinal,long,ewCardinal});

% Free the serial port
fclose(obj1);