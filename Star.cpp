// Fill out your copyright notice in the Description page of Project Settings.


#include "Star.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/Actor.h"

// Sets default values
AStar::AStar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));

	StarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));

	DefaultMaterial = CreateDefaultSubobject<UMaterialInterface>(TEXT("Default"));

	BCollision->SetBoxExtent(FVector(100.f,100.f,100.f));

	BCollision->SetCollisionProfileName("OverlapAllDynamic");

	RootComponent = StarMesh;

	BCollision->OnComponentBeginOverlap.AddDynamic(this, &AStar::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AStar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotateVelocity * DeltaTime);

}

void AStar::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "Overlapbegin");
	if(DoEvent == true)
	{
		Event = true;
		StarMesh->SetVisibility(false);
	BCollision->SetCollisionProfileName("NoCollision");
		DoEvent = false;
	}
}

