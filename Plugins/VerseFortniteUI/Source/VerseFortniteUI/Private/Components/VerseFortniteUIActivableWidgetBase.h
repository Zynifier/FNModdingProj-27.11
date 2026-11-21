// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Components/NamedSlot.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "VerseFortniteUIActivableWidgetBase.generated.h"

class UVerseFortniteUINamedSlot;

UCLASS(Abstract, meta=(DisableNativeTick))
class UVerseFortniteUIActivableWidgetBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="Widget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerseFortniteUINamedSlot> MainSlot;

private:
	UPROPERTY(EditDefaultsOnly, Category="VerseFortniteUI", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle MainMenuInputRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="VerseFortniteUI")
	TArray<FGameplayTagContainer> HudToDeactivateOnInitialization;

};

UCLASS()
class UVerseFortniteUINamedSlot : public UNamedSlot
{
	GENERATED_BODY()

};

