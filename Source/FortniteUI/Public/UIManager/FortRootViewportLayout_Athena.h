// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortRootViewportLayout.h"
#include "FortRootViewportLayout_Athena.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UFortRootViewportLayout_Athena : public UFortRootViewportLayout
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortRootViewportLayout_Athena", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle LetoToggleDormancyAction;

};

