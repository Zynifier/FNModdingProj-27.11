// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "BattlePassSubPageInterface.h"
#include "FortBattlePassCustomSkinPageBase.generated.h"

class UBattlePassEnabledInputData;
class UFortDynamicEntryBox;
class UScrollBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassCustomSkinPageBase : public UCommonActivatableWidget, public IBattlePassSubPageInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Categories;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> FortDynamicEntryBox_Categories;

	UPROPERTY(Transient)
	TObjectPtr<UBattlePassEnabledInputData> EquipEnabledData;

};

