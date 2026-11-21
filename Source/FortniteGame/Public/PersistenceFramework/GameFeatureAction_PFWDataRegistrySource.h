// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_PFWDataRegistrySource.generated.h"

class UPersistenceFrameworkTagToServiceTable;

USTRUCT()
struct FPFWDataRegistrySourceToAdd
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Registry Data")
	FName RegistryToAddTo;

	UPROPERTY(EditAnywhere, Category="Registry Data")
	int32 AssetPriority;

	UPROPERTY(EditAnywhere, Category="Registry Data")
	TSoftObjectPtr<UPersistenceFrameworkTagToServiceTable> ServiceTableToAdd;

};

UCLASS(meta=(DisplayName="Persistence Framework Settings Override"))
class FORTNITEGAME_API UGameFeatureAction_PFWDataRegistrySource : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Persistence Data")
	FName ModeName;

	UPROPERTY(EditAnywhere, Category="Registry Data")
	TArray<FPFWDataRegistrySourceToAdd> SettingOverrideTables;

	UPROPERTY(EditAnywhere, Category="Registry Data")
	bool bPreloadInEditor;

};

