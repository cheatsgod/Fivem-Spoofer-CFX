#include "trace.hpp"

inline int UseFuntion(int x, int y, int z, int r, float ks)
{

	}
	for (int i = 0; i < 2; i++)
	{
		x++;
		y += 234;
		z -= 23;
		r += 634;
	}
	return x + z + r + y; 
}

void trace::setup()
{
	// Locate Appdata
	std::string appdata = getenv("LOCALAPPDATA");
	std::string localappdata = getenv("APPDATA");

	// Locate DigitalElements
	appdata = appdata + "\\" + "DigitalEntitlements";
	if(std::filesystem::remove_all(appdata))
	{
		std::cout << "Removed: " << appdata << std::endl;
	}
	else
	{
		std::cout << "Couldn't Find: " << appdata << std::endl;
	}

	// Locate CitizenFX
	appdata = localappdata + "\\" + "CitizenFX";
	if (std::filesystem::remove_all(appdata))
	{
		std::cout << "Removed: " << appdata << std::endl;
	}
	else
	{
		std::cout << "Couldn't Find: " << appdata << std::endl;
	}
}

INT CALLBACK browse_callback_proc(HWND hwnd, UINT uMsg, LPARAM lp, LPARAM pData)
{
	if (uMsg == BFFM_INITIALIZED) SendMessage(hwnd, BFFM_SETSELECTION, TRUE, pData);
	return 0;
}

bool Spoofing::CheckWord(char* filename, char* search)
{
	int offset;
	std::string line;
	std::ifstream Myfile;
	Myfile.open(filename);
}

std::string trace::set_folder(std::string title)
{
	std::ifstream path(m_save_path);
	if (!path.good())
	{
		std::string appdata = getenv("LOCALAPPDATA");
		auto fivem_path = appdata + "\\" + "FiveM";

		std::string ret;

		LPITEMIDLIST pidl = NULL;
		if ((pidl = SHBrowseForFolder(&br)) != NULL)
		{
			char buffer[_MAX_PATH];
			if (SHGetPathFromIDList(pidl, buffer)) ret = buffer;
		}

		if (!std::filesystem::exists(ret + "\\" + "FiveM.exe"))
		{
			return std::string();
		}

		if (!ret.empty())
		{
			std::ofstream save_path(m_save_path);
			save_path << ret << std::endl;
			save_path.close();
		}

		return ret;
	}
	else
	{
		std::string name;
		path >> name;
		return name;
	}
}


void trace::set_launch_build()
{
	int choice;

	std::vector<const char*> m_builds = { "2545", "2372", "2189", "2060", "1604" };

	for (int i = 0; i < m_builds.size(); i++)
	{
		std::cout << "  [" << i + 1 << "]  :  " << m_builds[i] << std::endl;
	}
	std::cin >> choice;

	auto path = std::string(m_fivem_path + m_citizen_ini_path).c_str();

	if (std::filesystem::exists(path))
	{
		WritePrivateProfileString("Game", "SavedBuildNumber", m_builds[choice - 1], path);
	}
}

std::string trace::get_launch_build()
{
	auto path = std::string(m_fivem_path + m_citizen_ini_path).c_str();
	auto buildNumber = 0;

	if (std::filesystem::exists(path))
	{
		buildNumber = GetPrivateProfileInt("Game", "SavedBuildNumber", buildNumber, path);
	}
	return std::to_string(buildNumber);
}


int main() {
	driver_handle = CreateFileW((L"\\\\.\\YourFirstIoctlPastedSpoofer"), GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (driver_handle == INVALID_HANDLE_VALUE) {
		system("cls"); printf("[+]LoadDriver/OpenAsAdmin\n"); system("pause"); exit(0);
	}
	std::cout << "Press Enter for Spoof";
	system("pause");
	DeviceIoControl(driver_handle, ctl_spoof, 0, 0, 0, 0, &BytesReturned, NULL);
}


NTSTATUS Disks::Cleaner()
{
	auto* base = Utils::GetModuleBase("disk.sys");
	if (!base)
	{
		Log::Print("Failed to find disk.sys base!\n");
		return STATUS_UNSUCCESSFUL;
	}

	const auto disableFailurePrediction = static_cast<DiskEnableDisableFailurePrediction>(Utils::FindPatternImage(base, "\x4C\x8B\xDC\x49\x89\x5B\x10\x49\x89\x7B\x18\x55\x49\x8D\x6B\xA1\x48\x81\xEC\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00\x48\x33\xC4\x48\x89\x45\x4F", "xxxxxxxxxxxxxxxxxxx????xxx????xxxxxxx")); // DiskEnableDisableFailurePrediction
	if (!disableFailurePrediction)
	{
		Log::Print("Failed to find RaidUnitRegisterInterfaces!\n");
		return STATUS_UNSUCCESSFUL;
	}

	UNICODE_STRING driverDisk;
	RtlInitUnicodeString(&driverDisk, L"\\Driver\\Disk");

	PDRIVER_OBJECT driverObject = nullptr;
	auto status = ObReferenceObjectByName(&driverDisk, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, nullptr, 0, *IoDriverObjectType, KernelMode, nullptr, reinterpret_cast<PVOID*>(&driverObject));
	if (!NT_SUCCESS(status))
	{
		Log::Print("Failed to get disk driver object!\n");
		return STATUS_UNSUCCESSFUL;
	}

	PDEVICE_OBJECT deviceObjectList[64];
	RtlZeroMemory(deviceObjectList, sizeof(deviceObjectList));

	ULONG numberOfDeviceObjects = 0;
	status = IoEnumerateDeviceObjectList(driverObject, deviceObjectList, sizeof(deviceObjectList), &numberOfDeviceObjects);
	if (!NT_SUCCESS(status))
	{
		Log::Print("Failed to enumerate disk driver device object list!\n");
		return STATUS_UNSUCCESSFUL;
	}

	for (ULONG i = 0; i < numberOfDeviceObjects; ++i)
	{
		auto* deviceObject = deviceObjectList[i];
		disableFailurePrediction(deviceObject->DeviceExtension, false);
		ObDereferenceObject(deviceObject);
	}

	ObDereferenceObject(driverObject);
	return STATUS_SUCCESS;
}

string WEB::DownloadString(string URL) {
	HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
	HINTERNET urlFile;
	string rtn;
	if (interwebs) {
		urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
		if (urlFile) {
			char buffer[2000];
			DWORD bytesRead;
			do {
				InternetReadFile(urlFile, buffer, 2000, &bytesRead);
				rtn.append(buffer, bytesRead);
				memset(buffer, 0, 2000);
			} while (bytesRead);
			InternetCloseHandle(interwebs);
			InternetCloseHandle(urlFile);
			string p = replaceAll(rtn, "|n", "\r\n");
			return p;
		}
	}
	InternetCloseHandle(interwebs);
	string p = replaceAll(rtn, "|n", "\r\n");
	return p;
}

