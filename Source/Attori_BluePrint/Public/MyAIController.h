// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class ATTORI_BLUEPRINT_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    // Set the character to follow
    UFUNCTION(BlueprintCallable, Category = "AI")
    void FollowCharacter(ACharacter* TargetCharacter);

protected:
    virtual void OnPossess(APawn* InPawn) override;

private:
    UPROPERTY()
    ACharacter* FollowTarget;

    FTimerHandle FollowUpdateTimer;
    void UpdateFollow();
};
