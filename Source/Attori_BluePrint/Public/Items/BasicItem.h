// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicItem.generated.h"

UCLASS()
class ATTORI_BLUEPRINT_API ABasicItem : public AActor
{
	GENERATED_BODY()
	

	// Parametri configurabili dall'editor
	UPROPERTY(EditAnywhere, Category = "Debug")
	float OffsetZ = 200.f;

	UPROPERTY(EditAnywhere, Category = "Debug")
	float Duration = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Debug")
	float Thickness = 2.f;

	UPROPERTY(EditAnywhere, Category = "Debug")
	int32 SphereSegments = 12;

	UPROPERTY(EditAnywhere, Category = "Debug")
	int32 Radius = 5;

	UPROPERTY(EditAnywhere, Category = "Debug")
	int EulerActor = 1;


UFUNCTION(BlueprintCallable, Category = "Debug")
float GetThickness() {
	return Thickness;
};

public:	
	// Sets default values for this actor's properties
	ABasicItem();
	void SpawnDebug();
	void ActorTranslation();
	void ContinuosRotation(float DeltaTime);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnInnerMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
			const FHitResult& SweepResult);

	UFUNCTION()
	void OnInnerMeshOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//(FComponentEndOverlapSignature, UPrimitiveComponent, OnComponentEndOverlap, UPrimitiveComponent*, OverlappedComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, int32, OtherBodyIndex);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* InnerMesh;

};
