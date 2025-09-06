// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterState.h"
#include "MyCharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;
class AGeneric_Item;
class AGeneric_Weapon;



UCLASS()
class ATTORI_BLUEPRINT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float offset);
	void MoveRight(float offset);
	void Turn(float offset);
	void LookUp(float offset);
	void EKeyPressed();
	void QKeyPressed();
	void Attack();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void AttackEnd();


private:

	CharacterState CharState = CharacterState::ECS_Unequipped;

	AttackState AttState = AttackState::ECS_Unoccupied;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleInstanceOnly, Category = "Components")
	AGeneric_Item* OverlappingItem;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Weapons")
	AGeneric_Weapon* WeaponHeld;


public:
	FORCEINLINE AGeneric_Item* GetOverlappingItem() const { return OverlappingItem; }
	FORCEINLINE void SetOverlappingItem(AGeneric_Item* item) { OverlappingItem = item; }
	FORCEINLINE CharacterState GetCharacterState() const { return CharState; }
	
	FORCEINLINE void SetAttackStateState(AttackState state) { AttState = state; }

};
