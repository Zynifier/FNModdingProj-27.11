// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnlineISOConversionUtil.generated.h"

USTRUCT()
struct FOnlineISOLanguageInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FText DisplayName;

	UPROPERTY(Config)
	FString LanguageId;

	UPROPERTY(Config)
	FString BackendId;

};

USTRUCT()
struct FOnlineISORegionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FText DisplayName;

	UPROPERTY(Config)
	FString RegionId;

	UPROPERTY(Config)
	FString BackendId;

};

UCLASS(Abstract, Config=Engine)
class ONLINESUBSYSTEMMCP_API UOnlineISOConversionUtil : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FOnlineISOLanguageInfo> Languages;

	UPROPERTY(Config)
	TArray<FOnlineISORegionInfo> Regions;

};

