// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//enable the character to rotate with the controller
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	// Create and attach the spring arm component

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 150.f; // Set the length of the spring arm


	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArmComp);

	
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCharacter::MoveForward(float offset)
{
	// Move the character forward based on the input offset
	UE_LOG(LogTemp, Warning, TEXT("MoveForward called with offset: %f"), offset);
	// Check if the Controller is valid and if the offset is not zero
	if (Controller && (offset != 0.f)) {
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, offset);
	}
}

void AMyCharacter::MoveRight(float offset)
{
	// Move the character forward based on the input offset
	UE_LOG(LogTemp, Warning, TEXT("MoveForward called with offset: %f"), offset);
	// Check if the Controller is valid and if the offset is not zero
	if (Controller && (offset != 0.f)) {
		FVector Right = GetActorRightVector();
		AddMovementInput(Right, offset);
	}
}

void AMyCharacter::Turn(float offset)
{
	// Move the character forward based on the input offset
	UE_LOG(LogTemp, Warning, TEXT("Turn called with offset: %f"), offset);
	// Check if the Controller is valid and if the offset is not zero
	if (Controller && (offset != 0.f)) {
		AddControllerYawInput(offset);
	}
}

void AMyCharacter::LookUp(float offset)
{
	// Move the character forward based on the input offset
	UE_LOG(LogTemp, Warning, TEXT("LookUp called with offset: %f"), offset);
	// Check if the Controller is valid and if the offset is not zero
	if (Controller && (offset != 0.f)) {
		AddControllerPitchInput(offset);
	}
}


// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::Turn);
}



