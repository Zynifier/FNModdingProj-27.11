// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "CommonUserWidget.h"
#include "FortActivityBrowserRow.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, Config=Game, NotBlueprintable, meta=(DisableNativeTick))
class UFortActivityBrowserRow : public UCommonUserWidget, public IUserListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetIsActive() const;

	UFUNCTION(BlueprintPure)
	bool GetIsInPeekState() const;

	UFUNCTION(BlueprintPure)
	bool GetIsSelected() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCategoryItemChanged(const bool bPlayAnimation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRowIsActiveChanged(const bool bIsActive);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRowIsSelectedChanged(const bool bIsSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRowMoveDown(const bool bMovingOffscreen);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRowMoveUp(const bool bMovingOffscreen);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRowPeekStateChanged(const bool bIsInPeekState);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserRow", meta=(AllowPrivateAccess, BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> Text_CategoryName;

	UPROPERTY(Config)
	float MinimumVisibilityPercentageForRowActivation;

};

