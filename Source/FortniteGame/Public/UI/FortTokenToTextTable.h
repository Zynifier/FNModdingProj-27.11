// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortTokenToTextTable.generated.h"

USTRUCT(BlueprintType)
struct FFortTokenContextInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	FGameplayTagContainer RequiredContextTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	FText Text;

};

USTRUCT(BlueprintType)
struct FFortTooltipTokenInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TokenInfo", meta=(Categories="Tooltip.Token"))
	FGameplayTag Token;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	TArray<FFortTokenContextInfo> ContextDetails;

};

UCLASS()
class UFortTokenToTextTable : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Tokens")
	TArray<FFortTooltipTokenInfo> TokenInfoList;

};

