// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "FortCreativeClassInstanceTracker.h"
#include "FortClassTrackerComponent.generated.h"

class AActor;
class IFortSpatialGameplayInterface;

UCLASS(MinimalAPI)
class UFortClassTrackerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AddActor(AActor* Actor, TScriptInterface<IFortSpatialGameplayInterface> Volume);

	UFUNCTION()
	void RemoveActor(AActor* Actor, TScriptInterface<IFortSpatialGameplayInterface> Volume);

protected:
	UPROPERTY(Transient)
	TScriptInterface<IFortSpatialGameplayInterface> ParentSpatialInterface;

	UPROPERTY(Replicated)
	bool bEnabled;

	UPROPERTY(Replicated)
	FFortCreativeClassInstanceTracker ClassTracker;

	UPROPERTY(Replicated)
	FGameplayTagContainer ExcludeActorTags;

};

