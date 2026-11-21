// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Mobile/LayoutProfile/FortMobileHUDLayoutProfileSaveTypes.h"
#include "FortMobileHUDPresetExtension.generated.h"

USTRUCT()
struct FFortMobileHUDPresetExtension
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDPresetExtension")
	FGameplayTag HUDPresetToExtend;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDPresetExtension")
	FFortMobileHUDLayoutProfileSave HUDPresetExtensionSave;

};

