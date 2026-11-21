// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaMapSquadEliminationsWidget.generated.h"

class UDynamicEntryBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMapSquadEliminationsWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="AthenaMapPlayerEliminationsWidget"))
	TObjectPtr<UDynamicEntryBox> EntryBox_SquadElims;

};

