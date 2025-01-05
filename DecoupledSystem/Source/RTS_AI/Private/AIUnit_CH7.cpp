#include "AIUnit_CH7.h"

#include "RTS_AI/HealthComponent.h"

AAIUnit_CH7::AAIUnit_CH7()
{
	M_HealthComp = CreateDefaultSubobject<UHealthComponent>( TEXT( "Health" ) );
	M_PointValue = 10;
}

void AAIUnit_CH7::Init()
{
	M_HealthComp->onComponentDead.AddDynamic( this, &AAIUnit_CH7::Handle_HealthDeath );
}

void AAIUnit_CH7::Handle_HealthDeath( AController* causer )
{
	OnUnitDeath.Broadcast( causer, M_PointValue );
}