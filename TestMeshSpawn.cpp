// Fill out your copyright notice in the Description page of Project Settings.


#include "TestMeshSpawn.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/Actor.h"

// Sets default values
ATestMeshSpawn::ATestMeshSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));

	DissapearMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Test Mesh"));

	DefaultMaterial = CreateDefaultSubobject<UMaterialInterface>(TEXT("Default"));

	WrongMaterial = CreateDefaultSubobject<UMaterialInterface>(TEXT("Wrong"));

	CorrectMaterial = CreateDefaultSubobject<UMaterialInterface>(TEXT("Correct"));

	
	BCollision->SetBoxExtent(FVector(100.f,100.f,100.f));

	BCollision->SetCollisionProfileName("OverlapAllDynamic");

	RootComponent = DissapearMesh;

	BCollision->OnComponentBeginOverlap.AddDynamic(this, &ATestMeshSpawn::OnOverlapBegin);
	BCollision->OnComponentEndOverlap.AddDynamic(this, &ATestMeshSpawn::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ATestMeshSpawn::BeginPlay()
{
	Super::BeginPlay();
	DissapearMesh->SetMaterial(0, DefaultMaterial);
	
	
}

// Called every frame
void ATestMeshSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(CollisionEvent == true)
	{
		if(Dissapear == true)
		{
			DissapearMesh->SetMaterial(0, WrongMaterial);
			Delay += DeltaTime;

			if(Delay >= Wait)
			{
				Destroy();
			}
		}
		else
		{
			DissapearMesh->SetMaterial(0, CorrectMaterial);
		}
	}

}

void ATestMeshSpawn::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "Overlapbegin");
	CollisionEvent = true;
	DissapearMesh->SetMaterial(0, WrongMaterial);
}

void ATestMeshSpawn::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

