// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortCheatManager_CreativeRoyale.generated.h"

class UFortCreativeRealEstatePlotItemDefinition;

UCLASS()
class UFortCheatManager_CreativeRoyale : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void CreativeRoyaleLoadEditPlot() const;

	UFUNCTION(Exec)
	void CreativeRoyaleResetIslandFile() const;

	UFUNCTION(Exec)
	void CreativeRoyaleTeleportToEditZone() const;

protected:
	UFUNCTION()
	void TeleportToPlotAferLoad() const;

	UPROPERTY(EditDefaultsOnly, Category="FortCheatManager_CreativeRoyale")
	TObjectPtr<UFortCreativeRealEstatePlotItemDefinition> CreativeRoyaleEditPlotDefinition;

	UPROPERTY(EditDefaultsOnly, Category="FortCheatManager_CreativeRoyale")
	FGameplayTag CreativeRoyaleVolumeTag;

};

