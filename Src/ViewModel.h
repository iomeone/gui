#pragma once



#include <NsCore/Noesis.h>

#include <NsCore/ReflectionDeclare.h>
#include <NsCore/ReflectionImplement.h>

#include <NsCore/BaseComponent.h>
#include <NsApp/DelegateCommand.h>
#include <NsApp/NotifyPropertyChangedBase.h>

#include <NsGui/SolidColorBrush.h>
#include <NsDrawing/Color.h>

#include <NsGui/ObservableCollection.h>

using namespace Noesis;
namespace HelloWorld
{


	class Player : public BaseComponent
	{
	public:
		Player() {}
		Player(const char* name, Color color, float scale, const char* pos) : _name(name), _scale(scale),
			_pos(pos), _color(MakePtr<SolidColorBrush>(color)) {}

	private:
		String _name;
		float _scale;
		String _pos;
		Ptr<Brush> _color;

		NS_IMPLEMENT_INLINE_REFLECTION(Player, Noesis::BaseComponent)
		{
			NsProp("Name", &Player::_name);
			NsProp("Scale", &Player::_scale);
			NsProp("Pos", &Player::_pos);
			NsProp("Color", &Player::_color);
		}
	};


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

		ObservableCollection<Player>* GetPlayers() const { return _players; }

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

		Noesis::Ptr<Noesis::ObservableCollection<Player>> _players;

		NS_DECLARE_REFLECTION(ViewModel, NotifyPropertyChangedBase)


		//NS_IMPLEMENT_INLINE_REFLECTION(ViewModel, NotifyPropertyChangedBase, "HelloWorld.ViewModel")
		//{
		//	NsProp("StartCommand", &ViewModel::GetStartCommand);
		//	NsProp("SettingsCommand", &ViewModel::GetSettingsCommand);
		//	NsProp("ExitCommand", &ViewModel::GetExitCommand);
		//	NsProp("UI_Input", &ViewModel::GetInput, &ViewModel::SetInput);
		//	NsProp("UI_Output", &ViewModel::GetOutput, &ViewModel::SetOutput);
		//}
		
	};

}
