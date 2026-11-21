// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestProductGroup.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FQuestProductData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="QuestProductData")
	bool bAlwaysActive;

	UPROPERTY(EditDefaultsOnly, Category="QuestProductData", meta=(EditCondition="!bAlwaysActive"))
	TArray<FString> LinkIdStrings;

	UPROPERTY(EditDefaultsOnly, Category="QuestProductData")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, Category="QuestProductData")
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditDefaultsOnly, Category="QuestProductData")
	int32 SortIndex;

};

UCLASS()
class UQuestProductGroup : public UObject
{
	GENERATED_BODY()

};

