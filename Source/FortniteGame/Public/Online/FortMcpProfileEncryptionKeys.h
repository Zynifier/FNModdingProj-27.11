// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMcpProfileEncryptionKeys.generated.h"

USTRUCT()
struct FFortMcpProfileEncryptionKey
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FString KeyGuid;

	UPROPERTY()
	FString KeyDescription;

	UPROPERTY()
	FString KeyData;

};

USTRUCT()
struct FFortMcpProfileEncryptionKeyData
{
	GENERATED_BODY()

};

