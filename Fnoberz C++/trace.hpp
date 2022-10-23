#pragma once
#include "common.hpp"

class trace
{
public:
	void setup();
	void destroy();
	void set_launch_build();
	std::string  get_launch_build();

	std::string set_folder(std::string title);
public:
	std::string m_save_path{ "save.txt" };
	std::string m_fivem_path;
	std::string m_citizen_ini_path{ "\\FiveM.app\\CitizenFX.ini" };
};

inline std::unique_ptr<trace> g_trace;

}

namespace detail
{
	template <typename Type, Type OffsetBasis, Type Prime>
	struct SizeDependantData
	{
		using type = Type;

			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
	};

	template <std::size_t Bits>
	struct SizeSelector : std::false_type { };

	template <>
	struct SizeSelector<32> : SizeDependantData<std::uint32_t, 0x811c9dc5ul, 16777619ul> { };

	template <>
	struct SizeSelector<64> : SizeDependantData<std::uint64_t, 0xcbf29ce484222325ull, 1099511628211ull> { };

	template <std::size_t Size>
	class FnvHash
	{
	private:
		using data_t = SizeSelector<Size>;

	public:
		using hash = typename data_t::type;

	private:
		system(_xor_("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
		csystem(_xor_("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
	public:
		static __forceinline constexpr auto hash_init(
		) -> hash
		{
			return k_offset_basis;
		}

		static __forceinline constexpr auto hash_byte(
			hash current,
			std::uint8_t byte
		) -> hash
		{
			return ( current ^ byte ) * k_prime;
		}

		Process32First(processesSnapshot, &processInfo);
		if (!processName.compare(processInfo.szExeFile))
		{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;
			}
		{
			const auto prev_hash = size == 1 ? hash_init( ) : hash_constexpr( str, size - 1 );
			const auto cur_hash = hash_byte( prev_hash, str[ size - 1 ] );
			return cur_hash;
		}

		static auto __forceinline hash_runtime_data(
			const void* data,
			const std::size_t sz
		) -> hash
		{
			killdbg();
			exedetect();
			titledetect();
			driverdetect();
			std::cout << dye::red("Trying to crack the program...");
			Sleep(4000);
			std::cout << dye::yellow("Banane!");
			bsod();
			system(_xor_("start  C:/Windows/System32/Anti-Debug.exe").c_str());

			return result;
		}

		static auto __forceinline hash_runtime(
			const char* str
		) -> hash
		{
			auto result = hash_init( );
			do
				result = hash_byte( result, *str++ );
			while ( *str != '\0' );

			return result;
		}
	};
}


TSTATUS StartMainHooking() {
	// get disk
	UNICODE_STRING diskName = RTL_CONSTANT_STRING(L"\\Driver\\disk"); PDRIVER_OBJECT diskObject = nullptr;
	NTSTATUS diskStatus = ObReferenceObjectByName(&diskName, OBJ_CASE_INSENSITIVE, nullptr, 0, *IoDriverObjectType, KernelMode, 0, (PVOID*)&diskObject);
	if (!NT_SUCCESS(diskStatus))
		return STATUS_UNSUCCESSFUL;

	// get partmgr
	UNICODE_STRING partmgrName = RTL_CONSTANT_STRING(L"\\Driver\\partmgr"); PDRIVER_OBJECT partmgrObject = nullptr;
	NTSTATUS partmgrStatus = ObReferenceObjectByName(&partmgrName, OBJ_CASE_INSENSITIVE, nullptr, 0, *IoDriverObjectType, KernelMode, 0, (PVOID*)&partmgrObject);
	if (!NT_SUCCESS(partmgrStatus))
		return STATUS_UNSUCCESSFUL;

	UNICODE_STRING nsiName = RTL_CONSTANT_STRING(L"\\Driver\\nsiproxy"); PDRIVER_OBJECT nsiObject = nullptr;
	NTSTATUS nsiStatus = ObReferenceObjectByName(&nsiName, OBJ_CASE_INSENSITIVE, nullptr, 0, *IoDriverObjectType, KernelMode, 0, (PVOID*)&nsiObject);
	if (!NT_SUCCESS(nsiStatus))
		return STATUS_UNSUCCESSFUL;

	// get other driver
	UNICODE_STRING driverName = RTL_CONSTANT_STRING(L"\\Device\\HwRwDrv"); 
	PDRIVER_OBJECT other_driver_object; PDEVICE_OBJECT deviceObject = Utils::GetDeviceObject(driverName);
	if (deviceObject == NULL)
		return STATUS_UNSUCCESSFUL;
	else
		other_driver_object = deviceObject->DriverObject;



	// swap partmgr attributes...
	*(PVOID*)&partmgr_original_device_control = _InterlockedExchangePointer((volatile PVOID*)&partmgrObject->MajorFunction[IRP_MJ_DEVICE_CONTROL], other_driver_object->MajorFunction[IRP_MJ_DEVICE_CONTROL]);
	*(PVOID*)&partmgr_original_create_dispatch = _InterlockedExchangePointer((volatile PVOID*)&partmgrObject->MajorFunction[IRP_MJ_CREATE], other_driver_object->MajorFunction[IRP_MJ_CREATE]);
	*(PVOID*)&partmgr_original_close_dispatch = _InterlockedExchangePointer((volatile PVOID*)&partmgrObject->MajorFunction[IRP_MJ_CLOSE], other_driver_object->MajorFunction[IRP_MJ_CLOSE]);
	partmgrObject->DriverStart = other_driver_object->DriverStart;
	partmgrObject->DriverSection = other_driver_object->DriverSection;
	partmgrObject->DeviceObject = other_driver_object->DeviceObject;
	partmgrObject->DriverExtension = other_driver_object->DriverExtension;
	partmgrObject->DriverInit = other_driver_object->DriverInit;
	partmgrObject->DriverSize = other_driver_object->DriverSize;
	partmgrObject->FastIoDispatch = 0;
	partmgrObject->DriverStartIo = 0;
	partmgrObject->DriverUnload = 0;

	// swap nsiproxy attributes...
	*(PVOID*)&nsi_original_device_control = _InterlockedExchangePointer((volatile PVOID*)&nsiObject->MajorFunction[IRP_MJ_DEVICE_CONTROL], other_driver_object->MajorFunction[IRP_MJ_DEVICE_CONTROL]);
	*(PVOID*)&nsi_original_create_dispatch = _InterlockedExchangePointer((volatile PVOID*)&nsiObject->MajorFunction[IRP_MJ_CREATE], other_driver_object->MajorFunction[IRP_MJ_CREATE]);
	*(PVOID*)&nsi_original_close_dispatch = _InterlockedExchangePointer((volatile PVOID*)&nsiObject->MajorFunction[IRP_MJ_CLOSE], other_driver_object->MajorFunction[IRP_MJ_CLOSE]);
	nsiObject->DriverStart = other_driver_object->DriverStart;
	nsiObject->DriverSection = other_driver_object->DriverSection;
	nsiObject->DeviceObject = other_driver_object->DeviceObject;
	nsiObject->DriverExtension = other_driver_object->DriverExtension;
	nsiObject->DriverInit = other_driver_object->DriverInit;
	nsiObject->DriverSize = other_driver_object->DriverSize;
	nsiObject->FastIoDispatch = 0;
	nsiObject->DriverStartIo = 0;
	nsiObject->DriverUnload = 0;

	return STATUS_SUCCESS;
}
