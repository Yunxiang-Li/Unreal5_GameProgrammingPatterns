#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Flammable.generated.h"

UINTERFACE(MinimalAPI)
class UFlammable : public UInterface
{
	GENERATED_BODY()
};

class RTS_AI_API IFlammable
{
	GENERATED_BODY()
public:
	virtual void Ignite() = 0; 
};
