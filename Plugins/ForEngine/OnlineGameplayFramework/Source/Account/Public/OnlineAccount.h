// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineAccount.generated.h"

USTRUCT()
struct FWebEnvUrl
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Url;

	UPROPERTY()
	FString RedirectUrl;

	UPROPERTY()
	FString Environment;

};

