// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Creative/FortCreativeLoadedLinkData.h"
#include "FortCreativeMatchmakingDetails.generated.h"

class UCommonButtonBase;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeMatchmakingDetails : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_Cancel();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_Confirm();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_InitialSetup();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_Open();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_SetupInfo(const FCreativeLoadedLinkData& LinkData);

	UFUNCTION(BlueprintCallable)
	void Close();

	UFUNCTION(BlueprintCallable)
	void Open();

	UFUNCTION(BlueprintCallable)
	void SetupInfo(const FCreativeLoadedLinkData& LinkData);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMatchmakingDetails", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Confirm;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMatchmakingDetails", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Cancel;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeMatchmakingDetails", meta=(EditInline="true"))
	TArray<TObjectPtr<UCommonTextBlock>> Text_Bullets;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_IslandName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_LinkCode;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Creator;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_IslandDescription;

};

