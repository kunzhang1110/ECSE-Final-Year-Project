function varargout = GUI_v0(varargin)
% GUI_V0 MATLAB code for GUI_v0.fig
%      GUI_V0, by itself, creates a new GUI_V0 or raises the existing
%      singleton*.
%
%      H = GUI_V0 returns the handle to a new GUI_V0 or the handle to
%      the existing singleton*.
%
%      GUI_V0('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI_V0.M with the given input arguments.
%
%      GUI_V0('Property','Value',...) creates a new GUI_V0 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI_v0_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI_v0_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI_v0

% Last Modified by GUIDE v2.5 20-Aug-2013 08:52:10

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI_v0_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI_v0_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI_v0 is made visible.
function GUI_v0_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI_v0 (see VARARGIN)

% Choose default command line output for GUI_v0
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes GUI_v0 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI_v0_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function Frequency_Callback(hObject, eventdata, handles)
% hObject    handle to Frequency (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Frequency as text
%        str2double(get(hObject,'String')) returns contents of Frequency as a double


% --- Executes during object creation, after setting all properties.
function Frequency_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Frequency (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in OK.
function OK_Callback(hObject, eventdata, handles)
% hObject    handle to OK (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Clear.
function Clear_Callback(hObject, eventdata, handles)
% hObject    handle to Clear (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
