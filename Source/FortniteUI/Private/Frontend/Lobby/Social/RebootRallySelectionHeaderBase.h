// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSidebarSpecialNavWidgetBase.h"
#include "RebootRallySelectionHeaderBase.generated.h"

class URebootRallyTimerBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class URebootRallySelectionHeaderBase : public UFortSidebarSpecialNavButtonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	URebootRallyTimerBase* WBP_RebootRallyTimer;

};

