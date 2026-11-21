// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Commandlets/WorldPartitionConvertCommandlet.h"
#include "FortWorldPartitionConvertCommandlet.generated.h"

UCLASS()
class UFortWorldPartitionConvertCommandlet : public UWorldPartitionConvertCommandlet
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FString> FoundationPathsToDiscard;

};

