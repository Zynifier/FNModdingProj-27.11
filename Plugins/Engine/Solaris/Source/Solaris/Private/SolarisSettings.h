// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SolarisSettings.generated.h"

UCLASS(Config=Game, DefaultConfig)
class USolarisGameSettings : public UObject
{
	GENERATED_BODY()

public:
	/// Names of classes or methods whose use we want to disallow

	UPROPERTY(Config)
	TArray<FString> Blacklist;

	/// The maximum byte code length we allow per method
/// Name is deliberately indescriptive to prevent "leaking"

	UPROPERTY(Config)
	int32 MaxAllowedSize;

};

