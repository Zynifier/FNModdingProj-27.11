// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DiscordRuntimeSettings.generated.h"

UCLASS(Config=Engine, DefaultConfig)
class UDiscordRuntimeSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	bool bEnableJoinSecrets;

};

