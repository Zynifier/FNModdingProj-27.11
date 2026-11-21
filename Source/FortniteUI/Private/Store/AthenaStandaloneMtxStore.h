// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UIManager/FortHUDShutdownTimerInterface.h"
#include "AthenaStandaloneMtxStore.generated.h"

class UCommonButtonBase;
class UFortMtxStoreRootBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaStandaloneMtxStore : public UCommonActivatableWidget, public IFortHUDShutdownTimerInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMtxStoreRootBase> Panel_MTXStore;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

};

