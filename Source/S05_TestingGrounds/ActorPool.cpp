// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "ActorPool.h"


// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
AActor* UActorPool::Checkout()
{
	UE_LOG(LogTemp, Warning, TEXT("[%s] Checkout"), *GetName());
	return nullptr;
}


// Called every frame
void UActorPool::Return(AActor* ActorToReturn)
{
	if (ActorToReturn == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Null-Actor eturned"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor eturned"), *ActorToReturn->GetName());
}

void UActorPool::Add(AActor* ActorToAdd)
{
	Return(ActorToAdd);
}