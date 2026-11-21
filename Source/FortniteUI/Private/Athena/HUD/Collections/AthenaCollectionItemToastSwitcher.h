// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "AthenaCollectionItemToastSwitcher.generated.h"

class UAthenaCollectionItemToast;
class UCommonVisibilitySwitcher;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnResetToast);

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionItemToastSwitcher : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnResetToast OnResetToast;

private:
	UPROPERTY(EditAnywhere, Category="AthenaCollectionItemToastSwitcher", meta=(ClampMin="0.010000"))
	float TimeToShowToast;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionItemToastSwitcher", meta=(ClampMin="0.000000"))
	float ActivationDelay;

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> WidgetSwitcher_Toasts;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaCollectionItemToast> ActiveCollectionItemToastWidget;

	UPROPERTY(Transient)
	bool bHasPrioritizedWidgetFocus;

};

