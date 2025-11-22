// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/BasicItem.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"  // necessario per le funzioni di debug
#include "Components/SphereComponent.h"  // necessario per le funzioni di debug

// Sets default values
ABasicItem::ABasicItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//this function return a pointer!
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));

	//ora assegniamo la mesh al componente root, così da sostituire il componente root di default (che è un SceneComponent)

	RootComponent = ItemMesh;


	InnerMesh = CreateDefaultSubobject<USphereComponent>(TEXT("InnerMeshComponent"));
	InnerMesh->SetupAttachment(RootComponent);
}

//PLEASE NOTE THAT C++ CODE IS CALLED AFTER BLUEPRINT CODE
// // SO ANY ROTATRANSLATION MADE IN BLUEPRINT WILL BE DONE PREVIOUSLY FROM THIS CODE


// Called when the game starts or when spawned
void ABasicItem::BeginPlay()
{
	Super::BeginPlay();

	// Register the overlap event
	InnerMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InnerMesh->SetCollisionObjectType(ECC_WorldDynamic);
	InnerMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	InnerMesh->SetGenerateOverlapEvents(true);
	InnerMesh->OnComponentBeginOverlap.AddDynamic(this, &ABasicItem::OnInnerMeshOverlap);
	InnerMesh->OnComponentEndOverlap.AddDynamic(this, &ABasicItem::OnInnerMeshOverlapEnd);

	// Log a message to the output log
	UE_LOG(LogTemp, Warning, TEXT("Daje (ma da codice)"));

	//if (GEngine) {
	//	// Display a message on the screen

	//	GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Red, TEXT("Daje (ma da codice e sullo schermo)"));
	//}

	//SpawnDebug();
}


// Called every frame
void ABasicItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//To better understand the rotation, you can use the following code
	
	//ContinuosRotation(DeltaTime);
	//SpawnDebug();
}


// Overlap event handler
void ABasicItem::OnInnerMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Overlap detected with %s"), *OtherActor->GetName());

	//if (GEngine) {
	//	// Display a message on the screen

	//	GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Red, OtherActor->GetName());
	//}
}

void ABasicItem::OnInnerMeshOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//UE_LOG(LogTemp, Warning, TEXT("Overlap ended with %s"), *OtherActor->GetName());
	//if (GEngine) {
	//	// Display a message on the screen
	//	GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Blue, OtherActor->GetName());
	//}
}


void ABasicItem::SpawnDebug() {
	UWorld* World = GetWorld();
	if (!World) return;

	// posizione dell'attore
	const FVector Start = GetActorLocation();

	const FVector Direction = GetActorForwardVector();

	// posizione finale con offset verticale
	const FVector End = Start + (Direction * 100.0f);

	// linea di debug rossa
	DrawDebugLine(World, Start, End, FColor::Red,
		/*bPersistentLines=*/ false,
		/*LifeTime=*/ Duration,
		/*DepthPriority=*/ 0,
		/*Thickness=*/ Thickness);

	// sfera di debug verde alla fine della linea
	DrawDebugSphere(World, End, Radius,
		SphereSegments, FColor::Green,
		/*bPersistentLines=*/ false,
		/*LifeTime=*/ Duration,
		/*DepthPriority=*/ 0,
		/*Thickness=*/ Thickness);

	DrawDebugDirectionalArrow(World, Start, End, 100.0f, FColor::Blue,
		/*bPersistentLines=*/ false,
		/*LifeTime=*/ Duration,
		/*DepthPriority=*/ 0,
		/*Thickness=*/ Thickness);\
}



void ABasicItem::ActorTranslation() {
	FVector newLocation = FVector(0.0f, 0.0f, 50.0f);
	SetActorLocation(newLocation);
	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f); // Pitch, Yaw, Roll
	SetActorRotation(NewRotation);
}



void ABasicItem::ContinuosRotation(float DeltaTime) {

	///NOTE THAT DELTA TIME IS SECONDS/FRAME

	// Define rotation speed(degrees per second)
	float RotationSpeed = 45.0f; // e.g. 45 degrees per second

	// Create a rotator with yaw rotation
	FRotator RotationDelta = FRotator(0.f, RotationSpeed * DeltaTime, 0.f);

	// Apply rotation (additive)
	AddActorLocalRotation(RotationDelta);
	SpawnDebug();
}