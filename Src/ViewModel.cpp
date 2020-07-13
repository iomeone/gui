////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "ViewModel.h"

#include <NsCore/ReflectionImplement.h>
#include <NsCore/Log.h>
#include <NsGui/PasswordBox.h>
using namespace NoesisApp;
using namespace HelloWorld;
using namespace Noesis;

////////////////////////////////////////////////////////////////////////////////////////////////////
ViewModel::ViewModel()
{
    _startCommand.SetExecuteFunc(MakeDelegate(this, &ViewModel::Start));
    _settingsCommand.SetExecuteFunc(MakeDelegate(this, &ViewModel::Settings));
    _exitCommand.SetExecuteFunc(MakeDelegate(this, &ViewModel::Exit));
	//StrCopy(_input, 256, "haha");
}

void HelloWorld::ViewModel::SetInput(const char * value)
{
	if (!StrEquals(_input, value))
	{
		StrCopy(_input, sizeof(_input), value);
		OnPropertyChanged("UI_Input");
	}
}

const char * HelloWorld::ViewModel::GetInput() const
{
	return _input;
}

const char * HelloWorld::ViewModel::GetOutput() const
{
	return _output;
}

void HelloWorld::ViewModel::SetOutput(const char * value)
{
	if (!StrEquals(_output, value))
	{
		StrCopy(_output, sizeof(_output), value);
		OnPropertyChanged("UI_Output");
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const DelegateCommand* ViewModel::GetStartCommand() const
{
    return &_startCommand;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const DelegateCommand* ViewModel::GetSettingsCommand() const
{
    return &_settingsCommand;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const DelegateCommand* ViewModel::GetExitCommand() const
{
    return &_exitCommand;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
#include "windows.h"
void ViewModel::Start(BaseComponent*param_)
{
	auto t = param_->GetClassType();
	NS_UNUSED(t);


	PasswordBox *pb = static_cast<PasswordBox*>(param_);

	const char* password = pb->GetPassword();
	char text[512];
	snprintf(text, sizeof(text), "Hello, %s (%s)", _input, password);
	SetOutput(text);




	
	//char * p = Boxing::Unbox<char*>(param_);
	//NS_UNUSED(p);
	////Noesis::String* PasswordBox =(Noesis::String*) param_;
	////if (PasswordBox)
	////{
	////
	////	printf(PasswordBox->Begin());
	////}


	//if (Boxing::CanUnbox<Noesis::String>(param_))
	//{
	//	Noesis::String param = Boxing::Unbox<Noesis::String>(param_);

	//	/*const char * x = param->GetPassword();*/
	//	char text[512];
	//	snprintf(text, sizeof(text), "Hello, %s (%s)", _input, param.Begin());
	//	SetOutput(text);
	//}

	//::MessageBoxA(0, "hi", "caption", 0);
	//NS_LOG_INFO("Start Game");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ViewModel::Settings(BaseComponent*)
{
    NS_LOG_INFO("Change Settings");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ViewModel::Exit(BaseComponent*)
{
    NS_LOG_INFO("Exit Game");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

//NS_IMPLEMENT_REFLECTION(ViewModel)
//NS_IMPLEMENT_REFLECTION(ViewModel, NotifyPropertyChangedBase, "HelloWorld.ViewModel")
//{
//
//	NsProp("StartCommand", &ViewModel::GetStartCommand);
//	NsProp("SettingsCommand", &ViewModel::GetSettingsCommand);
//	NsProp("ExitCommand", &ViewModel::GetExitCommand);
//
//	NsProp("UI_Input", &ViewModel::GetInput, &ViewModel::SetInput);
//
//	NsProp("UI_Output", &ViewModel::GetOutput, &ViewModel::SetOutput);
//
//
//
//
//}