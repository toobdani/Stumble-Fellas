// Fill out your copyright notice in the Description page of Project Settings.


#include "DissapearingPlatform.h"

// Sets default values
ADissapearingPlatform::ADissapearingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADissapearingPlatform::BeginPlay()
{
	Super::BeginPlay();
	Dissapear = DissapearSet;
	
}

// Called every frame
void ADissapearingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

