// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortHUDCenterPopupMessageWidget.generated.h"

class UCommonActivatablePanelLegacy;
class UUserWidget;
enum class ECenterPopupMessageStateEnum : uint8;

UENUM(BlueprintType)
enum class ECenterPopupMessageStateEnum : uint8
{
	NotVisible = 0 UMETA(DisplayName="Not Visible"),
	WaitingForOutpostOwner = 1 UMETA(DisplayName="Waiting for Outpost Owner"),
};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortHUDCenterPopupMessageWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Center Popup Message")
	ECenterPopupMessageStateEnum GetCenterPopupMessageState() const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Center Popup Message")
	void UpdateState();

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Center Popup Message")
	void OnModalDisplayed(ECenterPopupMessageStateEnum NewState, UCommonActivatablePanelLegacy* ModalPopup);

	UPROPERTY(EditAnywhere, Category="UI", meta=(AssetBundles="Client"))
	TSoftClassPtr<UUserWidget> CenterPopupModalWidgetClass;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCommonActivatablePanelLegacy> CenterPopupModalWidget;

};

