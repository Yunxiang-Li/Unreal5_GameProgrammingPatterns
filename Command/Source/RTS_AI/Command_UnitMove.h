#pragma once

#include "CoreMinimal.h"
#include "CommandBase.h"
#include "Command_UnitMove.generated.h"

UCLASS()
class RTS_AI_API UCommand_UnitMove : public UCommandBase
{
	GENERATED_BODY()
	
public:
	void Init( AActor* Unit, const FVector& MoveLocation );
	virtual void Execute() override;
	
private:
	TObjectPtr<AActor> M_Unit;
	FVector M_MoveLocation;
	
};
