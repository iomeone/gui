////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "ViewModel.h"

#include <NsCore/ReflectionImplement.h>
#include <NsCore/Log.h>


using namespace NoesisApp;
using namespace HelloWorld;


////////////////////////////////////////////////////////////////////////////////////////////////////
ViewModel::ViewModel()
{
    _startCommand.SetExecuteFunc(MakeDelegate(this, &ViewModel::Start));
    _settingsCommand.SetExecuteFunc(MakeDelegate(this, &ViewModel::Settings));
    _exitCommand.SetExecuteFunc(MakeDelegate(this, &ViewModel::Exit));
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
void ViewModel::Start(BaseComponent*)
{
	::MessageBoxA(0, "hi", "caption", 0);
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

NS_IMPLEMENT_REFLECTION(ViewModel)
{
    NsProp("StartCommand", &ViewModel::GetStartCommand);
    NsProp("SettingsCommand", &ViewModel::GetSettingsCommand);
    NsProp("ExitCommand", &ViewModel::GetExitCommand);
}