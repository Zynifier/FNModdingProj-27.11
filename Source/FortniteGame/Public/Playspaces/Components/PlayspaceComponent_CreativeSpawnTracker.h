// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_CreativeSpawnTracker.generated.h"

class AActor;
class UFortCreativeActorCollection;

UCLASS(Abstract, MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UPlayspaceComponent_CreativeCollectionBase : public UFortPlayspaceComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetCreativeActorCollection(const UFortCreativeActorCollection* NewActorCollection);

protected:
	UPROPERTY(EditAnywhere, Replicated, Category="Creative Actor Collection")
	TObjectPtr<UFortCreativeActorCollection> CreativeCollection;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_CreativeSpawnTracker : public UPlayspaceComponent_CreativeCollectionBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Creative Actor Collection")
	TArray<TSubclassOf<AActor>> ActorClassesToTrack;

};

