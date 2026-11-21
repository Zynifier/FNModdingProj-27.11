// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Math/MathFwd.h"
#include "Athena/ItemShop/AthenaItemShopSectionInterface.h"
#include "AthenaItemShopSection.generated.h"

class UAthenaScrollBox;
class UCommonButtonBase;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortEventDateTimeTextBlock;
class UFortStoreFrontOfferInfo;
class UHorizontalBox;
class UScaleBox;

USTRUCT(BlueprintType)
struct FAthenaItemShopSectionData
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaItemShopSection : public UCommonActivatableWidget, public IAthenaItemShopSectionInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectedStateUpdated(bool bIsInSelectedState);

private:
	UFUNCTION()
	void HandleUserScrolled(float InCurrentScrollOffset);

	UPROPERTY(EditAnywhere, Category="AthenaItemShopSection")
	float OriginalScale;

	UPROPERTY(EditAnywhere, Category="AthenaItemShopSection")
	float LargeScale;

	UPROPERTY(Transient)
	TMap<FString, int32> OfferIdToIndexMap;

	UPROPERTY(Transient)
	TMap<FString, FIntPoint> Analytics_OfferIdToIndex2D;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortStoreFrontOfferInfo>> OffersToDisplay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="FortItemShopTile"))
	TObjectPtr<UDynamicEntryBox> EntryBox_OfferEntries;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaScrollBox> ScrollBox_Offers;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_Timer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventDateTimeTextBlock> Text_TimeRemaining;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> CircleArrowButton_Next;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> CircleArrowButton_Previous;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScaleBox> ScaleBox_Offers;

};

