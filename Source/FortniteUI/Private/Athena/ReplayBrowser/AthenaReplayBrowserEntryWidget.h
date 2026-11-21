// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Athena/ReplayBrowser/AthenaReplayBrowserRowProxyInstance.h"
#include "CommonButtonLegacy.h"
#include "AthenaReplayBrowserEntryWidget.generated.h"

class UCommonTextBlock;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaReplayBrowserEntryWidget : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Replay State Set"))
	void BP_HandleReplayStateSet(bool bSaved, bool bOld, bool bCorrupt);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> DownloadIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Name;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Date;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Length;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Rank;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Eliminations;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Row Data"))
	FAthenaReplayBrowserRowData DesignTime_RowData;
#endif

};

