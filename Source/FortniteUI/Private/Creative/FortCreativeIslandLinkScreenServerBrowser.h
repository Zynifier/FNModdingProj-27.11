// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/FortCreativeIslandLinkScreen.h"
#include "FortCreativeIslandLinkScreenServerBrowser.generated.h"

class UFortCreativeIslandLink;

UCLASS(Abstract)
class UFortCreativeIslandLinkScreenServerBrowser : public UFortCreativeIslandLinkScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="TRUE"))
	void SetLastSelectedIsland(UFortCreativeIslandLink* InLastSelectedIsland);

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortCreativeIslandLink> LastSelectedIsland;

};

