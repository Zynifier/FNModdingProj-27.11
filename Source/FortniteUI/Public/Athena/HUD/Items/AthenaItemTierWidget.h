// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/Items/AthenaItemElementWidgetBase.h"
#include "FortItemTier.h"
#include "AthenaItemTierWidget.generated.h"

class UDynamicEntryBox;
enum class EFortItemTier : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaItemTierWidget : public UAthenaItemElementWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemTierUpdated(const EFortItemTier ItemTier);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemTierWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true", EntryClass="AthenaItemTierPipWidget"))
	TObjectPtr<UDynamicEntryBox> EntryBox_TierPips;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Update Item Tier", EditCondition="!bDesignTime_SetItemToRepresent"))
	bool bDesignTime_UpdateItemTier;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Item Tier", EditCondition="bDesignTime_UpdateItemTier"))
	EFortItemTier DesignTime_ItemTier;
#endif

};

