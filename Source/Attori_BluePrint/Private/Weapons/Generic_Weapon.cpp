// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Generic_Weapon.h"

//AGeneric_Weapon::AGeneric_Weapon()
//{
//	// You can initialize weapon-specific properties here if needed
//}


void AGeneric_Weapon::OnInnerMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Overlap detected with %s"), *OtherActor->GetName());
	//Super::OnInnerMeshOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (GEngine) {
		// Display a message on the screen

		GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Red, OtherActor->GetName() + " but a weapon");
	}


}

void AGeneric_Weapon::OnInnerMeshOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//Super::OnInnerMeshOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	if (GEngine) {
		// Display a message on the screen

		GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Blue, OtherActor->GetName() + " but a weapon");
	}
}


