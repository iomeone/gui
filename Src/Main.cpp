////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include <NsCore/Noesis.h>
#include <NsCore/ReflectionImplementEmpty.h>
#include <NsCore/RegisterComponent.h>
#include <NsApp/EmbeddedXamlProvider.h>
#include <NsApp/EmbeddedFontProvider.h>
#include <NsApp/ApplicationLauncher.h>
#include <NsApp/EntryPoint.h>
#include <NsApp/Application.h>
#include <NsApp/Window.h>

#include <NsGui/IntegrationAPI.h>
#include <NsGui/TextBox.h>

#include <NsCore/ReflectionImplementEmpty.h>

#include "ViewModel.h"
#include "ConverterComponent.h"

#include "App.xaml.bin.h"
#include "MainWindow.xaml.bin.h"
#include "Fonts.xaml.bin.h"
#include "Aero Matics Regular.ttf.bin.h"

#include "fontawesome-webfont.ttf.bin.h"
using namespace Noesis;
using namespace NoesisApp;


namespace HelloWorld
{
////////////////////////////////////////////////////////////////////////////////////////////////////
class App final: public Application
{
    NS_IMPLEMENT_INLINE_REFLECTION_(App, Application, "HelloWorld.App")
};

////////////////////////////////////////////////////////////////////////////////////////////////////
class MainWindow final: public Window
{
public:
	MainWindow();
	void InitializeComponent();

	void OnInitialized(BaseComponent*, const Noesis::EventArgs&);
    NS_IMPLEMENT_INLINE_REFLECTION_(MainWindow, Window, "HelloWorld.MainWindow")
};

MainWindow::MainWindow()
{
	Initialized() += MakeDelegate(this, &MainWindow::OnInitialized);
	InitializeComponent();
}

void MainWindow::InitializeComponent()
{
	GUI::LoadComponent(this, "MainWindow.xaml");

	Noesis::TextBox* e = FindName<TextBox>("Input");
	if (e)
	{
		//e->SelectAll();
	}
	//mSelectorExpanderButton = FindName<ToggleButton>("SelectorExpanderButton");
}

void MainWindow::OnInitialized(BaseComponent *, const Noesis::EventArgs &)
{
	SetDataContext(MakePtr<ViewModel>());
}

}

////////////////////////////////////////////////////////////////////////////////////////////////////
class AppLauncher final: public ApplicationLauncher
{
private:
    void RegisterComponents() const override
    {
        RegisterComponent<HelloWorld::App>();
        RegisterComponent<HelloWorld::MainWindow>();
		RegisterComponent<HelloWorld::UppercaseConverter>();
    }

    Noesis::Ptr<XamlProvider> GetXamlProvider() const override
    {
        EmbeddedXaml xamls[] = 
        {
			{"Fonts_xaml", Fonts_xaml },
            { "App.xaml", App_xaml },
            { "MainWindow.xaml", MainWindow_xaml }
			
        };

        return *new EmbeddedXamlProvider(xamls);
    }

    Noesis::Ptr<FontProvider> GetFontProvider() const override
    {
        EmbeddedFont fonts[] =
        {
            { "", Aero_Matics_Regular_ttf },
			{"",fontawesome_webfont_ttf }
        };

        return *new EmbeddedFontProvider(fonts);
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
int NsMain(int argc, char **argv)
{
    AppLauncher launcher;
    launcher.SetArguments(argc, argv);
    launcher.SetApplicationFile("App.xaml");

	
    return launcher.Run();
}
