// Fill out your copyright notice in the Description page of Project Settings.


#include "RollingBalls.h"

// Sets default values
ARollingBalls::ARollingBalls()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARollingBalls::BeginPlay()
{
	Super::BeginPlay();

	StartPosition = GetActorLocation();
	
}

// Called every frame
void ARollingBalls::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

