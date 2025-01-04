// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Flammable.h"
#include "GameFramework/Actor.h"
#include "ATree.generated.h"

UCLASS()
class RTS_AI_API AATree : public AActor, public IFlammable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Ignite() override;
};
