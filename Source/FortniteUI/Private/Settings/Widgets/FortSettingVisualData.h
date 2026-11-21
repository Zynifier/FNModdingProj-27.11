// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Settings/FortSetting.h"
#include "FortSettingVisualData.generated.h"

class UFortSetting;
class UFortSettingsListEntryBase;

UCLASS(BlueprintType)
class UFortSettingVisualData : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="ListEntries", meta=(AllowAbstract))
	TMap<TSubclassOf<UFortSetting>, TSubclassOf<UFortSettingsListEntryBase>> EntryWidgetForClass;

	UPROPERTY(EditDefaultsOnly, Category="ListEntries", meta=(AllowAbstract))
	TMap<FString, TSubclassOf<UFortSettingsListEntryBase>> EntryWidgetForName;

	UPROPERTY(EditDefaultsOnly, Category="Extensions", meta=(AllowAbstract))
	TMap<TSubclassOf<UFortSetting>, FFortSettingClassExtensions> ExtensionsForClasses;

	UPROPERTY(EditDefaultsOnly, Category="Extensions")
	TMap<FString, FFortSettingNameExtensions> ExtensionsForName;

};

