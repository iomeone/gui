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
				Noesis::String rs;
				rs += "char  " + text + "[]= {";
				for (uint32_t i = 0; i < text.Size(); i++)
				{
					rs +=  "\'"  ;// +String(char(i)) + "\', ";
					rs += text[i];
					rs += "\'";
					if(i != text.Size()-1)
						rs += ", ";

				}
				rs += ", 0};";
				
				
				result = Boxing::Box<Noesis::String>(rs);
				return true;
			}

			return false;
		}

	private:
		NS_IMPLEMENT_INLINE_REFLECTION_(UppercaseConverter, BaseValueConverter, "HelloWorld.UppercaseConverter")
	};
}