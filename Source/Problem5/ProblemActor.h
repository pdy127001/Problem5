// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProblemActor.generated.h"

UCLASS()
class PROBLEM5_API AProblemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProblemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int X = 0;
	int Y = 0;
	int movecount = 1;//10번이동을 1번작동
	int evCnt = 0;
	float totDist = 0;
	FVector Start;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Move();
	int Step();
	float distance(FVector2D first, FVector2D second);

};
