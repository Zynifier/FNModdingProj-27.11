// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Items/FortCloudSaveItemDefinition.h"
#include "FortDeployableBaseCloudSaveItemDefinition.generated.h"

USTRUCT()
struct FFortTierProgressionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProgressionLayoutGuid;

	UPROPERTY()
	int32 HighestDefeatedTier;

};

USTRUCT()
struct FFortTierProgression
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortTierProgressionInfo> ProgressionInfo;

};

UCLASS(BlueprintType)
class UFortDeployableBaseCloudSaveItemDefinition : public UFortCloudSaveItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, DuplicateTransient, Category="GUID")
	FGuid SaveFilenameGUID;

};

