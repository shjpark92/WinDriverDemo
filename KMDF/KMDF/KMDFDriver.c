#include <ntddk.h>
#include <wdf.h>
DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD KMDFEvtDeviceAdd;

NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT  DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	NTSTATUS status;
	WDF_DRIVER_CONFIG config;

	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KMDF: DriverEntry\n"));
	WDF_DRIVER_CONFIG_INIT(&config, KMDFEvtDeviceAdd);
	status = WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);
	return status;
}

NTSTATUS KMDFEvtDeviceAdd(_In_ WDFDRIVER Driver, _Inout_ PWDFDEVICE_INIT DeviceInit)
{
	NTSTATUS status;
	WDFDEVICE hDevice;
	UNREFERENCED_PARAMETER(Driver);

	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KMDF: KMDFEvtDeviceAdd\n"));
	status = WdfDeviceCreate(&DeviceInit, WDF_NO_OBJECT_ATTRIBUTES, &hDevice);
	return status;
}