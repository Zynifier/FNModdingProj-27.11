// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "FortEventLevelNavigationBangCheckComponent.generated.h"

class AFortEventLevelNavigationActor;

UCLASS(meta=(BlueprintSpawnableComponent))
class UFortEventLevelNavigationBangCheckComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInitializedForPlayer();

	UPROPERTY(EditAnywhere, Category="FortEventLevelNavigationBangCheckComponent")
	FGameplayTag BangTrackerTag;

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortEventLevelNavigationActor> OwningNavigationActor;

};

