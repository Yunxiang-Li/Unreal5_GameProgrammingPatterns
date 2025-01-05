#include "PlayerController_CH7.h"

#include "AIController_CH7.h"
#include "Character_CH7.h"
#include "Widget_Score_CH7.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"

void APlayerController_CH7::Init()
{
	if( GetPawn() != nullptr )
	{
		GetPawn()->Destroy();
	}

	UWorld* const world = GetWorld();
	AActor* tempStart = UGameplayStatics::GetGameMode( world )->FindPlayerStart( this );
	FVector startLocation = tempStart != nullptr ? tempStart->GetActorLocation() : FVector::ZeroVector;

	FRotator spawnRotation = tempStart != nullptr ? tempStart->GetActorRotation() : FRotator::ZeroRotator;

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	APawn* tempPawn = world->SpawnActor<APawn>( M_PlayerPawn, SpawnLocation, spawnRotation, spawnParams );
	Possess( tempPawn );

	if(  ( M_Character = Cast<ACharacter_CH7>( tempPawn ) ) )
	{
		M_Character->Init();
	}
	
	M_ScoreWidget = CreateWidget<UWidget_Score_CH7, APlayerController_CH7*>( this, M_ScoreWidgetClass.Get() );
	if (!M_ScoreWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create the score widget!"));
		return;
	}
	M_ScoreWidget->AddToViewport();
}

void APlayerController_CH7::AddPoints( int points )
{
	M_Points += points;
	M_ScoreWidget->UpdatePoints( M_Points );
}