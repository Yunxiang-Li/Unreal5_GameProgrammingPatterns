#include "Command_UnitMove.h"
#include "ControllableUnit.h"

void UCommand_UnitMove::Init( AActor* Unit, const FVector& MoveLocation )
{
	M_Unit = Unit;
	M_MoveLocation = MoveLocation;
}

void UCommand_UnitMove::Execute( void )
{
	Super::Execute();
	IControllableUnit::Execute_SetMoveLocation( M_Unit, M_MoveLocation );
}
