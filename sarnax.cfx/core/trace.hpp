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

