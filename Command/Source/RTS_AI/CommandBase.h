#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CommandBase.generated.h"

UCLASS(Abstract)
class RTS_AI_API UCommandBase : public UObject
{
	GENERATED_BODY()
public:
	virtual void Execute();
};
