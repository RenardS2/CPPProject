// Fill out your copyright notice in the Description page of Project Settings.

#include "Actor_Week5_5.h"

// Sets default values
AActor_Week5_5::AActor_Week5_5()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Points = FVector(0.0f, 0.0f, 0.0f);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if(MeshAsset.Succeeded()) 
	{
		UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
		RootComponent = Mesh;
		Mesh->SetStaticMesh(MeshAsset.Object);
		Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		UE_LOG(LogTemp, Error, TEXT("Succeded to load mesh asset."));
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load mesh asset."));
	}
}

void AActor_Week5_5::move() {
	Points = GetActorLocation();

	float randX = FMath::FRandRange(0.0f, 1.5f);
	float randY = FMath::FRandRange(0.0f, 1.5f);

	if (FMath::RandRange(0, 100) <= 50) 
	{
		UE_LOG(LogTemp, Display, TEXT("Event Triggered!"))
	}

	float x1 = this->Points.X;
	float x2 = this->Points.X + randX;

	float y1 = this->Points.Y;
	float y2 = this->Points.Y + randY;

	this->Treval = FMath::Sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	this->Total += this->Treval;

	this->SetActorRelativeLocation(FVector(Points.X + randX, Points.Y + randY, Points.Z));
}

// Called when the game starts or when spawned
void AActor_Week5_5::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < 10; i++) {
		this->move();
		UE_LOG(LogTemp, Display, TEXT("Point %d: %s"), i, *Points.ToString());
		UE_LOG(LogTemp, Display, TEXT("Treval Distance : %f"), this->Treval);
	}

	UE_LOG(LogTemp, Display, TEXT("Total Distance : %f"), this->Total);
}

// Called every frame
void AActor_Week5_5::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

