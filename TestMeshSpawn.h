// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "TestMeshSpawn.generated.h"

UCLASS()
class STUMBLE_FELLAS_API ATestMeshSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestMeshSpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dissapearing Platform")
	UStaticMeshComponent* DissapearMesh;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dissapearing Platform")
	UMaterialInterface* DefaultMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dissapearing Platform")
	UMaterialInterface* WrongMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dissapearing Platform")
	UMaterialInterface* CorrectMaterial;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dissapearing Platform")
	class UBoxComponent* BCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dissapearing Platform")
	bool Dissapear;

	bool CollisionEvent = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dissapearing Platform")
	float Delay = 0.;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dissapearing Platform")
	FVector PlatformLocation;

	UPROPERTY(EditAnywhere, Category = "Dissapearing Platform")
	float Wait;

};
