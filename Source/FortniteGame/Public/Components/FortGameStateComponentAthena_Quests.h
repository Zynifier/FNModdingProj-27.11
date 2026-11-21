// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Components/FortGameStateComponent_Quests.h"
#include "FortGameStateComponentAthena_Quests.generated.h"

class UFortUrgentQuestItemDefinition;
class UTexture2D;

USTRUCT()
struct FBountyQuestSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="BountyQuestSettings")
	bool bSetTargetForSquad;

	UPROPERTY(EditDefaultsOnly, Category="BountyQuestSettings")
	TSoftObjectPtr<UFortUrgentQuestItemDefinition> TargetQuestToGrantPtr;

	UPROPERTY(EditDefaultsOnly, Category="BountyQuestSettings")
	bool bGrantProtectorQuests;

	UPROPERTY(EditDefaultsOnly, Category="BountyQuestSettings")
	TSoftObjectPtr<UFortUrgentQuestItemDefinition> ProtectorQuestToGrantPtr;

	UPROPERTY(EditDefaultsOnly, Category="BountyQuestSettings")
	FScalableFloat MediumThreatRange;

	UPROPERTY(EditDefaultsOnly, Category="BountyQuestSettings")
	FScalableFloat HighThreatRange;

	UPROPERTY(EditDefaultsOnly, Category="BountyQuestSettings")
	FScalableFloat ThreatRefreshRate;

	UPROPERTY(EditDefaultsOnly, Category="BountyQuestSettings")
	TSoftObjectPtr<UTexture2D> NPCIcon;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponentAthena_Quests : public UFortGameStateComponent_Quests
{
	GENERATED_BODY()

};

