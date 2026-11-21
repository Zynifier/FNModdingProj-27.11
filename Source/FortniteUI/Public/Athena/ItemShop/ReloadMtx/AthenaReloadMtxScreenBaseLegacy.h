// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "UIManager/FortHUDShutdownTimerInterface.h"
#include "AthenaReloadMtxScreenBaseLegacy.generated.h"

class UAthenaSmallOfferPreviewBase;
class UCommonButtonBase;
class UCommonTextBlock;
class UFortAccountItemDefinition;
class UFortStoreFrontOfferInfo;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaReloadMtxScreenBaseLegacy : public UFortItemPreviewScreen, public IFortHUDShutdownTimerInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BlockScreenContent(const bool bBlockScreen, const FText& ContentBlockedText);

	UPROPERTY(Transient)
	TObjectPtr<UFortStoreFrontOfferInfo> OfferInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_AmountNeeded;

private:
	UFUNCTION()
	void HandleOfferDisplayAssetLoaded();

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortAccountItemDefinition>> AccountItemDefinitions;

	UPROPERTY(EditDefaultsOnly, Category="AthenaReloadMtxScreenBaseLegacy", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSmallOfferPreviewBase> SmallOfferPreview_Widget;

};

