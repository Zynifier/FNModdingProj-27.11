// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/HUDLayoutToolV2/FortMobileHUDElementProxy.h"
#include "FortAutorunLockHUDElementProxy.generated.h"

class UOverlay;

UCLASS()
class UFortAutorunLockHUDElementProxy : public UFortMobileHUDElementProxy
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_AutorunLockZone;

};

