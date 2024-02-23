// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include <string>
#include "picam.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}



extern "C" __declspec(dllexport) void InitCamera(int* initCode, char* initMessage);
extern "C" __declspec(dllexport) void InitCamera(int* initCode, char* initMessage)
{
    Picam_InitializeLibrary();
    *initCode = 11100;
    std::string test = "PICam Initialized";
    strcpy_s(initMessage, test.length() + 1, test.c_str());
}

extern "C" __declspec(dllexport) void UninitCamera(int* uninitCode, char* uninitMessage);
extern "C" __declspec(dllexport) void UninitCamera(int* uninitCode, char* uninitMessage)
{
	Picam_UninitializeLibrary();
    *uninitCode = 10011;
    std::string test = "PICam Uninitialized";
    strcpy_s(uninitMessage, test.length() + 1, test.c_str());
}

extern "C" __declspec(dllexport) void OpenDemoMax3(char* openCameraMessage, char* sensorName, char* closeCameraMessage, unsigned short* image);
extern "C" __declspec(dllexport) void OpenDemoMax3(char* openCameraMessage, char* sensorName, char* closeCameraMessage, unsigned short* image)
{
    PicamHandle camera;
	PicamCameraID id;
    piint readoutStride = 0;
    PicamAvailableData data;
    PicamAcquisitionErrorsMask errors;
    pi16u* frameStartPtr;
    //const int frame1DLength = 0;
    //int fullFrame[frame1DLength];

    Picam_ConnectDemoCamera(
        PicamModel_PIMax31024I,
        "12345",
        &id);
    Picam_OpenCamera(&id, &camera);
    std::string tempString = "DemoPIMAX3 Opened";
    strcpy_s(openCameraMessage, tempString.length() + 1, tempString.c_str());

    //Get the readout stride which is the number of pixels multiplied by 2 (16 bits are 2 bytes)
    Picam_GetParameterIntegerValue(camera, PicamParameter_ReadoutStride, &readoutStride);


    //std::string sensor = id.sensor_name;
    //strcpy_s(sensorName,sensor.length()+1, sensor.c_str());
    strcpy_s(sensorName, 100, id.sensor_name);

    //Take one frame without any timeout 
    Picam_Acquire(camera, 1, -1, &data, &errors);
    frameStartPtr = (pi16u*)data.initial_readout;
    for (int i = 0; i < readoutStride/2; i++)
    {
        image[i] = (unsigned short)*(frameStartPtr + i);
    }

    Picam_CloseCamera(camera);
    tempString = "DemoPIMAX3 Closed";
    strcpy_s(closeCameraMessage, tempString.length() + 1, tempString.c_str());
}