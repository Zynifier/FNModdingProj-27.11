// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPurchaseTypes.generated.h"

USTRUCT()
struct FPlatformPurchaseErrorCodeMessage
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ErrorCode;

	UPROPERTY()
	FText Title;

	UPROPERTY()
	TArray<FText> Messages;

};

USTRUCT()
struct FPlatformPurchaseErrorCodeMessages
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FPlatformPurchaseErrorCodeMessage> ErrorCodeMessageList;

};

