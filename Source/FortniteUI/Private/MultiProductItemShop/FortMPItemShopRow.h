// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortMPItemShopRow.generated.h"

class UCommonButtonBase;
class UFortDynamicEntryBox;
class UFortItemShopOfferVM;

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UFortMPItemShopRow : public UUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOfferTileFocused, FString, OfferId);

public:
	UFortMPItemShopRow(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	const UCommonButtonBase* CreateEntryTile(UFortItemShopOfferVM* OfferVM, const TSubclassOf<UCommonButtonBase> TileEntryWidgetClass);

	UPROPERTY(BlueprintAssignable)
	FOnOfferTileFocused OnOfferTileFocusedEvent;

	UPROPERTY(BlueprintReadWrite, Category="FortMPItemShopRow")
	FString FocusedOfferId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Battle Pass")
	FText BattlePassLevelUpText;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortMPItemShopRow", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	UFortDynamicEntryBox* FortDynamicEntryBox_Row;

};

