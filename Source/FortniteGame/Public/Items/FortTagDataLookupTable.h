// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortMultiSize.h"
#include "FortTagDataLookupTable.generated.h"

USTRUCT(BlueprintType)
struct FFortTagUIData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TagData")
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	FFortMultiSizeBrush Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	FText Description;

};

UCLASS(MinimalAPI)
class UFortTagUIDataLookupTable : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Attributes")
	TArray<FFortTagUIData> TagUIDataList;

};

