// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerTriggerCollision.generated.h"

UCLASS()
class STUMBLE_FELLAS_API APlayerTriggerCollision : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerTriggerCollision();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collider")
	class UBoxComponent* BCollision;
	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collider")
	FVector Checkpoint;

};

