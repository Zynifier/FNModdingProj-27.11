// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AthenaLockerUtils.generated.h"

class UFortLockerCategoryItemVM;
class UFortLockerVM;
class UUserWidget;
enum class EAthenaCustomizationCategory : uint8;

UCLASS()
class UAthenaLockerUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(WorldContext="ContextWidget"))
	static UFortLockerCategoryItemVM* FindCategoryItem(const UFortLockerVM* LockerVM, EAthenaCustomizationCategory CategoryType, int32 SlotIndex);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="ContextWidget"))
	static void HideProgressModal(const UUserWidget* ContextWidget);

	UFUNCTION(BlueprintPure, Category="MultiProduct Utilities")
	static bool IsMPLockerEnabled();

	UFUNCTION(BlueprintCallable, meta=(WorldContext="ContextWidget"))
	static void ShowProgressModal(const UUserWidget* ContextWidget, FText Title, FText Description);

};

