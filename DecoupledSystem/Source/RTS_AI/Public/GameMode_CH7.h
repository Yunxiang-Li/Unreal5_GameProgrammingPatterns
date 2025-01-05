#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameMode_CH7.generated.h"

class AAIController_CH7;
class APlayerController_CH7;
UCLASS(Abstract)
class RTS_AI_API AGameMode_CH7 : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void Logout(AController* Exiting) override;

	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	void Handle_ControllerDeath(AController* causer, int points);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<APlayerController_CH7> M_PlayerController;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<AAIController_CH7>> M_AIControllers;
};
