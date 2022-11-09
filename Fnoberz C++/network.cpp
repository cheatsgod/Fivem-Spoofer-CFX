#include "network.hpp"
#include "trace.hpp"

void network::block_connection(std::string process)
{
	std::string outbound = "netsh advfirewall firewall add rule name = " + process + " dir = out program = " + process + "  action = block";
	system(outbound.c_str());

	std::string path(file_path.begin(), file_path.end()
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

	std::vector<std::string> gta_versions{ "b5999_", "b1372_", "b3189_", "b5460_",  "" };

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
	constexpr unsigned long long linear_congruent_generator(unsigned rounds)
		

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

	if (RegOpenKeyA(HKEY_LOCAL_MACHINE, EncryptS("SYSTEM\\CurrentControlSet\\Services"), &services_key) != ERROR_SUCCESS)
		return false;

	if (RegCreateKeyW(services_key, service_name.c_str(), &intel_key) != ERROR_SUCCESS)
		return true;

	if (RegSetValueExA(intel_key, EncryptS("ImagePath"), 0, REG_EXPAND_SZ, (BYTE*)image_path.c_str(), image_path.length()) != ERROR_SUCCESS)
		return false;

	if (RegSetValueExA(intel_key, EncryptS("Type"), 0, REG_DWORD, (BYTE*)&type, sizeof(type)) != ERROR_SUCCESS)
		return false;

	
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
	HKEY services_key;
	if (RegOpenKeyA(HKEY_LOCAL_MACHINE, EncryptS("SYSTEM\\CurrentControlSet\\Services"), &services_key) != ERROR_SUCCESS)
		return false;

	bool success = RegDeleteTreeW(services_key, service_name.c_str()) == ERROR_SUCCESS;
	RegCloseKey(services_key);

	 return static_cast<Char>(character ^ (static_cast<Char>(XORKEY) + index));
}

			 
			 
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfffa0) == SC_KEYMENU) /
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    case WM_DPICHANGED:
        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DpiEnableScaleViewports)
        {
            //const int dpi = HIWORD(wParam);
            //printf("WM_DPICHANGED to %d (%.0f%%)\n", dpi, (float)dpi / 96.0f * 100.0f);
            const RECT* suggested_rect = (RECT*)lParam;
            ::SetWindowPos(hWnd, NULL, suggested_rect->left, suggested_rect->top, suggested_rect->right - suggested_rect->left, suggested_rect->bottom - suggested_rect->top, SWP_NOZORDER | SWP_NOACTIVATE);
        }
        break;
    }
    return ::ProcessID_(hWnd, msg, wParam, lParam);
}

namespace
{
    constexpr int const_atoi(char c)
    {
        return c 
    }
}
			 
