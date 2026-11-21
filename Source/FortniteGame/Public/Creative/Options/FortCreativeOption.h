// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "FortMatchmakingKnobsDataSource.h"
#include "FortCreativeOption.generated.h"

class UFortCreativeOption;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCreativeOptionChanged, UFortCreativeOption*, ChangedOption, uint8, IndexValue);

USTRUCT(BlueprintType)
struct FCreativeOptionCategoryData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeOptionCategoryData")
	FText CategoryDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeOptionCategoryData")
	FName CategoryTag;

};

USTRUCT(BlueprintType)
struct FCreativeOptionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeOptionData")
	FText DisplayText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeOptionData")
	int32 Value;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortCreativeOption : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DecrementIndexWithWrap();

	UFUNCTION(BlueprintPure)
	bool DoesMatchCategory(FCreativeOptionCategoryData& CreativeOptionCategory);

	UFUNCTION(BlueprintPure)
	FText GetCreativeOptionTextAtCurrent();

	UFUNCTION(BlueprintPure)
	FText GetCreativeOptionTextAtIndex(int32 Index);

	UFUNCTION(BlueprintPure)
	int32 GetCurrentIndex();

	UFUNCTION(BlueprintPure)
	int32 GetValueAtCurrentIndex();

	UFUNCTION(BlueprintPure)
	int32 GetValueAtIndex(int32 Index);

	UFUNCTION(BlueprintCallable)
	void IncrementIndexWithWrap();

	UFUNCTION(BlueprintCallable)
	void SetCurrentIndex(int32 Index);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeOption")
	FText OptionText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeOption")
	FText OptionToolTip;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeOption")
	FName CategoryTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeOption")
	FSlateBrush DisplayIcon;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeOptionChanged OnCreativeOptionChanged;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeOption")
	TArray<FCreativeOptionData> Options;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeOption")
	FGameplayTag VariableTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeOption")
	TEnumAsByte<UFortMatchmakingKnobsDataSource::Type> MenuListType;

protected:
	UPROPERTY()
	int32 CurrentIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeOption")
	FScalableFloat DefaultOptionIndex;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortCreativeOptionsBundle : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeOptionsBundle")
	TArray<TObjectPtr<UFortCreativeOption>> CreativeOptions;

};

