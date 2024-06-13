// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTriggerCollision.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

// Sets default values
APlayerTriggerCollision::APlayerTriggerCollision()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));

	BCollision->SetBoxExtent(FVector(100.f,100.f,100.f));

	BCollision->SetCollisionProfileName("Trigger");

	RootComponent = BCollision;

}

// Called when the game starts or when spawned
void APlayerTriggerCollision::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerTriggerCollision::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
