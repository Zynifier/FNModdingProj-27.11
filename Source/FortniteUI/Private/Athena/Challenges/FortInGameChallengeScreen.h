// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortInGameChallengeScreen.generated.h"

class UAthenaChallengeTreeView;

UCLASS(meta=(DisableNativeTick))
class UFortInGameChallengeScreen : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeTreeView> TreeView_Challenges;

};

