// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/ItemShop/ReloadMtx/AthenaMtxOfferButtonBaseLegacy.h"
#include "AthenaStarterKitOfferButtonLegacy.generated.h"

class UCommonTextBlock;

UCLASS(Abstract)
class UAthenaStarterKitOfferButtonLegacy : public UAthenaMtxOfferButtonBaseLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DisplayName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_OfferContent;

};

