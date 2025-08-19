// Fill out your copyright notice in the Description page of Project Settings.

#include "Pawns/MyPawnExample.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AMyPawnExample::AMyPawnExample()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	SetRootComponent(CapsuleComponent);
	//set the capsule size
	CapsuleComponent->SetCapsuleSize(42.f, 96.0f);

	// Create and attach the skeleton mesh component
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	// Imposta come root o come child del componente root esistente
	SkeletalMeshComponent->SetupAttachment(GetRootComponent());
	// Automatically possess this pawn by the first player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMyPawnExample::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMyPawnExample::MoveForward(float offset)
{
	UE_LOG(LogTemp, Warning, TEXT("MoveForward called with offset: %f"), offset);
}

// Called to bind functionality to input
void AMyPawnExample::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AMyPawnExample::MoveForward);
}



// Called every frame
void AMyPawnExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


