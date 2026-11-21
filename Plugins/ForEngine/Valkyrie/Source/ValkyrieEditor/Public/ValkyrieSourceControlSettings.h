// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ValkyrieSourceControlSettings.generated.h"

UENUM()
enum class EValkyrieSourceControlSettingsFileVersion : uint8
{
	Invalid = 0,
	Initial = 1,
	LatestPlusOne = 2,
	Latest = 1,
};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieSourceControlSettings
{
	GENERATED_BODY()

private:
	UPROPERTY()
	uint8 FileVersion;

	UPROPERTY()
	FString ProviderName;

	UPROPERTY()
	TMap<FString, FString> ProviderParameters;

};

