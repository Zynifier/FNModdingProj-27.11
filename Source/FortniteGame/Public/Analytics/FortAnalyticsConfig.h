// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortAnalyticsConfig.generated.h"

UENUM()
enum class EFortAnalyticsEventDenylistPlaylistKey : int32
{
	PlaylistType = 0,
	PlaylistName = 1,
	All = 2,
};

USTRUCT()
struct FFortAnalyticsEventDenylistEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortAnalyticsEventDenylistPlaylistKey Type;

	UPROPERTY()
	FName PlaylistKey;

	UPROPERTY()
	FString EventName;

	UPROPERTY()
	double Probability;

};

UCLASS(Config=Game)
class UFortAnalyticsConfig : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TArray<FString> AltDomains;

	UPROPERTY(Config)
	FString UrlEndpoint;

private:
	UPROPERTY(Config)
	TArray<FFortAnalyticsEventDenylistEntry> EventDenylist;

};

