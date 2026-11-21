// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "ActivityBrowser/FortActivityBrowserView.h"
#include "FortTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "FortActivitySearchView.generated.h"

class UEditableText;
enum class EFortActivityValidationResult : uint8;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortActivitySearchView : public UFortActivityBrowserView, public IFortTabInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActivityClear();

	UFUNCTION(BlueprintImplementableEvent)
	void OnActivityValidated(const EFortActivityValidationResult ValidateResult);

private:
	UFUNCTION()
	void HandleTextChanged(const FText& Text);

	UFUNCTION()
	void HandleTextCommitted(const FText& InText, ETextCommit::Type CommitInfo);

	UPROPERTY(EditDefaultsOnly, Category="Tab Interface")
	FName TabNameId;

	UPROPERTY(EditDefaultsOnly, Category="Tab Interface")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_IslandLink;

};

