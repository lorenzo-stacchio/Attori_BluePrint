// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterState.h"
#include "MyCharacterAnimInstance.generated.h"

class AMyCharacter;
class UCharacterMovementComponent;


UCLASS()
class ATTORI_BLUEPRINT_API UMyCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void AnimNotify_AttackEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation);

	UPROPERTY(BlueprintReadOnly)
	AMyCharacter* OwningCharacter;


	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	UCharacterMovementComponent* OwningCharacterMovement;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")	
	float GroundSpeed;


	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool IsFalling;

	UPROPERTY(BlueprintReadOnly, Category = "Movement | Character State")
	//CharacterState CharacterState;
	TEnumAsByte<CharacterState> CharacterState;

};
