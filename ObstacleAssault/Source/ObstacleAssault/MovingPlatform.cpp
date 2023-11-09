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

	//get the initial location of the actor
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move Platform Forwards
	//get current location
	FVector CurrentLocation = GetActorLocation();

	//Apply Velocity
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);

	//set new Location
	SetActorLocation(CurrentLocation);

	// send platform back when reached final location
	// check if reached final location

	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	// Reverse direction of platform when final location is reached
	if (DistanceMoved > MoveDistance)
	{
		float OverShoot = DistanceMoved - MoveDistance;
		FString Name = GetName();
		UE_LOG(LogTemp, Display, TEXT("Name: %s, OverShoot Distance: %f"), *Name, OverShoot);

		FVector MoveDirection = PlatformVelocity.GetSafeNormal(); //GetSafeNormal return the direction with a value of 1
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	

}

