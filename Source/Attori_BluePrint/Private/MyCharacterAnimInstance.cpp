// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacterAnimInstance.h"
#include "MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


void UMyCharacterAnimInstance::NativeInitializeAnimation()
{
	// This function is called when the animation instance is initialized
	// You can set up initial values or references here
	Super::NativeInitializeAnimation();


	// Example: Initialize any variables or references needed for the animation
	// You can access the owning actor's properties or methods here
	OwningCharacter = Cast<AMyCharacter>(TryGetPawnOwner());

	if (OwningCharacter) {
		OwningCharacterMovement = OwningCharacter ? OwningCharacter->GetCharacterMovement() : nullptr;
	}
	else{
		UE_LOG(LogTemp, Warning, TEXT("OwningCharacter is null in UMyCharacterAnimInstance::NativeInitializeAnimation"));
	}
	
}


void UMyCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	// This function is called every frame to update the animation instance
	// You can update variables or perform calculations here based on the character's state
	// For example, you might want to update the speed or direction of the character

	if (!TryGetPawnOwner() || !OwningCharacter || !IsValid(OwningCharacter))
	{
		return;
	}

	GroundSpeed = UKismetMathLibrary::VSizeXY(OwningCharacterMovement->Velocity);

	//if is falling
	IsFalling = OwningCharacterMovement->IsFalling();

	CharacterState = OwningCharacter->GetCharacterState();

}


void UMyCharacterAnimInstance::AnimNotify_AttackEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp) {
		UMyCharacterAnimInstance* AnimInstance = Cast<UMyCharacterAnimInstance>(MeshComp->GetAnimInstance());
		if (AnimInstance && AnimInstance->OwningCharacter) {
			AnimInstance->OwningCharacter->SetAttackStateState(AttackState::ECS_Unoccupied);
		}
	}

	if (GEngine) {
		// Display a message on the screen
		GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Red, "Attack Ended");
	}
}