////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include <NsApp/SetFocusAction.h>
#include <NsCore/ReflectionImplementEmpty.h>


using namespace NoesisApp;


////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::Ptr<Noesis::Freezable> SetFocusAction::CreateInstanceCore() const
{
    return *new SetFocusAction();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void SetFocusAction::Invoke(Noesis::BaseComponent*)
{
    Noesis::UIElement* element = GetTarget();
    if (element != 0)
    {
        element->Focus();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION_(SetFocusAction, "NoesisGUIExtensions.SetFocusAction")
