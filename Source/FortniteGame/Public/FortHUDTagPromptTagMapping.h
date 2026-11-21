// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortHUDTagPromptTagMapping.generated.h"

class UUserWidget;

USTRUCT(BlueprintType)
struct FFortHUDTagPromptData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Prompt Data")
	FGameplayTag VolumeTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Prompt Data")
	FText Text_PromptTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Prompt Data")
	FText Text_PromptDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Prompt Data")
	bool bIsEnterData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Prompt Data")
	TSubclassOf<UUserWidget> WidgetClass;

};

UCLASS(MinimalAPI)
class UFortHUDTagPromptTagMapping : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Tag Mapping Data")
	TArray<FFortHUDTagPromptData> TagToPromptDataArray;

};

