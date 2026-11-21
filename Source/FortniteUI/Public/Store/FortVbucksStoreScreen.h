// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MtxStore/FortMtxStoreRootBase.h"
#include "FortVbucksStoreScreen.generated.h"

class UCommonRichTextBlock;
class UDynamicEntryBox;
class UFortRealMoneyOffer;
class UFortStoreBanner;
class UFortStoreFrontOfferInfo;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UFortVbucksStoreScreen : public UFortMtxStoreRootBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	float CalculateBonusPercent(const UFortStoreFrontOfferInfo* OfferData) const;

	UFUNCTION(BlueprintPure)
	bool CanCalculateBonusPercent() const;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortVbucksStoreScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true", EntryClass="FortRealMoneyOffer"))
	TObjectPtr<UDynamicEntryBox> EntryBox_VBuckOffers;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_OfferMessage;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVbucksStoreScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortStoreBanner> StoreBanner;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortRealMoneyOffer> LastSelectedOffer;

};

