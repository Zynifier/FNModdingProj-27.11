// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerStateEncryptionKey.generated.h"

USTRUCT()
struct FPlayerStateEncryptionKey
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<uint8> Key;

};

