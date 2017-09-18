// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "EngineUtils.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "ActorPool.h"
#include "InfiniteTerrainGameMode.h"

AInfiniteTerrainGameMode::AInfiniteTerrainGameMode()
{
	NavMeshPool = CreateDefaultSubobject<UActorPool>(FName("NavMeshBoundsVolume Pool"));
}

void AInfiniteTerrainGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AInfiniteTerrainGameMode::AddtoPool(ANavMeshBoundsVolume *VolumeToAdd)
{
	NavMeshPool->Add(VolumeToAdd);
}

void AInfiniteTerrainGameMode::PopulateBoundsVolumePool()
{
	TActorIterator<ANavMeshBoundsVolume> NavMeshIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (NavMeshIterator)
	{
		AddtoPool(*NavMeshIterator);
		++NavMeshIterator;
	}
}