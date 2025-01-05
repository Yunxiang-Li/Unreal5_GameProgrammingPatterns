#include "GameMode_CH7.h"

#include "AIController_CH7.h"
#include "PlayerController_CH7.h"
#include "Kismet/GameplayStatics.h"

void AGameMode_CH7::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if( APlayerController_CH7* castedPC = Cast<APlayerController_CH7>( NewPlayer ) )
	{
		M_PlayerController = castedPC;
		M_PlayerController->Init();
	}
}

void AGameMode_CH7::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	if( Exiting == M_PlayerController )
	{
		M_PlayerController = nullptr;
	}
}

void AGameMode_CH7::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> outActors;
	UGameplayStatics::GetAllActorsOfClass( GetWorld(), AAIController::StaticClass(), outActors );

	for( AActor* actor : outActors )
	{
		if (AAIController_CH7* aiController = Cast<AAIController_CH7>(actor))
		{
			M_AIControllers.Add(aiController);
		}
	}

	for( AAIController_CH7* aiController : M_AIControllers )
	{
		if( aiController )
		{
			aiController->Init();
			aiController->OnControllerDeath.AddDynamic( this, &AGameMode_CH7::Handle_ControllerDeath );
		}
	}
}

void AGameMode_CH7::Handle_ControllerDeath(AController* causer, int points)
{
	M_PlayerController->AddPoints( points );
}
