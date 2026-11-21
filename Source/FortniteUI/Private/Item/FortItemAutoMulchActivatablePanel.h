// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortItemAutoMulchActivatablePanel.generated.h"

class UFortItemManagementScreen;
enum class EFortAutoMulchCategory : uint8;
enum class EFortFrontendInventoryFilter : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemAutoMulchActivatablePanel : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AutoMulch")
	void SetItemManagementScreen(UFortItemManagementScreen* InItemManagementScreen);

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

