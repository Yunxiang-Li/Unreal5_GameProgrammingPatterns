#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerController_CH7.generated.h"

class UWidget_Score_CH7;
class ACharacter_CH7;
UCLASS(Abstract)
class RTS_AI_API APlayerController_CH7 : public APlayerController
{
	GENERATED_BODY()

public:
	void Init();
	void AddPoints( int points );
protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<APawn> M_PlayerPawn;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<ACharacter_CH7> M_Character;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UWidget_Score_CH7> M_ScoreWidgetClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidget_Score_CH7> M_ScoreWidget;

	int M_Points;
};
