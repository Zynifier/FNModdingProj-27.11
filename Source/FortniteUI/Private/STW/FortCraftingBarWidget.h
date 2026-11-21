// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortCraftingBarWidget.generated.h"

class UCommonTextBlock;
class UProgressBar;
enum class EFortCraftFailCause : uint8;

UCLASS(BlueprintType, Blueprintable)
class UFortCraftingBarWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Crafting Bar Widget")
	void SetHideCraftingBar(bool bInHideCraftBar);

protected:
	UFUNCTION()
	void HandlePlayerStartedCrafting();

	UFUNCTION()
	void HandlePlayerStoppedCrafting(bool bSuccess, EFortCraftFailCause CraftFailureCause);

	UFUNCTION()
	void OnCompletedSetHidden();

	UPROPERTY(BlueprintReadOnly, Export, Category="Crafting Bar Widget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CraftingText;

	UPROPERTY(BlueprintReadOnly, Export, Category="Crafting Bar Widget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> CraftingProgressBar;

	UPROPERTY(EditDefaultsOnly, Category="Crafting Bar Widget")
	float CompletedRemainVisibleTime;

};

