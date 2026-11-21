// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartContext.generated.h"

class ULocalPlayer;
class UUIStateChartContextEntry;

UENUM()
enum class EUIStateChartContextConditionType : int32
{
	// This condition is met if the context value is unset or is set to an empty value

	IsEmpty = 0,
	// This condition is met if the context value is set or is set to a non-empty value				

	IsNotEmpty = 1,
	// This condition is met if the context value is the same as the comparison constant (ignoring case for strings)

	IsEqualTo = 2,
	// This condition is met if the context value is not the same as the comparison constant (ignoring case for strings)

	IsNotEqualTo = 3,
	// This condition is met if the context value is numerically larger than the comparison constant

	IsGreaterThan = 4,
	// This condition is met if the context value is numerically larger than or equal to the comparison constant

	IsGreaterThanOrEqualTo = 5,
	// This condition is met if the context value is numerically smaller than the comparison constant

	IsLessThan = 6,
	// This condition is met if the context value is numerically smaller than or equal to the comparison constant

	IsLessThanOrEqualTo = 7,
	// This condition is met if the context value is a boolean true value or the string "true"

	IsTrue = 8,
	// This condition is met if the context value is not the boolean true value or the string "true"

	IsNotTrue = 9,
	// This condition is met if the context value when considered as a string begins with the comparison constant, ignoring case

	StartsWith = 10,
	// This condition is met if the context value when considered as a string ends with the comparison constant, ignoring case

	EndsWith = 11,
	// This condition is met if the context value when considered as a string contains with the comparison constant, ignoring case

	Contains = 12,
};

USTRUCT(BlueprintType)
struct UICHART_API FUIStateChartContextChangeSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="UIStateChartContextChangeSet")
	TMap<FGameplayTag, FString> Changes;

};

USTRUCT()
struct UICHART_API FUIStateChartContextCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="UIStateChartContextCondition", meta=(Categories="UI.StateContext"))
	FGameplayTag Key;

	UPROPERTY(EditAnywhere, Category="UIStateChartContextCondition")
	EUIStateChartContextConditionType ConditionType;

	UPROPERTY(EditAnywhere, Category="UIStateChartContextCondition", meta=(EditCondition="ConditionType != EUIStateChartContextConditionType::IsEmpty && ConditionType != EUIStateChartContextConditionType::IsNotEmpty && ConditionType != EUIStateChartContextConditionType::IsTrue && ConditionType != EUIStateChartContextConditionType::IsNotTrue"))
	FString ComparisonConstant;

};

UCLASS()
class UICHART_API UUIStateChartContext : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DisplayName="ApplyCommonChanges"))
	void BP_ApplyCommonChanges(const FUIStateChartContextChangeSet& ContextChanges);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="ApplyPlayerChanges"))
	void BP_ApplyPlayerChanges(const ULocalPlayer* LocalPlayer, const FUIStateChartContextChangeSet& ContextChanges);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="ClearCommonValue"))
	void BP_ClearCommonValue(const FGameplayTag Key);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="ClearEntry"))
	void BP_ClearEntry(const FGameplayTag Key);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="ClearPlayerValue"))
	void BP_ClearPlayerValue(const ULocalPlayer* LocalPlayer, const FGameplayTag& Key);

	UFUNCTION(BlueprintPure, meta=(DisplayName="FindEntry"))
	UUIStateChartContextEntry* BP_FindEntry(const FGameplayTag Key) const;

	UFUNCTION(BlueprintCallable, meta=(DisplayName="SetCommonBoolValue"))
	void BP_SetCommonBoolValue(const FGameplayTag Key, bool Value);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="SetCommonFloatValue"))
	void BP_SetCommonFloatValue(const FGameplayTag Key, float Value);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="SetCommonIntValue"))
	void BP_SetCommonIntValue(const FGameplayTag Key, int32 Value);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="SetCommonStringValue"))
	void BP_SetCommonStringValue(const FGameplayTag Key, const FString Value);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="SetPlayerBoolValue"))
	void BP_SetPlayerBoolValue(const ULocalPlayer* LocalPlayer, const FGameplayTag Key, bool Value);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="SetPlayerFloatValue"))
	void BP_SetPlayerFloatValue(const ULocalPlayer* LocalPlayer, const FGameplayTag Key, float Value);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="SetPlayerStringValue"))
	void BP_SetPlayerStringValue(const ULocalPlayer* LocalPlayer, const FGameplayTag Key, const FString Value);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="SetPlayerIntValue"))
	void BP_SetPlayerValue(const ULocalPlayer* LocalPlayer, const FGameplayTag Key, int32 Value);

protected:
	UPROPERTY()
	TMap<FGameplayTag, UUIStateChartContextEntry*> Store;

};

