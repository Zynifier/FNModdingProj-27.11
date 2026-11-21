// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialInteractionMenu.h"
#include "FortLeavePartyMenu.generated.h"

class UCommonButtonLegacy;

UCLASS(Abstract)
class UFortLeavePartyMenu : public USocialActionMenu
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Decline;

};

