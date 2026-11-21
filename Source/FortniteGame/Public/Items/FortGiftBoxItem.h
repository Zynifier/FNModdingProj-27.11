// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "Items/FortGiftBoxTypes.h"
#include "McpSharedTypes.h"
#include "FortGiftBoxItem.generated.h"

class UFortGiftBoxItemDefinition;
class UFortItemDefinition;
enum class ESubGame : uint8;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnTextFiltered, bool, bSuccess, FString, SanitizedMsg);

UCLASS(MinimalAPI)
class UFortGiftBoxItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void FilterUserMessageForProfanity(int32 ControllerId, FOnTextFiltered OnTextFiltered);

	UFUNCTION(BlueprintPure)
	FText FormatTextUsingParams(const FText& FormatString) const;

	UFUNCTION(BlueprintPure)
	UFortGiftBoxItemDefinition* GetGiftBoxDefinition() const;

	UFUNCTION(BlueprintPure)
	bool HasAccountID() const;

	UFUNCTION(BlueprintPure)
	bool HasParam(const FString& ParamName) const;

	UFUNCTION(BlueprintPure)
	bool IsVisibleIn(const ESubGame SubGame) const;

	UFUNCTION(BlueprintPure)
	UFortItemDefinition* RetrieveItemDefinitionFromTemplateID(const FString& TemplateParam) const;

	UFUNCTION(BlueprintPure)
	UFortItemDefinition* RetrieveItemDefintionFromParam(const FString& ParamName) const;

	UFUNCTION(BlueprintPure)
	bool TryGetCurrencyData(TArray<FCurrencyData>& OutValue) const;

	UFUNCTION(BlueprintPure)
	bool TryGetLootListParamInt(const UFortItemDefinition* Item, const FString& ParamName, int32& OutValue) const;

	UFUNCTION(BlueprintPure)
	bool TryGetLootListParamString(const UFortItemDefinition* Item, const FString& ParamName, FString& OutValue) const;

	UFUNCTION(BlueprintPure)
	bool TryGetLootListParamText(const UFortItemDefinition* Item, const FString& ParamName, FText& OutValue) const;

	UFUNCTION(BlueprintPure)
	bool TryGetParamInt(const FString& ParamName, int32& OutValue) const;

	UFUNCTION(BlueprintPure)
	bool TryGetParamString(const FString& ParamName, FString& OutValue) const;

	UFUNCTION(BlueprintPure)
	bool TryGetParamText(const FString& ParamName, FText& OutValue) const;

	UPROPERTY(BlueprintReadOnly, Category="FortGiftBoxItem")
	FGiftBoxInfo GiftBoxInfo;

};

