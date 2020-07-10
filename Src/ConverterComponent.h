#pragma once


#include <NsCore/Noesis.h>
#include <NsCore/TypeOf.h>

#include <NsCore/String.h>
#include <NsCore/Ptr.h>
#include <NsCore/RegisterComponent.h>
#include <NsCore/ReflectionImplement.h>
#include <NsGui/BaseValueConverter.h>

using namespace Noesis;

namespace HelloWorld
{
	class UppercaseConverter final : public BaseValueConverter
	{
	public:
		bool TryConvert(BaseComponent* value, const Type* targetType, BaseComponent* /*parameter*/,
			Ptr<BaseComponent>& result) override
		{
			if (targetType == TypeOf<Noesis::String>() && Boxing::CanUnbox<Noesis::String>(value))
			{
				Noesis::String text = Boxing::Unbox<Noesis::String>(value);
				text.Insert(0, "1111");
				result = Boxing::Box<Noesis::String>(text);
				return true;
			}

			return false;
		}

	private:
		NS_IMPLEMENT_INLINE_REFLECTION_(UppercaseConverter, BaseValueConverter, "HelloWorld.UppercaseConverter")
	};
}