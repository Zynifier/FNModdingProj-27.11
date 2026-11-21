// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortMultiSize.h"
#include "FortAttributeLookupTable.generated.h"

UENUM(BlueprintType)
namespace EFortAttributeDisplay
{
	enum Type
	{
		BasicInt = 0,
		NegativeImpliesInfiniteInt = 1,
		BasicFloat = 2,
		NegativeImpliesInfiniteFloat = 3,
		BasicString = 4,
		NormalizedPercentage = 5,
		StringArray = 6,
		SlateBrush = 7,
		DoNotDisplay = 8,
		None_Max = 9 UMETA(DisplayName="None"),
	};
}

USTRUCT(BlueprintType)
struct FFortAttributeDetailsInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	FGameplayTagContainer RequiredTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	FFortMultiSizeBrush Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	FText Description;

};

USTRUCT(BlueprintType)
struct FFortAttributeInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AttributeInfo")
	FGameplayAttribute Attribute;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AttributeInfo")
	TEnumAsByte<EFortAttributeDisplay::Type> DisplayMethod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AttributeInfo")
	FText UnitDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AttributeInfo")
	float DisplayScalingFactor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AttributeInfo")
	FText FormatText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	TArray<FFortAttributeDetailsInfo> AttributeDetails;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(DisplayName="Show In Building Panel Overview"))
	bool bShowInSummaries;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(DisplayName="Show In Building Panel Next Bonuses Section"))
	bool bShowInDifferences;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(DisplayName="Show As a Buff in the Front End"))
	bool bShowAsBuffInFE;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AttributeInfo")
	bool bNegativeValuesShouldBeDisplayedPositively;

};

UCLASS(MinimalAPI)
class UFortAttributeLookupTable : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, EditFixedSize, Category="Attributes")
	TArray<FFortAttributeInfo> AttributeInfoList;

};

