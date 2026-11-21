// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ChallengeBundles/Components/FortChallengeBundleItemDefinitionComponent_CustomMapWidget.h"
#include "FortChallengeBundleItemDefinitionComponent_NPCQuestRewardWidget.generated.h"

class UFortTandemCharacterData;
class UObject;

UENUM(BlueprintType)
enum class ENPCQuestRewardPanelMode : uint8
{
	ShowingRewards = 0,
	ShowingServices = 1,
};

UCLASS(meta=(DisplayName="NPC Reward Panel"))
class FORTNITEGAME_API UFortChallengeBundleItemDefinitionComponent_NPCQuestRewardWidget : public UFortChallengeBundleItemDefinitionComponent_CustomMapWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const UFortTandemCharacterData* GetNPCData() const;

	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<UObject> GetNPCIcon() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleItemDefinitionComponent_NPCQuestRewardWidget")
	FGameplayTag NPCTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleItemDefinitionComponent_NPCQuestRewardWidget")
	ENPCQuestRewardPanelMode Mode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleItemDefinitionComponent_NPCQuestRewardWidget", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> NPCIconOverride;

};

