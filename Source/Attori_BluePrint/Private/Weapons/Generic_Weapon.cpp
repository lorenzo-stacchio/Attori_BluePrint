// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Generic_Weapon.h"
#include "MyCharacter.h"

AGeneric_Weapon::AGeneric_Weapon()
{
	// You can initialize weapon-specific properties here if needed
	WeaponBox = CreateDefaultSubobject<UBoxComponent>(TEXT("box component"));
	WeaponBox->SetupAttachment(GetRootComponent());
}


void AGeneric_Weapon::Equip(USceneComponent* InParent, FName InSocketName)
{

	AttachToComponent(InParent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, InSocketName);
	SetItemState(ItemState::EIS_Equipped);


}

void AGeneric_Weapon::Unequip()
{
	//DisplayDebug.Log("Weapon Unequipped");
	//GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Red, "Weapon Unequipped");
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	SetItemState(ItemState::EIS_floating);
	// Zero out rotation in world space
	SetActorRotation(FRotator::ZeroRotator);
}



void AGeneric_Weapon::OnInnerMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Overlap detected with %s"), *OtherActor->GetName());
	Super::OnInnerMeshOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	//if (GEngine) {
	//	// Display a message on the screen

	//	GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Red, OtherActor->GetName() + " but a weapon");
	//}

	/*AMyCharacter* actor = Cast<AMyCharacter>(OtherActor);
	
	if (actor) {
	
		FName weaponSocketName = TEXT("Weapon_Collect");
		AttachToComponent(actor->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, weaponSocketName);		

	}*/

}



void AGeneric_Weapon::OnInnerMeshOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnInnerMeshOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	//if (GEngine) {
	//	// Display a message on the screen

	//	GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Blue, OtherActor->GetName() + " but a weapon");
	//}
}


