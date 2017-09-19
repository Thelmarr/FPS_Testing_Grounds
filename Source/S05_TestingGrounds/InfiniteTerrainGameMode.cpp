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
	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANavMeshBoundsVolume::StaticClass(), FoundVolumes);
	
	size_t j = 0;
	
	for (size_t i = 0; i < j; i++)
	{
		AddtoPool(Cast<ANavMeshBoundsVolume>(FoundVolumes[i]));
		UE_LOG(LogTemp, Warning, TEXT("Pool [%s]: Volume added: [%s]!"), *(NavMeshPool->GetName()), *(FoundVolumes[i]->GetName()));
	}
	/*TActorIterator<ANavMeshBoundsVolume> NavMeshIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (NavMeshIterator)
	{
		AddtoPool(*NavMeshIterator);
		j++;
		++NavMeshIterator;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Pool Populated: [%s], Pool Size: [%f]!"), *(NavMeshPool->GetName()), j);*/
	
}