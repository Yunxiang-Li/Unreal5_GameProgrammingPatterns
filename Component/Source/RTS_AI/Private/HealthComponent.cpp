// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	M_MaxHealth = 100.f;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->OnTakeAnyDamage.AddDynamic( this, &UHealthComponent::DamageTaken );
	M_CurrentHealth = M_MaxHealth;
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* Causer)
{
	M_CurrentHealth = FMath::Max( M_CurrentHealth - Damage, 0.0f );

	OnComponentDamaged.Broadcast( Instigator, Damage, M_CurrentHealth );
	if( M_CurrentHealth <= 0.0f )
	{
		OnComponentDead.Broadcast( Instigator );
	}
}


