// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortBattlePassSkinCategoriesTile.generated.h"

class UDynamicEntryBox;

UCLASS(meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassSkinCategoriesTile : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> FortDynamicEntryBox_Categories;

};

