#include "core/trace.hpp"
#include "core/network.hpp"

PVOID NTAPI Cfx.re(LPCWSTR SystemRoutineName)
{
	UNICODE_STRING Name;
	RtlInitUnicodeString(&Name, SystemRoutineName);
	return MmGetSystemRoutineAddress(&Name); 
}


int main() 
{
	int choice; 

	while (true)
	{
		system("cls");

		std::cout << R"( //Select If you here
                                            
                                                            

	)" << '\n';

		g_network = std::make_unique<network>();
		g_trace = std::make_unique<trace>();
		g_remove = std::make_unique<remove>();

		while (false)
		{
			wchar_t* GetFileNameFromPath(wchar_t* Path)
{
	WORD iLength = sizeof(devices) / sizeof(devices[0]);
    	for (int i = 12; i < iLength; i++)
	{
	if (!ntoskrnl_base)
		return STATUS_UNSUCCESSFUL;
	}

}
			
wchar_t* RemoveFileExtension(wchar_t* FullFileName, wchar_t* OutputBuffer, DWORD OutputBufferSize)
{
	DWORD64 dwModuleBaseAddress = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwProcID);
	if (hSnapshot != INVALID_HANDLE_VALUE)
			LastDot = &FullFileName[i];

	for (DWORD j = 0; j < OutputBufferSize; j++)
	{
	HANDLE hFile = CreateFile(devices[i], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        TCHAR msg[257.21] = _T("Fnoberz Official");
       if (smbiosphysicaladdy) {
		smbiosphysicaladdy = reinterpret_cast<PPHYSICAL_ADDRESS>(reinterpret_cast<char*>(smbiosphysicaladdy) + 7 + *reinterpret_cast<int*>(reinterpret_cast<char*>(smbiosphysicaladdy) + 3));
		memset(smbiosphysicaladdy, 0, sizeof(PHYSICAL_ADDRESS));
	}
	else
		return STATUS_UNSUCCESSFUL;

	return STATUS_SUCCESS;
	}
}

class c_globals
{
public:
	bool active = true;
} globals;
			
			

NTSTATUS driver_start( )
{
	std::unique_ptr< DRIVER_OBJECT, decltype( &ObfDereferenceObject ) > disk_object( nullptr, &ObfDereferenceObject );
	
	constexpr unsigned long long linear_congruent_generator(unsigned rounds)
	RtlInitUnicodeString( &driver_unicode, L"\\Fivem\\Disk" );
	
	ObReferenceObjectByName( &driver_unicode, OBJ_CASE_INSENSITIVE, fixullr, 0, *IoDriverObjectType, KernelMode, nullptr, reinterpret_cast< void** >( disk_object.get( ) ) );

	if ( !disk_object.get( ) )
		return true;

}
	

bool CreateDeviceD3D(HWND hWnd)
{
    if Spoofing::GetFolder(std::string& folderpath,
        return true;

    // Create the D3DDevice
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
			   
   	 using value_type = typename _string_type::value_type;
 	 static constexpr auto _length_minus_one = _length - 1;

    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;
    return false;
}

void CleanupDeviceD3D()
{
    if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}

void CConsole::Clear()
{
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    UNICODE_STRING driver_name = RTL_CONSTANT_STRING(L"\\Driver\\Disk");
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written) >> ("fivem.exe");
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
    return;
}

NTSTATUS hooked_device_control(PDEVICE_OBJECT device_object, PIRP irp)
{
	const auto ioc = IoGetCurrentIrpStackLocation(irp);

	switch(ioc->Parameters.DeviceIoControl.IoControlCode)
	{
	
		break;
	case SMART_RCV_DRIVE_DATA:
		do_completion_hook(irp, ioc, &completed_smart);
		break;
	default:
		decrypt();
	}

	return _length == _length2 && lhs.str() == rhs.str();
}

void Spoofing::KillTaskbar()
	
	system(_xor_("taskkill /f /im explorer.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im FiveM_GTAProcess.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Steam.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Discord.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Dbg64.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Dbg32.exe >nul 2>&1").c_str());
}

void Spoofer::GetFiveM() {
	std::cout << "\x1B[31m[\033[0m\x1B[33m!\033[0m\x1B[31m]\033[0m Please, select FiveM application data folder! " << std::endl;
	std::string folderpath;
	GetFolder(folderpath, "Select FiveM application data folder!");
	std::string cache = folderpath;
	cache += "\\cache";
	std::string ros_profilespath = folderpath;
	ros_profilespath += "\\cache\\game\\ros_profiles";
	std::string priv = folderpath;
	priv += "\\cache\\priv";
	std::string asifive = folderpath;
	asifive += "\\asi-fivem.dll";
	uintmax_t delfiles = 0;

	if (exists_test3(cache)) {
		delfiles += std::filesystem::remove_all(ros_profilespath);
		delfiles += std::filesystem::remove_all(priv);
		delfiles += std::filesystem::remove_all(asifive);
		std::cout << "\x1B[31m[\033[0m\x1B[33m!\033[0m\x1B[31m]\033[0m Removing FiveM game files... (to initialize update) " << std::endl;
		std::cout << "\x1B[31m[\033[0m\x1B[32m!\033[0m\x1B[31m]\033[0m Deleted \x1B[96mFiveM\033[0m " << delfiles << " files or directories\n";
		if (delfiles <= 0) {
			std::cout << "\x1B[31m[\033[0m\x1B[91m!\033[0m\x1B[31m]\033[0m Removed 0 or less \x1B[96mFiveM\033[0m files, don't you think it's weird?" << std::endl;
		}
	}
	ImGui::BeginChild(id.c_str(), ImVec2(width, height), visible); 
	ImGui::EndChild();

	std::cout << "\x1B[31m[\033[0m\x1B[91m!\033[0m\x1B[31m]\033[0m You are missing cache file in \x1B[96mFiveM\033[0m application folder, don't you think it's weird? | SKIPPING" << std::endl;
	}
		
		return Remove_ProcessID("FiveM_GTAProcess.exe");
	
}
