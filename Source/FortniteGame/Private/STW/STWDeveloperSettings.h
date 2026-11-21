// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "FortItemAndCount.h"
#include "STWDeveloperSettings.generated.h"

class UFortAbilityKit;

USTRUCT()
struct FDevHeroClassInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="DevHeroClassInfo")
	FString Name;

	UPROPERTY(EditAnywhere, Category="DevHeroClassInfo")
	int32 Level;

};

UCLASS(Config=EditorPerProjectUserSettings, meta=(DisplayName="Save The World Cheats"))
class USTWDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="STWDeveloperSettings")
	TArray<FString> CheatsToRunOnPlayerPawnPossession;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="STWDeveloperSettings")
	TArray<FItemAndCount> InventoryItemsToGrant;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Save The World")
	TArray<FDevHeroClassInfo> DevHeroes;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Ability")
	TArray<TObjectPtr<UFortAbilityKit>> DevAbilityKits;
#endif

};

