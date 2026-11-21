// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "Creative/FortCreativeIslandSelectTab.h"
#include "FortCreativeIslandSelectCodeTab.generated.h"

class UCommonButtonBase;
class UEditableText;
class UFortCreativeIslandDetailsPanel;
class UFortGameActivity;
class UFortGameActivityProvider;
class UWidget;
enum class EFortActivityValidationResult : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeIslandSelectCodeTab : public UFortCreativeIslandSelectTab
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void HandleActivityChanged(const FText& Text);

	UFUNCTION(BlueprintCallable)
	void HandleActivityCommitted(const FText& InText, ETextCommit::Type CommitInfo);

	UFUNCTION(BlueprintImplementableEvent)
	void OnActivityClear();

	UFUNCTION(BlueprintImplementableEvent)
	void OnActivityValidated(const EFortActivityValidationResult ValidateResult);

	UFUNCTION(BlueprintImplementableEvent)
	void OnActivityValidatedWithEmptyIslandLink();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Select;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_IslandLink;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativeIslandDetailsPanel> IslandDetailsPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Favorite;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_LaunchError;

	UPROPERTY()
	TObjectPtr<UFortGameActivityProvider> ActivityProvider;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandSelectCodeTab")
	TObjectPtr<UFortGameActivity> LastActivityQueried;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandSelectCodeTab")
	TObjectPtr<UFortGameActivity> UserEnteredActivity;

};

