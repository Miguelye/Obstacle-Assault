// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay(); 

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move Platform Forwards
		//get current location
	FVector CurrentLocation = GetActorLocation();
		//Add vector to that location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		//set Location
	SetActorLocation(CurrentLocation);
	// send platform back when reached final location
		// check if reached final location
	DistancePlatform = FVector::Dist(StartLocation, CurrentLocation);
		// Reverse direction of platform when final location is reached

}

