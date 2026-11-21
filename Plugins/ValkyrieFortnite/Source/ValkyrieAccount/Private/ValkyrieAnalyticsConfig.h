// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ValkyrieAnalyticsConfig.generated.h"

USTRUCT()
struct FValkyrieAnalyticsEventDenylistEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString EventName;

	UPROPERTY()
	double Probability;

};

UCLASS(Config=Game)
class UValkyrieAnalyticsConfig : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FValkyrieAnalyticsEventDenylistEntry> EventDenylist;

};

