// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "Mobile/LayoutProfile/FortMobileHUDProfile.h"
#include "FortMobileHUDPresetContainer.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortMobileHUDPresetContainer : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDPresetContainer", meta=(Categories="HUDLayout.PresetContainer"))
	FGameplayTag HUDPresetContainerTag;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDPresetContainer", meta=(TitleProperty="HUDProfileTag"))
	TArray<FFortMobileHUDPreset> HUDProfilePresets;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortMobileHUDPresetContainer")
	bool bMergeHotfixes;
#endif

};

