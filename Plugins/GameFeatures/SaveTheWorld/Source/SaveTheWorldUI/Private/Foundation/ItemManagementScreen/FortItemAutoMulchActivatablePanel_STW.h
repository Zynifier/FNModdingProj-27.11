// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortItemAutoMulchActivatablePanel_STW.generated.h"

class UFortItemManagementScreen_STW;
enum class EFortAutoMulchCategory : uint8;
enum class EFortFrontendInventoryFilter : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemAutoMulchActivatablePanel_STW : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AutoMulch")
	void SetItemManagementScreen(UFortItemManagementScreen_STW* InItemManagementScreen);

protected:
	UFUNCTION(BlueprintCallable, Category="AutoMulch")
	void CacheAutoMulchSettings();

	UFUNCTION(BlueprintCallable, Category="AutoMulch")
	void EnterMulchModeForAutoMulch();

	UFUNCTION(BlueprintPure, Category="AutoMulch")
	EFortFrontendInventoryFilter GetFrontendInventoryFilter() const;

	UFUNCTION(BlueprintPure, Category="AutoMulch")
	TArray<EFortAutoMulchCategory> GetMulchCategoriesForInventoryFilter() const;

	UFUNCTION(BlueprintCallable, Category="AutoMulch")
	void RestoreAutoMulchSettings();

	UFUNCTION(BlueprintCallable, Category="AutoMulch")
	void SaveSettings();

};

