// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortLockerConfigManager.generated.h"

class UFortLockerConfig;
class UFortRuntimeLockerConfig;

UCLASS(MinimalAPI)
class UFortLockerConfigManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortRuntimeLockerConfig> RuntimeLockerConfig;

	UPROPERTY(Transient)
	TObjectPtr<UFortLockerConfig> PlaylistLockerConfigOverride;

};

