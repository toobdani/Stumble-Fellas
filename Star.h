// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Star.generated.h"

UCLASS()
class STUMBLE_FELLAS_API AStar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Star")
	UStaticMeshComponent* StarMesh;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Star")
	UMaterialInterface* DefaultMaterial;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Star")
	class UBoxComponent* BCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Star")
	bool Event;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Star")
	bool DoEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Star")
	FRotator RotateVelocity;


	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
