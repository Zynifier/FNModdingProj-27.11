// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemQuantityPair.h"
#include "Items/FortAccountItemDefinition.h"
#include "STW/FortHomebase/FortHomebaseManager.h"
#include "FortHomebaseNodeItemDefinition.generated.h"

class UFortAbilityKit;

UENUM(BlueprintType)
enum class EHomebaseNodeType : uint8
{
	Gadget = 0,
	Utility = 1,
	Hidden = 2,
};

USTRUCT(BlueprintType)
struct FHomebaseNodeLevel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NodePayload")
	FName DisplayDataId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NodeLevel")
	int32 MinCommanderLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NodeLevel")
	TArray<FFortItemQuantityPair> Cost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NodeLevel")
	TArray<FName> GameplayEffectRowNames;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NodeLevel", meta=(AssetBundles="ClientCampaign, Server"))
	TSoftObjectPtr<UFortAbilityKit> AbilityKit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NodeLevel")
	TArray<FHomebaseSquadSlotId> UnlockedSquadSlots;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortHomebaseNodeItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HomebaseNodeItemDefinition")
	TArray<FHomebaseNodeLevel> LevelData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HomebaseNodeItemDefinition")
	EHomebaseNodeType DisplayType;

};

