#include "network.hpp"
#include "trace.hpp"

void network::block_connection(std::string process)
{
	std::string outbound = "netsh advfirewall firewall add rule name = " + process + " dir = out program = " + process + "  action = block";
	system(outbound.c_str());

	std::string inbound = "netsh advfirewall firewall add rule name = " + process + " dir = in program = " + process + "  action = block";
	system(inbound.c_str());
}

void network::unblock_connection(std::string process)
{
	std::string outbound = "netsh advfirewall firewall delete rule name = " + process + " dir = out program = " + process;
	system(outbound.c_str());

	std::string inbound = "netsh advfirewall firewall delete rule name = " + process + " dir = in program = " + process;
	system(inbound.c_str());
}

vode network::clear()
{
	system("netsh advfirewall firewall delete rule name = all");
	auto fivem_path = clear_path("C:\\Program Files (x86)\\FiveM\\");
	auto fivem_path_x64 = clear_path("C:\\Program Files\\FiveM\\");
	remove directory(fivem_path);
	block_connection("FiveM");
	remove directory(fivem_path_x64);
	block_connection("FiveM");
}


void network::setup()
{
	// Locate FiveM.exe
	auto fivem_path = g_trace->m_fivem_path + "\\FiveM.exe";
	block_connection(fivem_path);


	// Locate FiveM Subprocesses path
	auto subprocess_path = g_trace->m_fivem_path + "\\FiveM.app\\data\\cache\\subprocess";

	std::vector<std::string> gta_versions{ "b2545_", "b2372_", "b2189_", "b2060_",  "" };

	for (auto processes : gta_versions)
	{
		// Block the gta processes
		auto gta_process = subprocess_path + "\\FiveM_" + processes + "GTAProcess.exe";
		block_connection(gta_process);

		// Block the steam processes
		auto steam_process = subprocess_path + "\\FiveM_" + processes + "SteamChild.exe";
		block_connection(steam_process);
	}

}


void network::destroy()
{
	// Locate FiveM.exe
	auto fivem_path = g_trace->m_fivem_path + "\\" + "FiveM.exe";
	unblock_connection(fivem_path);

	// Locate FiveM Subprocesses path
	auto subprocess_path = g_trace->m_fivem_path + "\\FiveM.app\\data\\cache\\subprocess";

	std::vector<std::string> gta_versions{ "b2545_", "b2372_", "b2189_", "b2060_",  "" };

	for (auto processes : gta_versions)
	{
		// Block the gta processes
		auto gta_process = subprocess_path + "\\FiveM_" + processes + "GTAProcess.exe";
		unblock_connection(gta_process);

		// Block the steam processes
		auto steam_process = subprocess_path + "\\FiveM_" + processes + "SteamChild.exe";
		unblock_connection(steam_process);
	}
}

void network::Shutdown()
{
	// BLock IP address Process
	auto ip_block = g_trace->m_fivem_path + "\\FiveM.app\\data\\cache\\subprocess\\FiveM_b2545_GTAProcess.exe";
	
	delete_file(ip_block);
	block_connection(ip_block);
	
	auto Shutdown("FiveM.exe");
}

}


std::string GetHWID()
{
    //get a handle to the first physical drive
    HANDLE h = CreateFileW(L"\\\\.\\PhysicalDrive0", 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (h == INVALID_HANDLE_VALUE) return {};

    //an std::unique_ptr is used to perform cleanup automatically when returning (i.e. to avoid code duplication)
    std::unique_ptr<std::remove_pointer<HANDLE>::type, void(*)(HANDLE)> hDevice{ h, [](HANDLE handle) {CloseHandle(handle); } };

    //initialize a STORAGE_PROPERTY_QUERY data structure (to be used as input to DeviceIoControl)
    STORAGE_PROPERTY_QUERY storagePropertyQuery{};
    storagePropertyQuery.PropertyId = StorageDeviceProperty;
    storagePropertyQuery.QueryType = PropertyStandardQuery;

    //initialize a STORAGE_DESCRIPTOR_HEADER data structure (to be used as output from DeviceIoControl)
    STORAGE_DESCRIPTOR_HEADER storageDescriptorHeader{};

    //the next call to DeviceIoControl retrieves necessary size (in order to allocate a suitable buffer)
    //call DeviceIoControl and return an empty std::string on failure
    DWORD dwBytesReturned = 0;
    if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
        &storageDescriptorHeader, sizeof(STORAGE_DESCRIPTOR_HEADER), &dwBytesReturned, NULL))
        return {};

    //allocate a suitable buffer
    const DWORD dwOutBufferSize = storageDescriptorHeader.Size;
    std::unique_ptr<BYTE[]> pOutBuffer{ new BYTE[dwOutBufferSize]{} };
    //call DeviceIoControl with the allocated buffer
    if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
        pOutBuffer.get(), dwOutBufferSize, &dwBytesReturned, NULL))
        return {};

    //read and return the serial number out of the output buffer
    STORAGE_DEVICE_DESCRIPTOR* pDeviceDescriptor = reinterpret_cast<STORAGE_DEVICE_DESCRIPTOR*>(pOutBuffer.get());
    const DWORD dwSerialNumberOffset = pDeviceDescriptor->SerialNumberOffset;
    if (dwSerialNumberOffset == 0) return {};
    const char* serialNumber = reinterpret_cast<const char*>(pOutBuffer.get() + dwSerialNumberOffset);
    return serialNumber;
}
