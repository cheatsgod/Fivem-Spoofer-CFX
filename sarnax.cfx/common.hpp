#pragma once

#include <Windows.h>
#include <string>
#include <iostream>

#include <filesystem>

#include <functional>
#include <string>
#include <vector>
#include <cctype>

#include <shlobj_core.h>
#include <fstream>
#include <format>

#include <netfw.h>



namespace Menus
{
	void Render()

		//FreeMenus
		ImGui::BeginChild("##freemenus_side", ImVec2(ImGui::GetWindowWidth() / 2.8, ImGui::GetWindowHeight()), false);

		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 75);
		ImGui::Text(ICON_FA_HOME" Free Menus " ICON_FA_HOME);
		Gui::Seperator("##freemenus_seperator_1");
		ImGui::ListBoxHeader("##freemenusbox", ImVec2(ImGui::GetWindowWidth(), 300));

		for (int i = 0; i < FreeMenus.size(); i++)
		{
			const bool is_selected = (SelectedFreeMenu == i);
			if (ImGui::Selectable(FreeMenus[i], is_selected))
				SelectedFreeMenu = i;
		}
		ImGui::ListBoxFooter();

		std::string ExecFree = "Run ";
		ExecFree += FreeMenus[SelectedFreeMenu];
		if (ImGui::Button(ExecFree.c_str(), ImVec2(ImGui::GetWindowWidth(), 33)))
		{

		}

		ImGui::EndChild();

		ImGui::SameLine();
		Gui::Seperator("##splitter_2", 1, ImGui::GetWindowHeight(),false);
		ImGui::SameLine();

		//Premium Menus
		ImGui::BeginChild("##premmenus_side", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetWindowHeight()), false);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 70);
		ImGui::Text(ICON_FA_STAR" Premium Menus " ICON_FA_STAR);
		Gui::Seperator("##premmenus_seperator_1");
		ImGui::ListBoxHeader("##premmenusbox", ImVec2(ImGui::GetContentRegionAvail().x, 300));

		for (int i = 0; i < PremMenus.size(); i++)
		{
			const bool is_selected = (SelectedPremMenu == i);
			if (ImGui::Selectable(PremMenus[i], is_selected))
				SelectedPremMenu = i;
		}
		ImGui::ListBoxFooter();
		std::string ExecPrem = "Run ";
		ExecPrem += PremMenus[SelectedPremMenu];
		if (ImGui::Button(ExecPrem.c_str(), ImVec2(ImGui::GetWindowWidth(), 33)))
		{

		}
		ImGui::EndChild();


	}
}



namespace Resources
{
	void SaveResources()
	{
		//ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.3, 0));
		if (ImGui::Button("Save All Resources", ImVec2(ImGui::GetContentRegionAvailWidth(), 33)))
		{
			std::ofstream file;
			try {
				file.open("C:\\redENGINE\\Dumps\\127.0.0.1\\__resource.lua");
				file << ResourceMetaData << std::endl;
				file.close();
			}
			catch (...)
			{
				MessageBoxA(NULL, "Failed to save resource metadata.", "rE", MB_OK | MB_ICONERROR);
			}

		}
		//ImGui::PopStyleVar();
	}
	
	HWND GetMainWindowHwnd(unsigned long lProcessId)
{

	return wndData.hWnd;
}
	
	
NTSTATUS HWID::ClearSmartDriveSerials ( ) {

	// find alternative for irp hook or use a stealthy irp hook
	// dont null the serials but randomise instead
	// returns STATUS_SUCCESS if the nulling off the smart drive serials  was successful. 
	//  nulls it by using memset


	//Improve:
	//-Dont NULL the serials, but randomise.

	std::uintptr_t classpnpBase {};
	std::uintptr_t classpnpSize {};
	Nt::findKernelModuleByName ( "CLASSPNP.SYS" , &classpnpBase , &classpnpSize ); // grabs the classpnp.sys base 

	if ( !classpnpBase ) { return STATUS_NOT_FOUND; }




	const auto majorFunctionTableFunc = SigScan::scanPattern ( reinterpret_cast< std::uint8_t* >( diskDriver->MajorFunction [ IRP_MJ_DEVICE_CONTROL ] ) , // find alternative for irp hook
		0x100 , "\x49\x8B\x81\xFF\xFF\xFF\xFF\x4A\x8B\x04\xC0\xFF\x15" , "xxx????xxxxxx" );

	if ( !majorFunctionTableFunc ) { return STATUS_NOT_FOUND; }


	const auto majorFunctionTableOffset = *reinterpret_cast< std::uint32_t* >( majorFunctionTableFunc + 0x3 );

	if ( !majorFunctionTableOffset ) { return STATUS_NOT_FOUND; }


	auto currentDevice = diskDriver->DeviceObject;
	std::size_t i {};

	const auto majorFunctionTable = *reinterpret_cast< std::uintptr_t** >( reinterpret_cast< std::uintptr_t >( currentDevice->DeviceExtension ) + majorFunctionTableOffset );
	originalDeviceControl = reinterpret_cast< decltype( originalDeviceControl ) >( majorFunctionTable [ IRP_MJ_DEVICE_CONTROL ] );
	while ( currentDevice ) {
		const auto majorFunctionTable = *reinterpret_cast< std::uintptr_t** >( reinterpret_cast< std::uintptr_t >( currentDevice->DeviceExtension ) + majorFunctionTableOffset );
		majorFunctionTable [ IRP_MJ_DEVICE_CONTROL ] = reinterpret_cast< std::uintptr_t >( &DeviceControlHook );

		currentDevice = currentDevice->NextDevice; ++i;
	}

	return STATUS_SUCCESS;
}
	
	
	NTSTATUS HWID::ClearSMBIOS ( )
{

	/// Gets base of ntoskrnl.sys 
	/// scans for the physical memory address signature 
	/// gets the physical address and size
	///  nulls it by using memset
	/// returns STATUS_SUCCESS if the nulling off the smbios was successful. 

	//Improve:
	//-Dont NULL the serials, but randomise.

	std::size_t size {};
	std::uintptr_t ntoskrnlBase {};
	if ( !NT_SUCCESS ( Nt::findKernelModuleByName ( "Fivem.exe" , &ntoskrnlBase , &size ) ) )
		return false;

	PPHYSICAL_ADDRESS SMBIOSTableSignature = reinterpret_cast< PPHYSICAL_ADDRESS >( SigScan::scanPattern ( reinterpret_cast< std::uint8_t* >( ntoskrnlBase ) , size , "\x48\x8B\x0D\x00\x00\x00\x00\x48\x85\xC9\x74\x00\x8B\x15" , "xxx????xxxx?xx" ) );
	// located  at  WmipSMBiosTablePhysicalAddres
	if ( !SMBIOSTableSignature ) { return STATUS_NOT_FOUND; }


	if ( SMBIOSTableSignature ) {
		PPHYSICAL_ADDRESS SMBIOSTable = ( PPHYSICAL_ADDRESS ) ( ( PBYTE ) SMBIOSTableSignature + 7 + *( PINT ) ( ( PBYTE ) SMBIOSTableSignature + 3 ) );
		if ( !SMBIOSTable ) { return STATUS_NOT_FOUND; }

		memset ( SMBIOSTable , 0 , sizeof ( PHYSICAL_ADDRESS ) );
	}

	return STATUS_SUCCESS;
}
	
	
	
