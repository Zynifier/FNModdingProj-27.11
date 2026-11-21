// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineLinkId.generated.h"

UENUM(BlueprintType)
enum class ELinkCodeUserInputError : uint8
{
	InvalidMnemonicCharacter = 0,
	InvalidMnemonicLength = 1,
	InvalidVersionFormat = 2,
	NoError = 3,
};

USTRUCT(BlueprintType)
struct LINKID_API FOnlineLinkId
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="Unique Identifier")
	FString Mnemonic;

	UPROPERTY(BlueprintReadOnly, Category="Version")
	int32 Version;

};

