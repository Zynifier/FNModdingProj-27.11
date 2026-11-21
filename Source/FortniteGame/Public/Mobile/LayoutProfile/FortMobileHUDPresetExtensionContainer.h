// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Mobile/LayoutProfile/FortMobileHUDPresetExtension.h"
#include "FortMobileHUDPresetExtensionContainer.generated.h"

UCLASS(MinimalAPI)
class UFortMobileHUDPresetExtensionContainer : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDPresetExtensionContainer", meta=(Categories="HUDLayout.PresetExtensionContainer"))
	FGameplayTag HUDPresetExtensionContainerTag;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDPresetExtensionContainer", meta=(Categories="HUDLayout.PresetContainer"))
	FGameplayTag HUDPresetContainerToExtendTag;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDPresetExtensionContainer")
	TArray<FFortMobileHUDPresetExtension> HUDPresetExtensions;

};

