// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialInteractionMenu.h"
#include "FortMissedInvitesActionMenu.generated.h"

class UCommonButtonLegacy;

UCLASS(Abstract)
class UFortMissedInvitesActionMenu : public USocialActionMenu
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_NeverShowAgain;

};

