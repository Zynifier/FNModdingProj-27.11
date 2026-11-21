// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpatialFactionPerkTier.generated.h"

class USpatialFactionPerkProgress;
class USpatialFactionPerkReward;

UCLASS(Abstract, BlueprintType, Blueprintable)
class USpatialFactionPerkTier : public UUserWidget
{
	GENERATED_BODY()

public:
	USpatialFactionPerkTier(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFactionSet(bool bIsCurrentFactionEarned, bool bIsRevealed, int32 FactionNumber);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitializePerkTier(int32 PerkLevel, bool bIsRevealed, int32 PerkIndex);

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionPerkTier", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USpatialFactionPerkReward> Reward_Faction1;

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionPerkTier", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USpatialFactionPerkProgress> Progress_Faction1;

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionPerkTier", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USpatialFactionPerkReward> Reward_Faction2;

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionPerkTier", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USpatialFactionPerkProgress> Progress_Faction2;

};

