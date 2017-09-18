// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "S05_TestingGroundsGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API AInfiniteTerrainGameMode : public AS05_TestingGroundsGameMode
{
	GENERATED_BODY()

	AInfiniteTerrainGameMode();
		
	void BeginPlay();

public:
	UFUNCTION(BlueprintCallable, Category = "Navigation")
	void AddtoPool(class ANavMeshBoundsVolume *VolumeToAdd);

	UFUNCTION(BlueprintCallable, Category = "Navigation")
	void PopulateBoundsVolumePool();	

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPool *NavMeshPool;
};
