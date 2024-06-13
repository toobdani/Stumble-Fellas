// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "MovingPlatform.generated.h"


//UCLASS sets Unreal up to create a new class within the engine
UCLASS()
class STUMBLE_FELLAS_API AMovingPlatform : public AActor
{
	//A Macro used by unreal to generate some initialisation code
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties

	//Constructs the script at the start of the project
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Platform")
	float IncreaseAmount = -1.;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Platform")
	bool MoveUp = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Platform")
	FVector PlatformVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Platform")
	FVector Start = FVector(0.,0.,0.);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Platform")
	float MoveDistance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Moving Platform")
	bool BeginMoving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Platform: Pause")
	float DelayTime = 0.;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Platform: Pause")
	bool DelayStart = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Platform: Pause")
	bool Pause; 

	bool StopMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotating Platform")
	FRotator RotateVelocity;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotating Platform")
	bool Rotatebool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Platform")
	bool Movebool;

private:

	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);

	bool TurnBack() const;

	void Delay(float DeltaTime);

	float GetDistanceMoved() const;
	

};

