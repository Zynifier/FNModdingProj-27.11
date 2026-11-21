// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUserWidget.h"
#include "FortItemManagementEquipSlotOverlayBox.generated.h"

class UImage;

UCLASS(BlueprintType, Blueprintable)
class FORTNITEUI_API UFortItemManagementEquipSlotOverlayBox : public UFortUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortItemManagementEquipSlotOverlayBox", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Box_Fill;

};

