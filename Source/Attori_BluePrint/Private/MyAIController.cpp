// MyAIController.cpp
#include "MyAIController.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"

void AMyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    // Additional initialization if needed
}

void AMyAIController::FollowCharacter(ACharacter* TargetCharacter)
{
    FollowTarget = TargetCharacter;
    if (FollowTarget)
    {
        // Update movement every 0.2 seconds to follow dynamically
        GetWorld()->GetTimerManager().SetTimer(FollowUpdateTimer, this, &AMyAIController::UpdateFollow, 0.2f, true);
        UpdateFollow(); // Move immediately
    }
    else
    {
        GetWorld()->GetTimerManager().ClearTimer(FollowUpdateTimer);
    }
}

void AMyAIController::UpdateFollow()
{
    if (FollowTarget && GetPawn())
    {
        MoveToActor(FollowTarget, 100.0f); // Acceptance radius 100 units
    }
    else
    {
        GetWorld()->GetTimerManager().ClearTimer(FollowUpdateTimer);
    }
}