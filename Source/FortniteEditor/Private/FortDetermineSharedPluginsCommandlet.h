// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "FortDetermineSharedPluginsCommandlet.generated.h"

USTRUCT()
struct FSharedGFPFilter
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Order;

	UPROPERTY()
	FString PluginName;

};

UCLASS(Config=Editor)
class UFortDetermineSharedPluginsCommandlet : public UCommandlet
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FSharedGFPFilter> RootGFPsToUse;

};

