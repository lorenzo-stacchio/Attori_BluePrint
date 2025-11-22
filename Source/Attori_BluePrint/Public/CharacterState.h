#pragma once
#include "CoreMinimal.h"

UENUM(BlueprintType)
enum CharacterState : uint8 {
	ECS_Unequipped UMETA(DisplayName = "Unequipped"),
	ECS_EquippedOneHandedWeapon UMETA(DisplayName = "Equipped One-Handed Weapon"),
	ECS_EquippedTwoHandedWeapon UMETA(DisplayName = "Equipped Two-Handed Weapon"),
};



UENUM(BlueprintType)
enum AttackState : uint8 {
	ECS_Unoccupied UMETA(DisplayName = "Unattacking"),
	ECS_Attacking UMETA(DisplayName = "Attacking"),
};
