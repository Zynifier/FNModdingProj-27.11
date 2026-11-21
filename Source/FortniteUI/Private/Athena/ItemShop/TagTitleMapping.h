// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "TagTitleMapping.generated.h"

UCLASS()
class UAthenaItemShopTagTitleMapping : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AthenaItemShopTagTitleMapping", meta=(TitleProperty="Offer Tag"))
	TMap<FGameplayTag, FText> TagTitleMap;

};

