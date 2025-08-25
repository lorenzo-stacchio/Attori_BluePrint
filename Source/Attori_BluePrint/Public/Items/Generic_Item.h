// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Generic_Item.generated.h"


enum ItemState:uint8 {
	EIS_Pickup,
	EIS_Equipped,
	EIS_floating,
};


UCLASS()
class ATTORI_BLUEPRINT_API AGeneric_Item : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeneric_Item();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void OnInnerMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
		const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	virtual void OnInnerMeshOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ItemMesh;

	void TransformSin(float DeltaTime);

	void SetItemState(ItemState state) { itemState = state; };

private:

	UPROPERTY(VisibleAnywhere)
	FString description;
	

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* InnerMesh;

	ItemState itemState = ItemState::EIS_floating;


};
