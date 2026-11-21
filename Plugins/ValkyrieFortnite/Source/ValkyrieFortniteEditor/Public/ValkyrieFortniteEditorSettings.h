// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DocumentationRedirect.h"
#include "ValkyrieEditorSettings.h"
#include "ValkyrieFortniteEditorSettings.generated.h"

class ABuildingActor;
class AFortMinigameSettingsBuilding;
class AGameModeBase;
class AInfo;
class UFortPlaysetItemDefinition;

UCLASS()
class VALKYRIEFORTNITEEDITOR_API UValkyrieFortniteEditorSettings : public UValkyrieEditorSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="ValkyrieFortniteEditorSettings")
	TArray<FString> AssetNamePrefixesToRemove;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieFortniteEditorSettings")
	TMap<FString, FString> AssetNameSubstitutions;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieFortniteEditorSettings")
	TSoftClassPtr<AGameModeBase> DefaultGameMode;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieFortniteEditorSettings", meta=(MustImplement="/Script/FortniteGame.FortTimeOfDayManagerInterface"))
	TSoftClassPtr<AInfo> DefaultTimeOfDayManager;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieFortniteEditorSettings", meta=(MustImplement="/Script/FortniteGame.FortTimeOfDayManagerInterface"))
	TSoftClassPtr<AInfo> DefaultIslandImportTimeOfDayManager;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieFortniteEditorSettings")
	TSoftClassPtr<AFortMinigameSettingsBuilding> ExperienceSettingsClass;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieFortniteEditorSettings")
	TSoftClassPtr<ABuildingActor> ItemSpawnerClass;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieFortniteEditorSettings")
	TSoftObjectPtr<UFortPlaysetItemDefinition> PlayerSpawnerDeviceItemDef;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieFortniteEditorSettings")
	TArray<FDocumentationRedirect> DocumentationRedirects;

};

