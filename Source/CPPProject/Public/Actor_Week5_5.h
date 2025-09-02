// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_Week5_5.generated.h"

UCLASS()
class CPPPROJECT_API AActor_Week5_5 : public AActor
{
	GENERATED_BODY()
private:
	float Treval;
	float Total;
	FVector Points;

public:	
	// Sets default values for this actor's properties
	AActor_Week5_5();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void move();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
