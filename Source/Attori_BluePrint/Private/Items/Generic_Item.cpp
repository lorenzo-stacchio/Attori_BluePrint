// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Generic_Item.h"
#include "Components/SphereComponent.h"  // necessario per le funzioni di debug
#include "MyCharacter.h"  // necessario per le funzioni di debug

// Sets default values
AGeneric_Item::AGeneric_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//this function return a pointer!
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	//ora assegniamo la mesh al componente root, così da sostituire il componente root di default (che è un SceneComponent)
	RootComponent = ItemMesh;
	InnerMesh = CreateDefaultSubobject<USphereComponent>(TEXT("InnerMeshComponent"));
	InnerMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGeneric_Item::BeginPlay()
{
	Super::BeginPlay();
	// Register the overlap event
	InnerMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InnerMesh->SetCollisionObjectType(ECC_WorldDynamic);
	InnerMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	InnerMesh->SetGenerateOverlapEvents(true);
	InnerMesh->OnComponentBeginOverlap.AddDynamic(this, &AGeneric_Item::OnInnerMeshOverlap);
	InnerMesh->OnComponentEndOverlap.AddDynamic(this, &AGeneric_Item::OnInnerMeshOverlapEnd);
}


void AGeneric_Item::OnInnerMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Overlap detected with %s"), *OtherActor->GetName());

	if (GEngine) {
		// Display a message on the screen

		GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Red, OtherActor->GetName());
	}

	// Cast the OtherActor to your character class
	AMyCharacter* actor = Cast<AMyCharacter>(OtherActor);
	if (actor) {
		actor->SetOverlappingItem(this);
	}

}

void AGeneric_Item::OnInnerMeshOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//UE_LOG(LogTemp, Warning, TEXT("Overlap ended with %s"), *OtherActor->GetName());
	if (GEngine) {
		// Display a message on the screen
		GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Blue, OtherActor->GetName());
	}

	AMyCharacter* actor = Cast<AMyCharacter>(OtherActor);
	if (actor) {
		actor->SetOverlappingItem(nullptr);
	}

}

void AGeneric_Item::TransformSin(float DeltaTime)
{
	FVector NewLocation = GetActorLocation();
	float RunningTime = GetWorld()->GetTimeSeconds();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	SetActorLocation(NewLocation);
}


// Called every frame
void AGeneric_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (itemState == ItemState::EIS_floating) {
		TransformSin(DeltaTime);
	}

}