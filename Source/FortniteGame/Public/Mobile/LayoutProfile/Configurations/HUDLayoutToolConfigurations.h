// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameplayTagContainer.h"
#include "Mobile/LayoutProfile/FortMobileHUDLayoutProfileSaveTypes.h"
#include "HUDLayoutToolConfigurations.generated.h"

class UFortMobileHUDPresetContainer;
class UMobileHUDLayoutLegacyConverter;

USTRUCT()
struct FFortMobileHUDPresetHotfix
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDPresetHotfix")
	FGameplayTag HUDPresetTag;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDPresetHotfix")
	FFortMobileSchemaModificationContainer Modifications;

};

UCLASS(Config=Game, MinimalAPI)
class UHUDLayoutToolConfigurations : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Legacy HUD Layout")
	TSoftClassPtr<UMobileHUDLayoutLegacyConverter> LegacyLayoutConverterClass;

private:
	UPROPERTY(EditAnywhere, Config, Category="HUD Layout Save")
	int32 MaximumCustomLayoutSaveSlots;

	UPROPERTY(EditAnywhere, Config, Category="HUD Layout Save")
	FGameplayTag DefaultHUDProfilePresetTag;

	UPROPERTY(EditAnywhere, Config, Category="HUDLayoutToolConfigurations", meta=(Categories="HUDLayout.PresetContainer"))
	FGameplayTag ActiveHUDPresetContainer;

	UPROPERTY(EditAnywhere, Config, Category="HUDLayoutToolConfigurations")
	TArray<TSubclassOf<UFortMobileHUDPresetContainer>> HUDPresetContainerClasses;

	UPROPERTY(EditAnywhere, Config, Category="HUDLayoutToolConfigurations", meta=(TitleProperty="HUDProfileTag"))
	TArray<FFortMobileHUDPresetHotfix> HUDProfilePresetHotfixes;

	UPROPERTY(EditAnywhere, Category="Action Button Defaults")
	float DefaultButtonVisualSize;

};

