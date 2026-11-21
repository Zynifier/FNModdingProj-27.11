// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "Online/Collections/FortCollectionsTypes.h"
#include "AthenaCollectionItemToast.generated.h"

class UButton;
class UCommonLazyImage;
class UCommonTextBlock;
enum class EFortCollectedState : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionItemToast : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Display Toast"))
	void BP_OnDisplayToast();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Toast Reset"))
	void BP_OnToastReset();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Toast Updated"))
	void BP_OnToastUpdated(EFortCollectedState CollectedState, int32 NumCollected);

	UFUNCTION(BlueprintPure, meta=(DisplayName="Is Design Time"))
	bool BPCallableIsDesignTime() const;

	UFUNCTION()
	virtual void ResetToast();

private:
	UFUNCTION()
	void HandleMobileClick();

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="1", DisplayName="Item Number"))
	int32 DesignTime_ItemNumber;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Item Name"))
	FString DesignTime_ItemName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Collected State"))
	EFortCollectedState DesignTime_CollectedState;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="1", DisplayName="Num Collected"))
	int32 DesignTime_NumCollected;
#endif

	UPROPERTY(EditAnywhere, Category="AthenaCollectionItemToast", meta=(ClampMin="0.010000"))
	float OpenCollectionScreenInputHoldTime;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionItemToast")
	TArray<FName> BoundActions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemNumber;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_ItemImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> Button_MobileClickCatcher;

};

