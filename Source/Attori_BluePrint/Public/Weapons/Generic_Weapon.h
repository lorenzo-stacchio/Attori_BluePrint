// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Generic_Item.h"
#include "Generic_Weapon.generated.h"

/**
 * 
 */
UCLASS()
class ATTORI_BLUEPRINT_API AGeneric_Weapon : public AGeneric_Item
{
	GENERATED_BODY()
	


protected:

	void OnInnerMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	void OnInnerMeshOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex) override;


};
