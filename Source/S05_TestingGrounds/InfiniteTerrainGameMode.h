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

	void BeginPlay();

public:
	UFUNCTION(BlueprintCallable, Category = "Navigation")
	void AddtoPool(ANavMeshBoundsVolume *Iterator);

	UFUNCTION(BlueprintCallable, Category = "Navigation")
	void PopulateBoundsVolumePool();	
};
