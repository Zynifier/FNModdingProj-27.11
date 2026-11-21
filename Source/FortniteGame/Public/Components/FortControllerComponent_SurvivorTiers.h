// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "FortControllerComponent_SurvivorTiers.generated.h"

class IQuestInstanceInterface;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UFortControllerComponent_SurvivorTiers : public UControllerComponent
{
	GENERATED_BODY()

public:
	UFortControllerComponent_SurvivorTiers(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	void GetPrestigeAndTier(int32& OutSurvivorPrestige, int32& OutSurvivorTierRaw, int32& OutSurvivorTierDisplay) const;

protected:
	UFUNCTION()
	void HandleMCPSurvivorStateChanged();

	UFUNCTION()
	void HandleQuestCompleted(const TScriptInterface<IQuestInstanceInterface>& QuestInstance);

};

