#pragma once
#include <string>
namespace MT4Wrapper {

	template<class T>
	public ref class ManagedObject
	{
	protected:
		T* m_Instance;
	public:
		ManagedObject(T* instance)
			: m_Instance(instance)
		{
		}
		virtual ~ManagedObject()
		{
			if (m_Instance != nullptr)
			{
				delete m_Instance;
			}
		}
		!ManagedObject()
		{
			if (m_Instance != nullptr)
			{
				delete m_Instance;
			}
		}
		T* GetInstance()
		{
			return m_Instance;
		}
		const static char* stoca(System::String^ string) // String to char Array
		{
			const char* str = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(string)).ToPointer();
			return str;
		}

		static System::String^ catos(char* arr) // String to char Array
		{
			//const char* str = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(string)).ToPointer();
			System::String ^ clistr = gcnew System::String(arr);;
			return clistr;
		}
		const static char stringToSingleChar(System::String^ string) // String to char Array
		{
			const char str = (const char)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(string)).ToPointer();
			return str;
		}
		static System::String^ charToSingleString(char x) // 
		{
			//const char* str = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(string)).ToPointer();
			System::String^ clistr = gcnew System::String(1, x);
			//System::String^ string (1, x);
			return clistr;
		}
	};
	
}