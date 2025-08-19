// Fill out your copyright notice in the Description page of Project Settings.

#include "Pawns/MyPawnExample.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


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
	
	//create spring arm
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	//attach the spring arm to the root component --> so it will follow the pawn's movement
	SpringArmComp->SetupAttachment(GetRootComponent());
	// Create and attach the camera component
	SpringArmComp->TargetArmLength = 150.f; // Set the length of the spring arm
	SpringArmComp->SetupAttachment(RootComponent);

	//set view camera attached to the spring arm
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArmComp);

	
	// Automatically possess this pawn by the first player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("PawnMovement"));
	FloatingMovement->UpdatedComponent = CapsuleComponent;
	
	// Enable the pawn to rotate with the controller
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;


}


// Called when the game starts or when spawned
void AMyPawnExample::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMyPawnExample::MoveForward(float offset)
{
	UE_LOG(LogTemp, Warning, TEXT("MoveForward called with offset: %f"), offset);
	// Check if the Controller is valid and if the offset is not zero
	if (Controller && (offset != 0.f)) {
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, offset);
	}

}


void AMyPawnExample::Turn(float offset)
{
	UE_LOG(LogTemp, Warning, TEXT("Turn called with offset: %f"), offset);
	// Check if the Controller is valid and if the offset is not zero
	if (Controller && (offset != 0.f)) {
		AddControllerYawInput(offset);
	}

}


void AMyPawnExample::LookUp(float offset)
{
	UE_LOG(LogTemp, Warning, TEXT("Looked up called with offset: %f"), offset);
	// Check if the Controller is valid and if the offset is not zero
	if (Controller && (offset != 0.f)) {
		AddControllerPitchInput(offset);
	}

}

// Called to bind functionality to input
void AMyPawnExample::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AMyPawnExample::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &AMyPawnExample::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AMyPawnExample::LookUp);

}



// Called every frame
void AMyPawnExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


