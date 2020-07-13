#pragma once



#include <NsCore/Noesis.h>

#include <NsCore/ReflectionDeclare.h>
#include <NsCore/ReflectionImplement.h>

#include <NsCore/BaseComponent.h>
#include <NsApp/DelegateCommand.h>
#include <NsApp/NotifyPropertyChangedBase.h>

namespace HelloWorld
{

	////////////////////////////////////////////////////////////////////////////////////////////////////
	class ViewModel final : public NoesisApp::NotifyPropertyChangedBase
	{
	public:
		ViewModel();

	public:
		void SetInput(const char* value);
		const char* GetInput() const;

		const char* GetOutput() const;


		void SetOutput(const char* value);

	private:
		char _input[256] = "";
		char _output[256] = "";

	private:
		const NoesisApp::DelegateCommand* GetStartCommand() const;
		const NoesisApp::DelegateCommand* GetSettingsCommand() const;
		const NoesisApp::DelegateCommand* GetExitCommand() const;

		void Start(BaseComponent* param);
		void Settings(BaseComponent* param);
		void Exit(BaseComponent* param);

	private:
		NoesisApp::DelegateCommand _startCommand;
		NoesisApp::DelegateCommand _settingsCommand;
		NoesisApp::DelegateCommand _exitCommand;
		//NS_DECLARE_REFLECTION(ViewModel, NotifyPropertyChangedBase, "HelloWorld.ViewModel")
		//NS_DECLARE_REFLECTION(ViewModel, NotifyPropertyChangedBase)
		NS_IMPLEMENT_INLINE_REFLECTION(ViewModel, NotifyPropertyChangedBase, "HelloWorld.ViewModel")
		{

			NsProp("StartCommand", &ViewModel::GetStartCommand);
			NsProp("SettingsCommand", &ViewModel::GetSettingsCommand);
			NsProp("ExitCommand", &ViewModel::GetExitCommand);

			NsProp("UI_Input", &ViewModel::GetInput, &ViewModel::SetInput);

			NsProp("UI_Output", &ViewModel::GetOutput, &ViewModel::SetOutput);




		}
		
	};

}
