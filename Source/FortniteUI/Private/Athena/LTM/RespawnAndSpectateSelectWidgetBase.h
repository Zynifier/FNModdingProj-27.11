// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/FortActivatablePanelLTM.h"
#include "UIManager/AthenaHUDPrimaryContentInterface.h"
#include "RespawnAndSpectateSelectWidgetBase.generated.h"

class AFortAthenaMutator_RespawnAndSpectateSelect;
class UCommonButtonLegacy;
class URespawnAndSpectateSelectButtonWidgetBase;
class URichTextBlock;
class UWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRespawnAndSpectateSelectOptionSelected, int32, SelectedOption);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class URespawnAndSpectateSelectWidgetBase : public UFortActivatablePanelLTM, public IAthenaHUDPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	int32 GetCurrentlyHoveredButtonIndex() const;

	UFUNCTION(BlueprintPure)
	virtual UWidget* NativeGetDesiredFocusTarget() const;

	UFUNCTION()
	void OnSelectionConfirmed();

	UFUNCTION()
	void OnSelectionHovered(URespawnAndSpectateSelectButtonWidgetBase* Widget);

	UFUNCTION()
	void OnSelectionMade(URespawnAndSpectateSelectButtonWidgetBase* Widget);

	UFUNCTION()
	void OnSelectionMadeMobile(URespawnAndSpectateSelectButtonWidgetBase* Widget);

	UFUNCTION(BlueprintImplementableEvent)
	void StartClosingWidget();

	UPROPERTY(BlueprintReadOnly, Category="RespawnAndSpectateSelectWidgetBase")
	TObjectPtr<AFortAthenaMutator_RespawnAndSpectateSelect> CachedMutator;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<URespawnAndSpectateSelectButtonWidgetBase>> SelectButtonWidgets;

	UPROPERTY(EditDefaultsOnly, Category="RespawnAndSpectateSelectWidgetBase")
	FText HeaderText_Preview;

	UPROPERTY(EditDefaultsOnly, Category="RespawnAndSpectateSelectWidgetBase")
	FText HeaderText_Selectable;

	UPROPERTY(EditDefaultsOnly, Category="RespawnAndSpectateSelectWidgetBase")
	FText HeaderText_NoOptions;

	UPROPERTY(EditDefaultsOnly, Category="RespawnAndSpectateSelectWidgetBase")
	FText DescriptionText_Preview;

	UPROPERTY(EditDefaultsOnly, Category="RespawnAndSpectateSelectWidgetBase")
	FText DescriptionText_Selectable;

	UPROPERTY(EditDefaultsOnly, Category="RespawnAndSpectateSelectWidgetBase")
	FText DescriptionText_NoOptions;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> ConfirmButton;

private:
	UFUNCTION()
	void OnAvailableOptionsChanged();

	UFUNCTION()
	void OnLocalPlayerRespawned();

	UFUNCTION()
	void OnRespawnBecameAvailable();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> TextHeader;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<URichTextBlock> TextDescription;

};

