// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCreativeMyIslandContentPanelInterface.generated.h"

enum class EFortMinigameState : uint8;

UINTERFACE()
class UFortCreativeMyIslandContentPanelInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortCreativeMyIslandContentPanelInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Should Show Panel"))
	void BP_ShouldShowPanel(bool& bOutShouldShowPanel, const EFortMinigameState MinigameState, const bool bIsInReadOnlyExperience, const bool bIsOwnerOfCurrentExperience) const;

};

