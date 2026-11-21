// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Settings/FortOptionsSettingsType.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCreativeOptions.generated.h"

class UFortItemDefinition;

USTRUCT()
struct FOptionsReleaseInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	ESettingType SettingType;

	UPROPERTY()
	int32 ReleaseVersion;

};

USTRUCT(BlueprintType)
struct FRarityArray
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="RarityArray")
	TArray<TObjectPtr<UFortItemDefinition>> Items;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeOptionsDisplay : public UFortActivatablePanel
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeSpawnDisplay : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void LoadItems();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLoadedItems();

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeSpawnDisplay")
	TArray<FRarityArray> ItemArray;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeSpawnDisplay")
	TArray<TObjectPtr<UFortItemDefinition>> AllItems;

};

