// Fill out your copyright notice in the Description page of Project Settings.



#include "MovingPlatform.h"
#include "Components/BoxComponent.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	//Super is the actor class (in this scenario) and we are telling to run some code for using :: to manage the scope
	Super::BeginPlay();
	Start = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(Movebool == true)
	{
		MovePlatform(DeltaTime);
	}	

	if(Rotatebool == true)
	{
		RotatePlatform(DeltaTime);
	}

}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotateVelocity * DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (BeginMoving == true)
	{

		FVector CurrentLocation = GetActorLocation();


		if(StopMove == false)
		{
			CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		}

		float DistanceMoved = FVector::Dist(Start,CurrentLocation);
	

	if (TurnBack())
	{
		if(Pause == true)
		{
			Delay(DeltaTime);
		}
		else
		{
			PlatformVelocity = -PlatformVelocity;
			Start = GetActorLocation();
		}
	}


	SetActorLocation(CurrentLocation);
	}
}

bool AMovingPlatform::TurnBack() const
{
	return GetDistanceMoved() > MoveDistance;
}

void AMovingPlatform::Delay(float DeltaTime)
{
	StopMove = true;
	DelayTime += DeltaTime;

	if(DelayTime >= 5.)
	{
		PlatformVelocity = -PlatformVelocity;
		Start = GetActorLocation();
		DelayTime = 0.;
		StopMove = false;
	}
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(Start,GetActorLocation());
}

