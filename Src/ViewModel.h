#pragma once



#include <NsCore/Noesis.h>
#include <NsCore/ReflectionDeclare.h>
#include <NsCore/BaseComponent.h>
#include <NsApp/DelegateCommand.h>


namespace HelloWorld
{

	////////////////////////////////////////////////////////////////////////////////////////////////////
	class ViewModel final : public Noesis::BaseComponent
	{
	public:
		ViewModel();

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

		NS_DECLARE_REFLECTION(ViewModel, BaseComponent)
	};

}
