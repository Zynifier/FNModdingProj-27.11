// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortPlayerBanned.generated.h"

class UCommonButtonLegacy;
class UCommonRichTextBlock;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPlayerBanned : public UFortActivatablePanel
{
	GENERATED_BODY()

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialBanModal : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayModeSet(bool bIsBanned);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialBanModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CloseModal;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_TimeRemaining;

};

