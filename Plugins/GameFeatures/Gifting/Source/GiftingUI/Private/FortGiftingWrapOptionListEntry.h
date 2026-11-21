// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortGiftingWrapOptionListEntry.generated.h"

class UCommonLazyImage;
class UFortGiftBoxItemDefinition;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortGiftingWrapOptionListEntry : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortGiftBoxItemDefinition> GiftBoxDefinition;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> Image_Gift;

};

