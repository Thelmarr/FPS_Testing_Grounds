// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

USTRUCT(BlueprintType)
struct FSpawnParams
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnParams")
	int MinSpawn = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnParams")
	int MaxSpawn = 4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnParams")
	int MinScale = 0.8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnParams")
	int MaxScale = 1.2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnParams")
	float Radius;
};

USTRUCT(BlueprintType)
struct FSpawnPosition
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnParams")
	FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnParams")
	float YawRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnParams")
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
	void PlaceActors(TSubclassOf<AActor> ToSpawn, FSpawnParams SpawnParameter);

	UFUNCTION(BlueprintCallable)
	void PlaceAIPawns(TSubclassOf<APawn> ToSpawn, FSpawnParams SpawnParameter);

	TArray<FSpawnPosition> RandomSpawnPosition(FSpawnParams SpawnParameter);

	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(UActorPool* InPool);

private:
	template<class T>
	void RandomlyPlaceActors(TSubclassOf<T> ToSpawn, int MinSpawn, int MaxSpawn, float Radius = 500.f, float MinScale = 1.f, float MaxScale = 1.f);

	void PlaceObject(TSubclassOf<AActor> ToSpawn, FSpawnPosition &SpawnPosition);

	void PlaceObject(TSubclassOf<APawn> ToSpawn, FSpawnPosition &SpawnPosition);

	void PositionNavMeshBoundsVolume();

	bool CanSpawnAtLocation(FVector Location, float Radius);

	bool FindEmptyLocation(FVector &OutLocation, float Radius);

	UActorPool *Pool;

	AActor* NavMeshBoundsVolume;
};
