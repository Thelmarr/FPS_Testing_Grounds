// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "DrawDebughelpers.h"
#include "EngineUtils.h"
#include "ActorPool.h"
#include "Tile.h"


// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MinExtent = FVector(0, -1900, -100);
	MaxExtent = FVector(3900, 1900, -100);
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
}

void ATile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Pool->Return(NavMeshBoundsVolume);
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATile::PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn, float Radius, float MinScale, float MaxScale)
{
	int NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);
	
	for (size_t i = 0; i < NumberToSpawn; i++)
	{
		FVector SpawnPoint;
		float RandScale = FMath::RandRange(MinScale, MaxScale);
		bool Found = FindEmptyLocation(SpawnPoint, Radius * RandScale);
		if (Found)
		{
			float Rotation = FMath::RandRange(-180.f, 180.f);
			PlaceObject(ToSpawn, SpawnPoint, Rotation, RandScale);
		}
	}
}

bool ATile::FindEmptyLocation(FVector &OutLocation, float Radius)
{
	FVector BoxMin = MinExtent;
	FVector BoxMax = MaxExtent;

	FBox Bounds(BoxMin, BoxMax);
	const int Max_Attempts = 100;
	for (size_t i = 0; i < Max_Attempts; i++)
	{
		FVector CandidatePoint = FMath::RandPointInBox(Bounds);
		if (CanSpawnAtLocation(CandidatePoint, Radius))
		{
			OutLocation = CandidatePoint;
			return true;
		}
	}
	return false;
}

void ATile::PlaceObject(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint, float YawRotation, float Scale)
{
	AActor *Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
	Spawned->SetActorRelativeLocation(SpawnPoint);
	Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	Spawned->SetActorRotation(FRotator(0, YawRotation, 0));
	Spawned->SetActorScale3D(FVector(Scale));
}

bool ATile::CanSpawnAtLocation(FVector Location, float Radius)
{
	FHitResult HitResult;
	FVector GlobalLocation = ActorToWorld().TransformPosition(Location);
	bool HasHit = GetWorld()->SweepSingleByChannel
	(
		HitResult,
		GlobalLocation,
		GlobalLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,		
		FCollisionShape::MakeSphere(Radius)
	);
	return !HasHit;
}

void ATile::SetPool(UActorPool *InPool)
{
	Pool = InPool;

	PositionNavMeshBoundsVolume();
}

void ATile::PositionNavMeshBoundsVolume()
{
	NavMeshBoundsVolume = Pool->Checkout();
	if (NavMeshBoundsVolume == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s]: Not enough actors in pool!"), *GetName());
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s]: Checked out! [%s]"), *GetName(), *NavMeshBoundsVolume->GetName());
	NavMeshBoundsVolume->SetActorLocation(GetActorLocation());
}

