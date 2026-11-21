// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "CommonButtonLegacy.h"
#include "AthenaInventoryEquipButtonBase.generated.h"

class UFortMultiSizeItemCard;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaInventoryEquipButtonBase : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryEquipButtonBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMultiSizeItemCard> ItemWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryEquipButtonBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> EmptyImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	int32 SlotIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TArray<FVector2D> ButtonSizeBySlotUsage;

};

