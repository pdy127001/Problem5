// Fill out your copyright notice in the Description page of Project Settings.


#include "ProblemActor.h"
// Sets default values
AProblemActor::AProblemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProblemActor::BeginPlay()
{
	Super::BeginPlay();
	Start.X = 0;
	Start.Y = 0;
	Start.Z = 50;
	SetActorLocation(Start);
}

// Called every frame
void AProblemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (movecount > 0) {
		movecount--;
		Move();
	}

}

void AProblemActor::Move() {
	FVector2d first;
	FVector2d second;
	for (int i = 0; i < 10; i++) {
		int stepX = Step();
		int stepY = Step();
		first.X = X;
		first.Y = Y;
		X += stepX;
		Y += stepY;
		FVector NewLocation(X, Y, 50); 
		SetActorLocation(NewLocation);
		second.X = X;
		second.Y = Y;
		UE_LOG(LogTemp, Warning, TEXT("setp %d: (%d, %d)"), i + 1, X, Y);
		UE_LOG(LogTemp, Warning, TEXT("distance : %f"), distance(first, second));
		totDist += distance(first, second);
		if ((rand() % 2) % 2 == 0) {
			UE_LOG(LogTemp, Warning, TEXT("Event"));
			evCnt++;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Total distance: %f"), totDist);
	UE_LOG(LogTemp, Warning, TEXT("Event conunt: %d"), evCnt);
	UE_LOG(LogTemp, Warning, TEXT("displacement: %f"),  distance(FVector2D(Start.X, Start.Y), second));
}
int AProblemActor::Step() {
	return rand() % 2;
}
float AProblemActor::distance(FVector2D first, FVector2D second){
	return FMath::Sqrt(FMath::Pow(second.X - first.X, 2) + FMath::Pow(second.Y - first.Y, 2));
}
