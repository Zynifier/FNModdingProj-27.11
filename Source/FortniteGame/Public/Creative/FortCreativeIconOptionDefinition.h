// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Creative/FortCreativeIconOption.h"
#include "FortUserOptionDefinitions.h"
#include "FortCreativeIconOptionDefinition.generated.h"

class UDataTable;

USTRUCT(BlueprintType)
struct FUserOptionDefinitionIconValueEntry : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FCreativeIconOption Value;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionIconMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FCreativeIconOption DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.UserOptionDefinitionIconValueEntry"))
	TObjectPtr<UDataTable> IconsDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(EditCondition="IconsDataTable == nullptr", EditConditionHides))
	TArray<FUserOptionDefinitionIconValueEntry> ValueEntries;

};

