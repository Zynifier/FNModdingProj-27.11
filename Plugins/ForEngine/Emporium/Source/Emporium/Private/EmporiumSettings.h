// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "EmporiumSettings.generated.h"

UENUM()
enum class EEmporiumEnvironment : uint8
{
	Production = 0 UMETA(DisplayName="Production"),
	PreProduction = 1 UMETA(DisplayName="Pre-Production"),
	CI = 2 UMETA(DisplayName="CI"),
	Gamedev = 3 UMETA(DisplayName="Gamedev"),
	PreGamedev = 4 UMETA(DisplayName="Pre-Gamedev"),
	CustomUrl = 5 UMETA(DisplayName="Custom URL"),
};

UCLASS(Config=EditorPerProjectUserSettings, HideCategories=("HiddenProperties"))
class UEmporiumSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Frontend", meta=(DevOnly="TRUE"))
	EEmporiumEnvironment Environment;

	UPROPERTY(EditAnywhere, Config, Category="Frontend", meta=(DevOnly="TRUE"))
	FString CustomUrl;

	UPROPERTY(EditAnywhere, Config, Category="Frontend", meta=(DevOnly="TRUE"))
	FString CustomAuthToken;

	UPROPERTY(EditAnywhere, Config, Category="Frontend", meta=(DevOnly="TRUE"))
	bool bUseCustomAuthToken;

	UPROPERTY(EditAnywhere, Config, Category="General")
	FDirectoryPath DownloadDirectory;

	UPROPERTY(EditAnywhere, Config, Category="General")
	FDirectoryPath MostRecentDownloadDirectory;

	UPROPERTY(EditAnywhere, Config, Category="Mesh")
	bool bCreateCollision;

	UPROPERTY(EditAnywhere, Config, Category="Mesh")
	bool bCreateLods;

	UPROPERTY(EditAnywhere, Config, Category="Mesh")
	bool bNormalizeScale;

	UPROPERTY(EditAnywhere, Config, Category="Mesh")
	bool bNormalizePivot;

};

