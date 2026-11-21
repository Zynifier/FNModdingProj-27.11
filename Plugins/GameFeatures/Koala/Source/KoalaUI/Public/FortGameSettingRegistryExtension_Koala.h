// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/FortSetting.h"
#include "Settings/Registry/FortGameSettingRegistryExtension.h"
#include "FortGameSettingRegistryExtension_Koala.generated.h"

UCLASS(DefaultToInstanced, EditInlineNew)
class UFortGameSettingRegistryExtension_Koala : public UFortGameSettingRegistryExtension
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortGameSettingRegistryExtension_Koala")
	FFortSettingNameExtensions SettingExtensions;

};

