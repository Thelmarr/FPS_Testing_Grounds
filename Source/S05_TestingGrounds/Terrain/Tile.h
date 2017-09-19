// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

USTRUCT()
struct FSpawnPosition
{
	GENERATED_USTRUCT_BODY()

	FVector Location;
	float YawRotation;
	float Scale;

};

class UActorPool;

UCLASS()
class S05_TESTINGGROUNDS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MinExtent;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MaxExtent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn, float Radius = 500.f, float MinScale = 1.f, float MaxScale = 1.f);

	TArray<FSpawnPosition> RandomSpawnPosition(int MinSpawn, int MaxSpawn, float MinScale, float MaxScale, float Radius);

	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(UActorPool* InPool);

private:
	void PositionNavMeshBoundsVolume();

	bool CanSpawnAtLocation(FVector Location, float Radius);

	void PlaceObject(TSubclassOf<AActor> ToSpawn, FSpawnPosition &SpawnPosition);

	bool FindEmptyLocation(FVector &OutLocation, float Radius);

	UActorPool *Pool;

	AActor* NavMeshBoundsVolume;

};
