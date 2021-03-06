////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


namespace Noesis
{

////////////////////////////////////////////////////////////////////////////////////////////////////
inline DragCompletedEventArgs::DragCompletedEventArgs(BaseComponent* s, bool c, float h, float v):
    RoutedEventArgs(s, Thumb::DragCompletedEvent), canceled(c), horizontalChange(h),
    verticalChange(v) {}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline DragStartedEventArgs::DragStartedEventArgs(BaseComponent* s, float h, float v):
    RoutedEventArgs(s, Thumb::DragStartedEvent), horizontalOffset(h), verticalOffset(v) {}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline DragDeltaEventArgs::DragDeltaEventArgs(BaseComponent* s, float h, float v):
    RoutedEventArgs(s, Thumb::DragDeltaEvent), horizontalChange(h), verticalChange(v) {}

}
