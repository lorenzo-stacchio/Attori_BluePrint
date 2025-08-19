// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"

#include "MyPawnExample.generated.h"

class UCapsuleComponent;
class USkeletonMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ATTORI_BLUEPRINT_API AMyPawnExample : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawnExample();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float offset);
	void Turn(float offset);
	void LookUp(float offset);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UFloatingPawnMovement* FloatingMovement;

private:
	UPROPERTY(VisibleAnywhere,Category = "Components")
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* ViewCamera;
};
