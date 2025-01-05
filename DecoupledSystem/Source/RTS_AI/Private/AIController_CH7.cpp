#include "AIController_CH7.h"

#include "AIUnit_CH7.h"

void AAIController_CH7::Init()
{
	if( APawn* pawn = GetPawn() )
	{
		if( M_Unit = Cast<AAIUnit_CH7>( pawn ) )
		{
			M_Unit->Init();
			M_Unit->OnUnitDeath.AddDynamic( this, &AAIController_CH7::Handle_UnitDeath );
		}
	}
}

void AAIController_CH7::Handle_UnitDeath( AController* causer, int points )
{
	M_Unit->Destroy();
	OnControllerDeath.Broadcast( causer, points );
}