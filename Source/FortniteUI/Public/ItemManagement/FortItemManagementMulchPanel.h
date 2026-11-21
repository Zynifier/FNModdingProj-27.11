// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemManagementMulchPanel.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemViewRefreshed);

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class FORTNITEUI_API UFortItemManagementMulchPanel : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEUI_API IFortItemManagementMulchPanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void HideMulchConfirmationModal();

	UFUNCTION(BlueprintCallable)
	virtual void ShowMulchConfirmationModal();

protected:
	UFUNCTION(BlueprintCallable)
	virtual void NotifyPanelActivated();

	UFUNCTION(BlueprintCallable)
	virtual void NotifyPanelDeactivated();

};

