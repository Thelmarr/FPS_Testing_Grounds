// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "GrassComponent.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API UGrassComponent : public UHierarchicalInstancedStaticMeshComponent
{
	GENERATED_BODY()

	UGrassComponent();

public:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	FBox SpawnArea;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int SpawnCount;

	void SpawnGrass();
protected:
	virtual void BeginPlay() override;
};
