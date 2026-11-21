// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonUserWidget.h"
#include "AthenaReplayActionFeedRowBase.generated.h"

class AFortPlayerStateAthena;
class UAthenaReplayActionFeedRowProxyInstance;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UImage;
class UTexture2D;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaReplayActionFeedRowBase : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInstigatorNameUpdated(const FText& InstigatorName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnVictimNameUpdated(const FText& VictimName);

private:
	UFUNCTION()
	void OnPlayerStateAdded(AFortPlayerStateAthena* FPSA);

	UPROPERTY(EditDefaultsOnly, Category="AthenaReplayActionFeedRowBase")
	TSoftObjectPtr<UTexture2D> Texture_EliminationIcon;

	UPROPERTY(EditDefaultsOnly, Category="AthenaReplayActionFeedRowBase")
	TSoftObjectPtr<UTexture2D> Texture_DbnoIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_EventIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_EventTime;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaReplayActionFeedRowBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_InstigatorButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaReplayActionFeedRowBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_VictimButton;

	UPROPERTY()
	TObjectPtr<UAthenaReplayActionFeedRowProxyInstance> RowProxy;

};

