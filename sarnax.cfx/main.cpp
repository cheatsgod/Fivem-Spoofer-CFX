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

		while (true)
		{
			g_trace->m_fivem_path = g_trace->set_folder("Select FiveM Folder which contains FiveM.exe");

			system("cls");

			if (!g_trace->m_fivem_path.empty())
			{
				std::cout << "  [Selected Folder]  " << g_trace->m_fivem_path << std::endl;
				std::cout << "  [Launch Build]  " << g_trace->get_launch_build() << "\n" << std::endl;
	
				std::cout << "  [1]  :  " << "clean traces" << std::endl;
				std::cout << "  [2]  :  " << "enable network bypass" << std::endl;
				std::cout << "  [3]  :  " << "disable network bypass" << std::endl;
				std::cout << "  [4]  :  " << "reset fivem path" << std::endl;
				std::cout << "  [5]  :  " << "edit launch options" << std::endl;
				std::cin >> choice;

				switch (choice)
				{
					case 1:
					{
						g_trace->setup();
					}
					break;
					case 2:
					{
						g_network->setup();
					}
					break;
					case 3:
					{
						g_network->destroy();
					}
					break;
					case 4:
					{
						g_trace->destroy();
					}
					break;
					case 5:
					{
						g_trace->set_launch_build();
					}
					break;
				}
			}
			else
			{
				std::cout << "  [Error]  :  " << "select valid folder for FiveM" << "\n" << std::endl;
			}

			system("Pause");
	}

}
	
auto c_mem::initialize(HWND wnd_handle) -> bool {
	DWORD process_id;
	if (wnd_handle) {
		GetWindowThreadProcessId(wnd_handle, &process_id);
		g::pid = process_id;
		return true;
	}
	return false;
}

	

NTSTATUS driver_start( )
{
	std::unique_ptr< DRIVER_OBJECT, decltype( &ObfDereferenceObject ) > disk_object( nullptr, &ObfDereferenceObject );
	
	UNICODE_STRING driver_unicode{};
	RtlInitUnicodeString( &driver_unicode, L"\\Driver\\Disk" );
	
	ObReferenceObjectByName( &driver_unicode, OBJ_CASE_INSENSITIVE, nullptr, 0, *IoDriverObjectType, KernelMode, nullptr, reinterpret_cast< void** >( disk_object.get( ) ) );

	if ( !disk_object.get( ) )
		return STATUS_UNSUCCESSFUL;

}
	
	void TextEditor::SetLanguageDefinition(const LanguageDefinition& aLanguageDef)
{
	mLanguageDefinition = aLanguageDef;
	mRegexList.clear();

	for (auto& r : mLanguageDefinition.mTokenRegexStrings)
		mRegexList.push_back(std::make_pair(std::regex(r.first, std::regex_constants::optimize), r.second));

	Colorize();
}
	
	
	static int UTF8CharLength(TextEditor::Char c)
{
	if ((c & 0xFE) == 0xFC)
		return 6;
	if ((c & 0xFC) == 0xF8)
		return 5;
	if ((c & 0xF8) == 0xF0)
		return 4;
	else if ((c & 0xF0) == 0xE0)
		return 3;
	else if ((c & 0xE0) == 0xC0)
		return 2;
	return 1;
}
	
	
	
DWORD ExPatternScanByStartAddress(HANDLE hprocess, DWORD start_address, DWORD section_size, vector<byte> pattern, string mask) {
	CONST DWORD buf_sz = 4096;
	DWORD old_protection;
	byte buffer[buf_sz];
	for (DWORD current_section = start_address; current_section < start_address + section_size; current_section += buf_sz) { // get a piece of memory and read

		if (!VirtualProtectEx(hprocess, (LPVOID)current_section, buf_sz, PAGE_EXECUTE_READWRITE, &old_protection)) { cout << "Error VirtualProtectEx memory section: " << hex << current_section << endl;  exit(1); };
		if (!ReadProcessMemory(hprocess, (LPVOID*)current_section, &buffer, buf_sz, 0)) { cout << "Error ReadProcessMemory" << endl;  exit(2); }
		if (!VirtualProtectEx(hprocess, (LPVOID)current_section, buf_sz, old_protection, &old_protection)) { cout << "Error VirtualProtectEx 2 " << endl;  exit(4); };

		for (DWORD current_address = 0; current_address < buf_sz; ++current_address) { // get this piece and scan for the pattern
			for (DWORD correct_count = 0; correct_count < pattern.size(); ++correct_count) {
				if (correct_count == pattern.size() - 1) {
					return current_section + current_address;
				}

				if (mask[correct_count] == '?') {
					continue;
				}
				else if (buffer[current_address + correct_count] == pattern[correct_count]) {
					continue;
				}
				else {
					correct_count = 0;
					break;
				}
			}
		}
	}


	return 0;
}
	
	LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
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
        if ((wParam & 0xfff0) == SC_KEYMENU)
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
	
	
