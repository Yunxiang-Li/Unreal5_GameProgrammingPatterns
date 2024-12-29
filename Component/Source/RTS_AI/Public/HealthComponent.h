// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FComponentDeadSignature, AController*, causer );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams( FComponentDamagedSignature, AController*, causer, float, damage, float, newHealth );

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RTS_AI_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UPROPERTY(BlueprintAssignable)
	FComponentDeadSignature OnComponentDead;
	UPROPERTY(BlueprintAssignable)
	FComponentDamagedSignature OnComponentDamaged;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void DamageTaken( AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* Causer );

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float M_CurrentHealth;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float M_MaxHealth;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
