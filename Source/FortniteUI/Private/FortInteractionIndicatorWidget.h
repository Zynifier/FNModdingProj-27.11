// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortActorIndicatorWidget.h"
#include "FortInteractionIndicatorWidget.generated.h"

class UCommonVisibilitySwitcher;
class UFortInteractContextInfo;
class UFortInteractContextInfoWidget;

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI", ClassGroup="UI", DisableNativeTick))
class UFortInteractionIndicatorWidget : public UFortActorIndicatorWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortInteractionIndicatorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_PrimaryContext;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortInteractionIndicatorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_SecondaryContext;

private:
	UFUNCTION(BlueprintCallable)
	UFortInteractContextInfoWidget* ActivateContextOverride(const TSubclassOf<UFortInteractContextInfoWidget>& ContextOverrideWidget, const UFortInteractContextInfo* ContextInfo, bool bPrimary = true);

	UFUNCTION()
	void HandleAddContextOverride(TSubclassOf<UFortInteractContextInfoWidget> ContextOverrideWidget, bool bPrimary);

	UFUNCTION()
	void HandleImprovedDBNOStateChanged(bool bImprovedDBNOEnabled);

	UFUNCTION()
	void HandleRemoveContextOverride(TSubclassOf<UFortInteractContextInfoWidget> ContextOverrideWidget, bool bPrimary);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<TSubclassOf<UFortInteractContextInfoWidget>, TObjectPtr<UFortInteractContextInfoWidget>> PrimaryContextOverrideMap;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<TSubclassOf<UFortInteractContextInfoWidget>, TObjectPtr<UFortInteractContextInfoWidget>> SecondaryContextOverrideMap;

};

