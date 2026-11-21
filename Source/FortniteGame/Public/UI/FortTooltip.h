// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "UI/FortTooltipManager.h"
#include "FortTooltip.generated.h"

class UFortTooltipContext;
class UObject;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(ShortTooltip="Gathers data for display in tooltips."))
class UFortTooltip : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="tooltip")
	FORTNITEGAME_API virtual bool GetNumericValue(const UObject* ObjectToDescribe, const FGameplayTag& Tag, const UFortTooltipContext* Context, const FGameplayTag& Token, float& OutVal) const;

	UFUNCTION(BlueprintPure, Category="Tooltip")
	FORTNITEGAME_API virtual bool GetTextForToken(const UObject* ObjectToDescribe, const FGameplayTag& Tag, const UFortTooltipContext* Context, const FGameplayTag& Token, FText& OutText) const;

	UFUNCTION(BlueprintPure, Category="tooltip")
	FORTNITEGAME_API virtual bool GetTokenizedDescriptionText(const UObject* ObjectToDescribe, const FGameplayTag& Tag, const UFortTooltipContext* Context, TArray<FText>& OutDescription) const;

	UFUNCTION(BlueprintPure, Category="tooltip")
	FORTNITEGAME_API virtual bool GetValueData(const UObject* ObjectToDescribe, const UFortTooltipContext* Context, const FGameplayTag& Token, FFortTooltipValueData& OutData) const;

	UFUNCTION(BlueprintCallable, Category="tooltip")
	FORTNITEGAME_API void SetLocalizationFloat(const FString& Name, float Value);

	UFUNCTION(BlueprintCallable, Category="tooltip")
	FORTNITEGAME_API void SetLocalizationInt(const FString& Name, int32 Value);

	UFUNCTION(BlueprintCallable, Category="tooltip")
	FORTNITEGAME_API void SetLocalizationText(const FString& Name, FText Value);

protected:
	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="GetNumericValue"))
	FORTNITEGAME_API bool BP_GetNumericValue(const UObject* ObjectToDescribe, const FGameplayTag& Tag, const UFortTooltipContext* Context, const FGameplayTag& Token, float& OutVal) const;

	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="GetTextForToken"))
	FORTNITEGAME_API bool BP_GetTextForToken(const UObject* ObjectToDescribe, const FGameplayTag& Tag, const UFortTooltipContext* Context, const FGameplayTag& Token, FText& OutText) const;

	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="GetTokenizedDescriptionText"))
	FORTNITEGAME_API bool BP_GetTokenizedDescriptionText(const UObject* ObjectToDescribe, const FGameplayTag& Tag, const UFortTooltipContext* Context, TArray<FText>& OutDescription) const;

	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="GetValueData"))
	FORTNITEGAME_API bool BP_GetValueData(const UObject* ObjectToDescribe, const UFortTooltipContext* Context, const FGameplayTag& Token, FFortTooltipValueData& OutData) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTooltip")
	FText Description;

};

