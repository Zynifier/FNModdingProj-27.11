// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortItemAutoMulchSettingRow.generated.h"

enum class EFortAutoMulchCategory : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemAutoMulchSettingRow : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AutoMulch")
	FText GetAutoMulchCategoryText() const;

	UFUNCTION(BlueprintPure, Category="AutoMulch")
	FText GetAutoMulchModeText() const;

	UFUNCTION(BlueprintCallable, Category="AutoMulch")
	void SelectNextAutoMulchMode();

	UFUNCTION(BlueprintCallable, Category="AutoMulch")
	void SelectPreviousAutoMulchMode();

	UFUNCTION(BlueprintCallable, Category="AutoMulch")
	void SetAutoMulchCategory(EFortAutoMulchCategory NewCategory);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="AutoMulch")
	void HandleAutoMulchCategoryChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="AutoMulch")
	void HandleAutoMulchModeChanged();

};

