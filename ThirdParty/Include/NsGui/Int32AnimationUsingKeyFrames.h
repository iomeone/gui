////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef __GUI_INT32ANIMATIONUSINGKEYFRAMES_H__
#define __GUI_INT32ANIMATIONUSINGKEYFRAMES_H__


#include <NsCore/Noesis.h>
#include <NsCore/ReflectionDeclare.h>
#include <NsGui/AnimationTimeline.h>


namespace Noesis
{

class Int32KeyFrame;
template<class T> class FreezableCollection;
typedef FreezableCollection<Int32KeyFrame> Int32KeyFrameCollection;

NS_WARNING_PUSH
NS_MSVC_WARNING_DISABLE(4251 4275)

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Animates the value of a *Int32* property along a set of *KeyFrames*.
///
/// http://msdn.microsoft.com/en-us/library/system.windows.media.animation.int32animationusingkeyframes.aspx
////////////////////////////////////////////////////////////////////////////////////////////////////
class NS_GUI_ANIMATION_API Int32AnimationUsingKeyFrames final: public AnimationTimeline
{
public:
    Int32AnimationUsingKeyFrames();
    ~Int32AnimationUsingKeyFrames();

    /// Gets the type of value this animation generates
    const Type* GetTargetPropertyType() const override;

    /// Gets the collection of KeyFrame objects that define the animation
    Int32KeyFrameCollection* GetKeyFrames() const;

    // Hides Freezable methods for convenience
    //@{
    Ptr<Int32AnimationUsingKeyFrames> Clone() const;
    Ptr<Int32AnimationUsingKeyFrames> CloneCurrentValue() const;
    //@}

    /// From AnimationTimeline
    //@{
    Ptr<BaseComponent> GetAnimatedValue(BaseComponent* defaultOrigin,
        BaseComponent* defaultDestination, AnimationClock* clock) override;
    //@}

private:
    /// From DependencyObject
    //@{
    void OnInit() override;
    //@}

    /// From Freezable
    //@{
    void CloneCommonCore(const Freezable* source) override;
    Ptr<Freezable> CreateInstanceCore() const override;
    //@}

    /// From Timeline
    //@{
    Duration GetNaturalDuration(Clock* clock) const override;
    Duration GetEffectiveDuration() const override;
    //@}

    /// From AnimationTimeline
    //@{
    Ptr<AnimationTimeline> CreateTransitionFrom() const override;
    Ptr<AnimationTimeline> CreateTransitionTo() const override;
    //@}

private:
    mutable Ptr<Int32KeyFrameCollection> mKeyFrames;
    Vector<Pair<Ptr<Int32KeyFrame>, double>> mOrderedFrames;
    mutable Duration mNaturalDuration;

    NS_DECLARE_REFLECTION(Int32AnimationUsingKeyFrames, AnimationTimeline)
};

NS_WARNING_POP

}


#endif
