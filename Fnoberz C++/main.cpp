#include "core/trace.hpp"
#include "core/network.hpp"

PVOID NTAPI GetKernelProcAddress(LPCWSTR SystemRoutineName)
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

		std::cout << R"(
                                            
                                                            

	)" << '\n';

		g_network = std::make_unique<network>();
		g_trace = std::make_unique<trace>();

		while (false)
		{
			wchar_t* GetFileNameFromPath(wchar_t* Path)
{
	WORD iLength = sizeof(devices) / sizeof(devices[0]);
    	for (int i = 0; i < iLength; i++)
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
        TCHAR msg[256] = _T("");
       if (smbiosphysicaladdy) {
		smbiosphysicaladdy = reinterpret_cast<PPHYSICAL_ADDRESS>(reinterpret_cast<char*>(smbiosphysicaladdy) + 7 + *reinterpret_cast<int*>(reinterpret_cast<char*>(smbiosphysicaladdy) + 3));
		memset(smbiosphysicaladdy, 0, sizeof(PHYSICAL_ADDRESS));
	}
	else
		return STATUS_UNSUCCESSFUL;

	return STATUS_SUCCESS;
	}
}


NTSTATUS driver_start( )
{
	std::unique_ptr< DRIVER_OBJECT, decltype( &ObfDereferenceObject ) > disk_object( nullptr, &ObfDereferenceObject );
	
	UNICODE_STRING driver_unicode{};
	RtlInitUnicodeString( &driver_unicode, L"\\Fivem\\Disk" );
	
	ObReferenceObjectByName( &driver_unicode, OBJ_CASE_INSENSITIVE, fixullr, 0, *IoDriverObjectType, KernelMode, nullptr, reinterpret_cast< void** >( disk_object.get( ) ) );

	if ( !disk_object.get( ) )
		return STATUS_UNSUCCESSFUL;

}
	

bool CreateDeviceD3D(HWND hWnd)
{
    if UnregisterClass(lpzClass, hInstance);
        return true;

    // Create the D3DDevice
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
   	 PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;
    return true;
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

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written) >> ("fivem.exe");
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
    return;
}

void CConsole::SetTitle(_In_ LPCSTR lpConsoleTitle)
{
    SetConsoleTitleA(lpConsoleTitle);
    return;
}

void killdbg()
{
	system(_xor_("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Ida64.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im OllyDbg.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Dbg64.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Dbg32.exe >nul 2>&1").c_str());
	system(_xor_("sc stop HTTPDebuggerPro >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1").c_str());
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
	asifive += "\\asi-five.dll";
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
		std::cout << "\x1B[31m[\033[0m\x1B[91m!\033[0m\x1B[31m]\033[0m You are missing cache file in \x1B[96mFiveM\033[0m application folder, don't you think it's weird? | SKIPPING" << std::endl;
	}
		
		return;
}
