// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "GameplayTagContainer.h"
#include "UI/Tutorial/HighlightableInterface.h"
#include "FortHUDElementWidget.generated.h"

class UFortHUDElementWidget;
class UTutorialHighlight;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortHUDElementWidget : public UCommonUserWidget, public IHighlightableInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="HUD")
	FORTNITEUI_API void AppendHUDElementTags(const FGameplayTagContainer& AdditionalTags);

	UFUNCTION()
	FORTNITEUI_API void HandleGetHUDElementWidgetsForTags(const FGameplayTagContainer& HUDElementTags, TArray<UFortHUDElementWidget*>& OutWidgets);

	UFUNCTION(BlueprintPure, Category="HUD")
	FORTNITEUI_API bool HasAnyTags(const FGameplayTagContainer& InTags) const;

protected:
	UFUNCTION()
	FORTNITEUI_API virtual void HandleOnHUDElementVisibilityChanged(const FGameplayTagContainer& HiddenHUDElementTags);

	UFUNCTION(BlueprintImplementableEvent, Category="Visibility")
	FORTNITEUI_API void OnVisibilitySetEvent(ESlateVisibility InVisibility);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HUD", meta=(DisplayName="Tag"))
	FGameplayTag ElementTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HUD", meta=(DisplayName="Tags (Extra)"))
	FGameplayTagContainer HUDElementTag;

	UPROPERTY(EditAnywhere, Category="HUD")
	ESlateVisibility HiddenVisibility;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bRequiresAnElementTag;
#endif

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UTutorialHighlight> TutorialHighlight;

};

