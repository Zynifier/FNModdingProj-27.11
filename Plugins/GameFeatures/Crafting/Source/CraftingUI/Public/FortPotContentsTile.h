// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortPotContentsTile.generated.h"

class UCommonLazyImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortPotContentsTile : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> Image_Item;

};

