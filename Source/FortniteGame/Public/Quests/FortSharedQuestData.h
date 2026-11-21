// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortSharedQuestData.generated.h"

class UDataTable;

USTRUCT()
struct FSharedQuestBucketData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SharedQuestBucketData")
	FString Identifier;

	UPROPERTY(EditDefaultsOnly, Category="SharedQuestBucketData")
	int32 NumAutoFill;

	UPROPERTY(EditDefaultsOnly, Category="SharedQuestBucketData")
	TArray<FString> Playlists;

};

UCLASS(BlueprintType)
class UFortSharedQuestData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortSharedQuestData")
	TArray<FSharedQuestBucketData> Buckets;

	UPROPERTY(EditDefaultsOnly, Category="FortSharedQuestData")
	TObjectPtr<UDataTable> SharedQuestsTable;

};

