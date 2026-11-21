// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CommonInputTypeEnum.h"
#include "Engine/DataTable.h"
#include "VictoryCrownsPreGameWidget.generated.h"

class AFortPlayerStateAthena;
class UCommonActionWidget;
class UDynamicEntryBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UVictoryCrownsPreGameWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnButtonClose();

	UFUNCTION(BlueprintImplementableEvent)
	void OnButtonCloseProgress(float Progress);

	UFUNCTION(BlueprintCallable)
	void OnCloseActionsComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnInputMethodChanged(ECommonInputType CurrentInput);

	UFUNCTION(BlueprintImplementableEvent)
	void StartFadeOut();

private:
	UFUNCTION()
	void FadeOutTimerFinished();

	UFUNCTION()
	void RebuildBearerList(const TArray<AFortPlayerStateAthena*>& CrownBearerList);

	UFUNCTION()
	void RegisterCloseButtonInput();

	UFUNCTION()
	void UnregisterCloseButtonInput();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="VictoryCrownsBearerInfo"))
	TObjectPtr<UDynamicEntryBox> EntryBox_BearerList;

	UPROPERTY(BlueprintReadOnly, Export, Category="VictoryCrownsPreGameWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> TipActionWidget;

	UPROPERTY(EditAnywhere, Category="VictoryCrownsPreGameWidget", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CloseObjectInputAction;

};

