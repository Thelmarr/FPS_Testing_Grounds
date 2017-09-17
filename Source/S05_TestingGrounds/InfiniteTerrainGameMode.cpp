// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "EngineUtils.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "InfiniteTerrainGameMode.h"

void AInfiniteTerrainGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AInfiniteTerrainGameMode::AddtoPool(ANavMeshBoundsVolume *Iterator)
{
	//ANavMeshBoundsVolume* FoundVolume = Iterator;
	UE_LOG(LogTemp, Warning, TEXT("Found Volume: %s"), *Iterator->GetName());
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