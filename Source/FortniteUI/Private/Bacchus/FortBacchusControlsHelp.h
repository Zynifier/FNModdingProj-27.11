// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortBacchusControlsHelp.generated.h"

class UCommonButtonBase;
class UFortBacchusControlsDiagram;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortBacchusControlsHelp : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortBacchusControlsHelp", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBacchusControlsDiagram> ControlsDiagram;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchClose;

	UPROPERTY(EditDefaultsOnly, Category="FortBacchusControlsHelp")
	FDataTableRowHandle CloseAction;

};

